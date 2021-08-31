// Should be moved to the src dir before compilation so that the header files can be linked using the MakeFile
#include "file_handle.h"
#include "function.h"
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
			f_z = comp_func(x, y);
			norm = cmag(f_z);

			hsv_color = colorize(creal(f_z), cimag(f_z), norm);
			hsv_to_rgb(&hsv_color, &rgb_color);
			write_file_dom_col(fp, x, y, \
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
