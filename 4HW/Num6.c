#include <stdio.h>
#include <math.h>


const double step = 0.02;
const double eps = 0.0000000001;


double gamma(double x)
{
	double result = 0;
	double s;
	double right = step;
	double left = 0;

	while (1)
	{
		s = (right - left) * (pow(left, x - 1) * exp(-1 * left) + pow(right, x - 1) * exp(-1 * right)) / 2;
		result += s;

		if (s > eps)
		{
			left = right;
			right += step;
		}

		else
			return result;
	}
}


int main()
{
	double j;
	scanf("%lf", &j);

	printf("%lf\n", gamma(j));
}