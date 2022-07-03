#include "Delivery.h"
#include <iostream>

Delivery::Delivery() : Product(), name(nullptr), price(0.), cnt(0) {}

Delivery::Delivery(char* prName, unsigned id, double kg, unsigned w, unsigned h, unsigned l, char* name, double price, unsigned cnt) :
	Product(prName, id, kg, w, h, l), name(new char[strlen(name) + 1]), price(price), cnt(cnt) {
	strcpy_s(this->name, strlen(name) + 1, name);
}

Delivery::~Delivery() {
	if (name != nullptr) {
		delete[] name;
	}
}

Delivery::Delivery(const Delivery& other) : Product(other), name(new char[strlen(other.name) + 1]), price(other.price), cnt(other.cnt) {
	strcpy_s(name, strlen(other.name) + 1, other.name);
}

Delivery& Delivery::operator=(const Delivery& other) {
	if (this != &other) {
		Product::operator=(other);

		if (name != nullptr) {
			delete[] name;
		}

		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		price = other.price;
		cnt = other.cnt;
	}

	return *this;
}

char* Delivery::getName() { return name; }
double Delivery::getPrice() { return price; }
unsigned Delivery::getCnt() { return cnt; }
void Delivery::setName(char* newName) {
	if (name != nullptr) {
		delete[] name;
	}

	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, name);
}

void Delivery::setPrice(double d) { price = d; }
void Delivery::setCnt(unsigned u) { cnt = u; }

std::ostream& Delivery::ins(std::ostream& out) const {
	Product::ins(out);
	out << "Delivery guy's name: " << name << std::endl;
	out << "Price: " << price << std::endl;
	out << "Count: " << cnt << std::endl;

	return out;
}

std::istream& Delivery::extr(std::istream& in) {
	Product::extr(in);
	std::cout << "Input delivery name: ";
	in.clear();
	in.ignore();
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[50];
	in.getline(name, 49);
	std::cout << "Input price: ";
	in >> price;
	std::cout << "Input count: ";
	in >> cnt;

	return in;
}

Delivery& Delivery::sale(int count) {
	if (cnt >= count)
		cnt -= count;
	else
		throw "Not enought products!";
	return *this;
}

