#ifndef __COMPLEX_COLOR_H__
#define __COMPLEX_COLOR_H__

#include <stdint.h>
#include <math.h>
#include <complex.h>
#include "float_comparison.h"

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} RGB;

typedef struct {
	double hue;
	double saturation;
	double value;
} HSV;

double mod (double a, int b);

HSV colorize (double x, double y, double norm);

void hsv_to_rgb (HSV *hsv_struct, RGB *rgb_struct);

#endif
