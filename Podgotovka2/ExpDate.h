#ifndef EXPDATE_H
#define EXPDATE_H
#include "Delivery.h"

class ExpDate: public Delivery
{
public:
	ExpDate();
	ExpDate(char*, unsigned, double, unsigned, unsigned, unsigned, char*, double, unsigned, unsigned);
	ExpDate(const ExpDate&);
	~ExpDate();
	ExpDate& operator=(const ExpDate&);

	unsigned getExpDate() const;
	void setExpDate(unsigned);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& extr(std::istream&);

	void regExp(unsigned);
	void rePrice();

private:

	unsigned expDate;
};

#endif // !EXPDATE_H
