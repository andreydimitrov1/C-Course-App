#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
private:
	char* name;
	unsigned id; // 1000 00 00 00 00 00 00 00 00
	double kg;
	unsigned h, w, l; 

public:
	Product();
	Product(char*, unsigned, double, unsigned, unsigned, unsigned);
	Product(const Product&);
	virtual ~Product();
	Product& operator=(const Product&);

	char* getName() const;
	unsigned getId() const;
	double getKg() const;
	unsigned getH() const;
	unsigned getW() const;
	unsigned getL() const;

	void setName(char*);
	void setId(unsigned);
	void setKg(double);
	void setH(unsigned);
	void setW(unsigned);
	void setL(unsigned);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& extr(std::istream&);
};

std::ostream& operator<<(std::ostream&, const Product&);
std::istream& operator>>(std::istream&, Product&);

#endif