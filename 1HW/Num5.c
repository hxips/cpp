#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	scanf_s("%i", &n);
	printf("%i ", n);

	int max = n;
	int c = 1;

	while (n != 1)
	{
		if (n % 2 == 0)
			n = n / 2;

		else
			n = 3 * n + 1;

		if (n > max)
			max = n;

		printf("%i ", n);
		++c;
	}
	printf("\nLength = %i, Max = %i", c, max);
}