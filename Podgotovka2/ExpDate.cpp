#include "ExpDate.h"

ExpDate::ExpDate():Delivery() {}

ExpDate::ExpDate(char* prName, unsigned id, double kg, unsigned w, unsigned h, unsigned l, char* delName, double price,
	unsigned cnt, unsigned date): Delivery(prName, id, kg, w, h, l, delName, price, cnt), expDate(date){}

ExpDate::ExpDate(const ExpDate& other): Delivery(other), expDate(other.expDate){}
ExpDate::~ExpDate(){}
ExpDate& ExpDate::operator=(const ExpDate& other) {
	if (this != &other) {
		Delivery::operator=(other);
		expDate = other.expDate;
	}

	return *this;
}

unsigned ExpDate::getExpDate() const { return expDate; }
void ExpDate::setExpDate(unsigned d) { expDate = d; }

std::ostream& ExpDate::ins(std::ostream& out) const {
	Delivery::ins(out);
	out << "Expiry date: " << expDate << std::endl;

	return out;
}

std::istream& ExpDate::extr(std::istream& in) {
	Delivery::extr(in);
	std::cout << "Input expiry date: ";
	in >> expDate;

	return in;
}

void ExpDate:: regExp(unsigned d){
	if (expDate >= d) {
		expDate -= d;
		std::cout << "Product experation date has been changed!\n";
	}
	else {
		expDate = 0;
		std::cerr << "Product has already expired!\n";
	}
}


void ExpDate::rePrice() {
	if (expDate <= 2) {
		double newPr = getPrice() - getPrice() * 0.4;
		setPrice(newPr);
		std::cout << "Price has been reduced by 40%!\n";
	}
	else std::cout << "Price has not changed!\n";

}
