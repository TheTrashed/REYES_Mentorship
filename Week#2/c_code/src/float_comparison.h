#ifndef __FLOAT_COMAPARISON_H__
#define __FLOAT_COMAPARISON_H__

#include <float.h>

#define   ABS(a)      ((a) < 0 ? -a : a)
#define   MAX(a, b)   ((a) > (b) ? a : b)
#define   MIN(a, b)   ((a) < (b) ? a : b)

int almost_equal (double a, double b);

double mod (double a, int b);

#endif
