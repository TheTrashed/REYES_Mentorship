#include "float_comparison.h"

// Uses relative epsilon comparison to compare the floats
int
almost_equal (double a, double b)
{
	double diff = ABS(a - b);
	a = ABS(a);
	b = ABS(b);

	double largest = MAX(a, b);

	if (diff <= largest * FLT_EPSILON)
		return 1;
	else
		return 0;
}

double 
mod (double a, int b)
{
	int tmp = a / b;

	return a - (tmp * b);
}
