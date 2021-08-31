#ifndef __FILE_HANDLE_H__
#define __FILE_HANDLE_H__

#include <stdio.h>
#include <stdlib.h>

int write_file_dom_col (FILE *fp, double x, double y, int r, int g, int b);

int write_file_3d (FILE *fp, double x, double y, double f_x, double f_y);

#endif
