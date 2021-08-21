#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define   X_MIN    -3.0
#define   X_MAX     3.0

#define   Y_MIN    -1
#define   Y_MAX     1

#define   POINTS    1000

int
main (void)
{
	double x_increment = (X_MAX - X_MIN) / ((double) POINTS);

	double x;
	int y = Y_MIN;
	double complex f_z;

	char *file_name = malloc(sizeof(char) * 21);
	while (y <= Y_MAX) {
		sprintf(file_name, "analytic_sep_y%02i.dat", y);
		FILE *fp = fopen(file_name, "w");
		if (fp == NULL) {
			fprintf(stderr, "could not open file\n");
			return 1;
		}
		fprintf(fp, "#%16s\t%16s\t%16s\n", "x", "Re f(z)", "Im f(z)");		// File heading

		x = X_MIN;
		while (x <= X_MAX) {
			f_z = cpow(x + I*y, 2);
			fprintf(fp, "%.15f\t%.15f\t%.15f\n", x, creal(f_z), cimag(f_z));
			x += x_increment;
		}
		fprintf(fp, "\n");
		fclose(fp);
		y++;
	}
	free(file_name);

	if (!system("gnuplot -p fig1_plot.gpl")) {
		fprintf(stdout, "plot generated\n");
		system("rm -f analytic_sep_y*");		// Clean the directory of dat files
		return 0;
	} else {
		fprintf(stderr, "an error occurred\n");
		system("rm -f analytic_sep_y*");
		return 2;
	}
}
