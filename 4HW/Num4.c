#include <stdio.h>
#include <math.h>



size_t fact(size_t n)
{
	size_t y = n / 2;
	size_t result = 1;
	for (size_t i = 1; i <= y; ++i)
		result = result * i * (n - i + 1);

	if (n % 2 == 0)
		return result;

	else
		return result * (n / 2 + 1);
}


size_t placememts(size_t n, size_t k)
{
	size_t result = 1;

	for (size_t i = n; i > (n - k); --i)
		result *= i;

	return result;
}


long double volume_squad_sphere(int n)
{
	size_t b;
	size_t pi;
	size_t f;

	if (n % 2 == 0)
	{
		b = pow(2, n);
		pi = pow(M_PI, n / 2);
		f = fact(n / 2);
	}

	else
	{
		b = pow(2, n - 1);
		int k = (n + 1) / 2;
		f = placememts(n, k);
		pi = pow(4 * M_PI, k - 1);
	}

	long double result = (long double)b * f / pi;

	return result;
}


int main()
{
	size_t o;
	scanf("%zu", &o);

	printf("%Lf\n", volume_squad_sphere(o));
}