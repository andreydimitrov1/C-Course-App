// Podgotovka2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Product.h"
#include "Delivery.h"
#include "ExpDate.h"

using namespace std;

int zad3(Product* arr, int sz) {
	ofstream fout("products.bin", ios::binary | ios::out);
	if (!fout) {
		return 1;
	}
	fout.write((char*)&sz, sizeof(int));

	for (size_t i = 0; i < sz; i++)
	{
		fout.write((char*)&arr[i], sizeof(Product));
		//cout << arr[i] << endl;
	}

	fout.close();

	return 0;
}

int zad3a() {
	int count;
	ifstream fin("products.bin", ios::binary | ios::in);

	if (!fin) {
		return 1;
	}

	fin.read((char*)&count, sizeof(int));

	Product* arr = new Product[count];
	for (size_t i = 0; i < count; i++)
	{
		fin.read((char*)&arr[i], sizeof(Product));
		cout << arr[i] << endl;
	}

	fin.close();

	return 0;
}

int zad4() {

	Delivery de;
	cin >> de;
	try {
		de.sale(2).sale(3);
	}
	catch (...) {
		cerr << "Sale exception" << endl;
		//return 1;
	}
	cout << "\n" << de << endl;

	return 0;
}

int zad5() {

	Delivery* del = new Delivery[3];
	for (size_t i = 0; i < 3; i++)
	{
		cin >> del[i];
		cout << endl;
		cin.ignore();
		cin.clear();
	}

	{
		ofstream fout("Deliverables", ios::out);
		for (size_t i = 0; i < 3; i++)
		{
			fout << del[i];
		}

		fout.close();
	}

	{
		ifstream fin("Deliverables", ios::in);
		if (!fin) return 333;

		string line;

		while (getline(fin, line)) {
			cout << line << endl;
		}
	}

	return 0;
}

void zad6() {

		ExpDate de;
		cin >> de;
		try {
			de.regExp(3);
			de.sale(2);
			de.rePrice();
		}
		catch (...) {
			cerr << "Sale exception" << endl;
		}
		cout << endl << de;

}

int main()
{
	Product one;
	char temp[] = "random name";
	char temp1[] = "second random name";
	Product two(temp, 111, 25.5, 10, 11, 12);
	Product three(temp1, 222, 35.5, 13, 13, 17);
	Product four(two);

	//cout << one << endl << two << endl << three << endl << four << endl;

	one = four;

	//cout << one << endl;

	//cin >> one;

	//cout << endl << endl << one;

	Product arr[4] = { one, two, three, four };

	//zad3(arr, 4);
	//zad3a();
	//zad5();
	zad6();

	//	ofstream fout("product.txt", ios::out);
	//	if (!fout) {
	//		cerr << "Issue writing in product.txt\n";
	//		return 1;
	//	}
	//
	//	//fout << 4 << endl;
	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		fout << arr[i] << endl << endl;
	//	}
	//
	//	fout.close();
	//
	//	ifstream fin("product.txt", ios::in);
	//	if(!fin){
	//		cerr << "Issue opening fin!";
	//		return 2;
	//	}
	//
	//
	//	string line;
	//	int count = 0;
	//	while (getline(fin, line)) {
	//		if (count % 8 == 0) {
	//			cout << endl << "Product number: " << count / 8 + 1 << endl;
	//		}
	//		cout << line << endl;
	//		count++;
	//	}
	//	fin.close();
}