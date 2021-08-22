#include "complex_color.h"

double
mod (double a,
     int   b)
{
	int tmp = a / b;

	return a - (tmp * b);
}

HSV
colorize (double x,
	  double y,
	  double norm)
{
	HSV color;
	if (!almost_equal(x, 0) && !almost_equal(y, 0)) {
		color.hue = (180 / M_PI) * (M_PI + carg(-x - I*y));
		color.saturation = 0.5 + 0.5 * (norm - floor(norm));
		color.value = 1;
	} else {
		color.hue = 0;
		color.saturation = 0;
		color.value = 1;
	}

	return color;
}


void
hsv_to_rgb (HSV  *hsv_struct,
	    RGB  *rgb_struct)
{
	double chroma = hsv_struct->value * hsv_struct->saturation;
	double hue_prime = hsv_struct->hue / 60;

	double X = chroma * (1 - fabs(mod(hue_prime, 2) - 1));

	double r_prime;
	double g_prime;
	double b_prime;
	if (hue_prime < 1 && hue_prime >= 0) {
		r_prime = chroma;
		g_prime = X;
		b_prime = 0;
	} else if (hue_prime < 2 && hue_prime >= 1) {
		r_prime = X;
		g_prime = chroma;
		b_prime = 0;
	} else if (hue_prime < 3 && hue_prime >= 2) {
		r_prime = 0;
		g_prime = chroma;
		b_prime = X;
	} else if (hue_prime < 4 && hue_prime >= 3) {
		r_prime = 0;
		g_prime = X;
		b_prime = chroma;
	} else if (hue_prime < 5 && hue_prime >= 4) {
		r_prime = X;
		g_prime = 0;
		b_prime = chroma;
	} else if (hue_prime < 6 && hue_prime >= 5) {
		r_prime = chroma;
		g_prime = 0;
		b_prime = X;
	} else {
		r_prime = 0;
		g_prime = 0;
		b_prime = 0;
	}

	double m = hsv_struct->value - chroma;

	rgb_struct->red = round((r_prime + m) * 255);
	rgb_struct->green = round((g_prime+ m) * 255);
	rgb_struct->blue = round((b_prime + m) * 255);
}
