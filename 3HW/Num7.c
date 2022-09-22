#include <stdio.h>

int trib(int n)
{
	if (n == 0 || n == 1)
		return 0;

	else if (n == 2)
		return 1;

	int a[3] = { 0, 0, 1 };

	for (int i = 3; i <= n; ++i)
		a[i % 3] = a[0] + a[1] + a[2];

	return a[n % 3];
}

int main()
{
	printf("%i\n", trib(1));
	printf("%i\n", trib(5));
	printf("%i\n", trib(20));
	printf("%i\n", trib(35));
	printf("%i\n", trib(38));
}