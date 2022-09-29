#include <stdio.h>


float pi(int n)
{
	float sum = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
			sum -= 1.0/(2 * i - 1);

		else
			sum += 1.0/(2 * i - 1);			
	}

	return 4 * sum;
}


int main()
{
	int p;
	scanf("%i", &p);

	printf("%f\n", pi(p));
}