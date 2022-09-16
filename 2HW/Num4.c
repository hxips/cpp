#include <stdio.h>
int main()
{
	int a[1000];
	int n, m;
	scanf_s("%i %i", &n, &m);
	for (int i = 0; i < n * m; ++i)
		scanf_s("%i", &a[i]);

	for (int k = 0; k < m; ++k)
	{
		int sum = 0;

		for (int t = 0; t < n * m; t += m)
			sum += a[k + t];
		
		printf("%i ", sum);
	}
}