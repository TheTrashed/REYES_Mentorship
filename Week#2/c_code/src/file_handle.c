#include "file_handle.h"

int
write_file_dom_col (FILE *fp, double x, double y, int r, int g, int b)
{
	if (fprintf(fp, "%.15f\t%.15f\t%d\t%d\t%d\n", x, y, r, g, b) < 0) {
		return 1;
	}

	return 0;
}

int
write_file_3d (FILE *fp, double x, double y, double f_x, double f_y)
{
	if (fprintf(fp, "%.15f\t%.15f\t%.15f\t%.15f\n", x, y, f_x, f_y) < 0) {
		return 1;
	}

	return 0;
}
