#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  MIN_EM    1.8
#define  MAX_EM    3.2
#define  POINTS	   1000000

int
main (void) 
{
	double increment = (MAX_EM - MIN_EM) / ((double) POINTS);

	// Open file for writing data that is to plotted
	FILE *fp = fopen("plotting_data.data", "w");
	if (fp == NULL) {
		fprintf(stderr, "could not open file\n");
		return 1;
	}
	fprintf(fp, "# %-14s\t%-15s\n", "X", "Y");	// File heading
	
	double EM = MIN_EM;				// The E/M value to be used to calculate phase space
	double rho;					// For storing the values of phase space
	while (EM <= MAX_EM) {

		rho = (1 / (32 * M_PI)) * sqrt(1 - 4 * pow((1 / EM), 2));
		if (isnan(rho)) {
			fprintf(fp, "%.15lf\t%.15lf\n", EM, 0.0);
		} else {
			fprintf(fp, "%.15lf\t%.15lf\n", EM, rho);
		}

		EM += increment;
	}
	fclose(fp);

	// Call the plotting script for gnuplot to generate the plot
	if (system("gnuplot -p plot.gpl") == 0) {
		fprintf(stdout, "plot generated\n");
		return 0;
	} else {
		fprintf(stderr, "an error occured\n");
		return 2;
	}
}
