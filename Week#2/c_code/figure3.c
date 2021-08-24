#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define	MIN_X	-2.0
#define	MAX_X	2.0

#define	MIN_Y	-2.0
#define	MAX_Y	2.0

#define	POINTS	100

int
main (void)
{
	double x = MIN_X;
	double y;
	complex double f_z;

	FILE *fp = fopen("plotting_data.dat", "w");
	if (fp == NULL) {
		fprintf(stderr, "could not open file\n");
		return 1;
	}

	double x_increment = (MAX_X - MIN_X) / (double) POINTS;
	double y_increment = (MAX_Y - MIN_Y) / (double) POINTS;
	while (x <= (double) MAX_X + x_increment) {
		y = MIN_Y;
		while (y <= (double) MAX_Y + y_increment) {
			f_z = cpow(x + I*y, 2);				// The function f(z) = z^2
			fprintf(fp, "%.15f\t%.15f\t%.15f\t%.15f\n", x, y, creal(f_z), cimag(f_z));

			y += y_increment;
		}
		fprintf(fp, "\n");
		x += x_increment;
	}
	fclose(fp);

	return 0;
}
