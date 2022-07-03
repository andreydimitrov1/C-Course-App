#ifndef DELIVERY_H
#define DELIVERY_H
#include "Product.h"
#include <iostream>

class Delivery: public Product
{
public:
	Delivery();
	Delivery(char*, unsigned, double, unsigned, unsigned, unsigned, char*, double, unsigned);
	virtual ~Delivery();
	Delivery(const Delivery&);
	Delivery& operator=(const Delivery&);

	char* getName();
	double getPrice();
	unsigned getCnt();
	void setName(char*);
	void setPrice(double);
	void setCnt(unsigned);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& extr(std::istream&);

	Delivery& sale(int);

private:
	char* name;
	double price;
	unsigned cnt;
};

#endif