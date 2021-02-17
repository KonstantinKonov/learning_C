#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 2
#define M 1000

void tab_print(double **arr, int points)
{
	printf("---------------------\n");
    for(int i = 0; i < points; i++) {
        printf("%.2lf\t%E\n", arr[i][0], arr[i][1]);
    }
	printf("---------------------\n");
}

double **tab_cubic_poly(double a3, double a2, double a1, double a0, int points, double xmin, double xmax)
{
    double **arr = (double **) malloc(points * sizeof(double *));
    for(int i = 0; i < points; i++) {
        arr[i] = (double *) malloc(2 * sizeof(double));
    }

    double xstep = (xmax - xmin) / points;
    for(int i = 0; i < points; i++) {
        double pt = xmin + xstep * i;
        arr[i][0] = pt;
        arr[i][1] = a3 * pow(pt, 3) + a2 * pow(pt, 2.0) + a1 * pt + a0;
    }
    return arr;
}

void plot_gnuplot(double **arr, int points)
{
	FILE *gp = popen("gnuplot -persist", "w");
	if(gp != NULL)
	{
		fprintf(gp, "plot '-' with lines\n");
		for(int i = 0; i < points; i++)
			fprintf(gp, "%lf\t%lf\n", arr[i][0], arr[i][1]);
		fflush(gp);
	}
}

int main(int argc, char **argv)
{
    double **tab = tab_cubic_poly(1, -6, 11, -6, M, 0.5, 4);
    tab_print(tab, M);
	plot_gnuplot(tab, M);

    return 0;
}