#include <stdio.h>
#include <stdlib.h>
#include "complex_color.h"

#define   MIN_X  -3.0
#define   MAX_X   3.0

#define   MIN_Y  -3.0
#define   MAX_Y   3.0

#define   POINTS   1000

int
main (void)
{
	double x = MIN_X;
	double y;
	complex double f_z;
	double norm;
	HSV hsv_color;
	RGB rgb_color;


	FILE *fp = fopen("complex_data.dat", "w");
	if (fp == NULL) {
		fprintf(stderr, "could not open file\n");
		return 1;
	}

	double x_increment = (MAX_X - MIN_X) / ((double) POINTS);
	double y_increment = (MAX_Y - MIN_Y) / ((double) POINTS);
	while (x <= (double) MAX_X) {
		y = MIN_Y;
		while (y <= (double) MAX_Y) {
			f_z = cpow(x + I*y, 2);
			norm = sqrt(pow(creal(f_z), 2) + pow(cimag(f_z), 2));

			hsv_color = colorize(creal(f_z), cimag(f_z), norm);
			hsv_to_rgb(&hsv_color, &rgb_color);
			fprintf(fp, "%.15f\t%.15f\t%d\t%d\t%d\n", x, y, \
					rgb_color.red, rgb_color.green, rgb_color.blue);
			y += y_increment;
		}
		fprintf(fp, "\n");
		x += x_increment;
	}
	fclose(fp);

	if (!system("gnuplot -p fig2_plot.gpl")) {
		fprintf(stdout, "plot generated\n");
		return 0;
	} else {
		fprintf(stderr, "an error occurred\n");
		return 2;
	}
}
