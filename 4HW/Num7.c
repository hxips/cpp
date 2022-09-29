#include <stdio.h>
#include <math.h>


const double pi = 3.14159265359;


double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


double length(double x, double y)
{
	return distance(x, y, 0, 0);
}


double scalar_product(double x1, double y1, double x2, double y2)
{
	return x1 * x2 + y1 * y2;
}



double to_degrees(double rad)
{
	return rad * 180 / pi;
}


double angle(double x1, double y1, double x2, double y2)
{
	double scalar = scalar_product(x1, x2, y1, y2);
	double mod_x = length(x1, x2);
	double mod_y = length(y1, y2);

	double cos = scalar / (mod_x * mod_y);

	double alf = acos(cos);

	alf = to_degrees(alf);

	return alf;
}


int main()
{
	double q, w;
	double e, r;
	scanf("%lf %lf", &q, &w);
	scanf("%lf %lf", &e, &r);

	printf("%g\n", angle(q, w, e, r));
}