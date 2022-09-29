#include <stdio.h>
#include <math.h>


const double eps = 0.0000000001;


int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
	double D = b * b - 4 * a * c;

	if (D < -1 * eps)
		return 0;

	else if ((D < eps) && (D > -1 * eps))
	{
		*px1 = (-1 * b) / (2 * a);
		return 1;
	}
	else
	{
		*px1 = (sqrt(D) - b) / (2 * a);
		*px2 = (-1 * sqrt(D) - b) / (2 * a);
		return 2;
	}

}


int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double y = 0;
	double h = 0;
	double* x1 = &y;
	double* x2 = &h;

	printf("%i\n", solve_quadratic(a, b, c, x1, x2));
//	printf("%lf %lf", *x1, *x2);

}