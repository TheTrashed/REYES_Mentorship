#include "function.h"

// The Function that is being used for generation of the figures. Currently, f(z) = z^2. Can be changed accordingly.
complex double
comp_func (double real, double imag)
{
	return cpow(real + I*imag, 2);

}

// Returns the magnitude of the complex number entered
double
cmag (complex double z)
{
	return sqrt(pow(creal(z), 2) + pow(cimag(z), 2));
}
