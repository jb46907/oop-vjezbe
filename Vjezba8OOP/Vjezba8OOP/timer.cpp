#include "timer.hpp"

void timer::operator+=(const timer& timeNum)
{
	s += timeNum.s;
	m += timeNum.m;
	h += timeNum.h;
}

void timer::operator/=(size_t sizeV)
{
	s /= sizeV;
	m /= sizeV;
	h /= sizeV;
}

timer::operator double()
{
	return (h * 3600 + m * 60 + s);
}

ostream& operator<<(ostream& COUT, const timer& toPrint)
{
	COUT << toPrint.h << ":" << toPrint.m << ":" << toPrint.s;
	return COUT;
}

timer operator-(const timer& a, const timer& b)
{
	timer tmp;

	tmp.h = a.h - b.h;
	tmp.m = a.m - b.m;
	tmp.s = a.s - b.s;

	return tmp;
}

void penalty::operator()(timer& xTimer)
{
	if ((xTimer.s + pen) >= 60) {
		xTimer.m += 1;
		xTimer.s = (xTimer.s + pen) - 60;
	}
	else
		xTimer.s += pen;
}
