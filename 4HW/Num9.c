#include <stdio.h>
#include <math.h>


const double eps = 0.0000000001;


double f(double x)
{
	return pow(x, 5) + 2 * pow(x, 4) + 5 * x * x + 4 * x - 500;
}


double binsearh_float(double left, double right)
{
	double mid;

	while (1)
	{
		mid = (left + right) / 2;

		if (fabs(f(mid)) < eps)
			return mid;

		else if (f(mid) > eps)
			right = mid;

		else
			left = mid;
	}
}


int main()
{
	double l;
	double r;
	scanf("%lf %lf", &l, &r);

	printf("%lf\n", binsearh_float(l, r));
}