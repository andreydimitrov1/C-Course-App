#include <iostream>
#include "Product.h"

Product::Product() {
	name = nullptr;
	id = 0;
	kg = 0.;
	w = 0;
	h = 0;
	l = 0;
}

Product::Product(char* name, unsigned id, double kg, unsigned w, unsigned h, unsigned l) : name(new char[strlen(name) + 1]), id(id),
kg(kg), w(w), h(h), l(l) {

	strcpy_s(this->name, strlen(name) + 1, name);
}

Product::Product(const Product& other) : name(new char[strlen(other.name) + 1]), id(other.id), kg(other.kg), w(other.w),
h(other.h), l(other.l) {
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
}

Product::~Product() {
	if (name != nullptr) {
		delete[] name;
	}
}

Product& Product::operator=(const Product& other) {
	if (this != &other) {
		if (name != nullptr) {
			delete[] name;
		}

		name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);

		this->id = other.id;
		this->kg = other.kg;
		this->w = other.w;
		this->h = other.h;
		this->l = other.l;
	}

	return *this;
}

char* Product::getName() const {
	return name;
}

unsigned Product::getId() const {
	return id;
}

double Product::getKg() const {
	return kg;
}

unsigned Product::getH() const {
	return h;
}

unsigned Product::getW() const {
	return w;
}

unsigned Product::getL() const {
	return l;
}

void Product::setName(char* newName) {
	if (name != nullptr) {
		delete[] name;
	}

	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Product::setId(unsigned id) {
	this->id = id;
}

void Product::setKg(double kg) {
	this->kg = kg;
}

void Product::setH(unsigned h) {
	this->h = h;
}

void Product::setW(unsigned w) {
	this->w = w;
}

void Product::setL(unsigned l) {
	this->l = l;
}

std::ostream& Product::ins(std::ostream& out) const {
	if (name != nullptr) {
		out << "Name: " << name << std::endl;
	}
	else out << "No name set\n";
	out << "Kg: " << kg << std::endl;
	out << "Id: " << id << std::endl;
	out << "H: " << h << std::endl;
	out << "W: " << w << std::endl;
	out << "L: " << l << std::endl;

	return out;
}

std::istream& Product::extr(std::istream& in) {
	std::cout << "Input name: ";
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[50];
	in.getline(name, 49);
	std::cout << "Input id: ";
	in >> id;
	std::cout << "Input kg: ";
	in >> kg;
	std::cout << "Input h: ";
	in >> h;
	std::cout << "Input w: ";
	in >> w;
	std::cout << "Input l: ";
	in >> l;

	return in;
};

std::ostream& operator<<(std::ostream& lhs, const Product& rhs) {
	return rhs.ins(lhs);
}

std::istream& operator>>(std::istream& lhs, Product& rhs) {
	return rhs.extr(lhs);
}