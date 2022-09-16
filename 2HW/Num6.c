#include <stdio.h>

int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	int n_kv = n * n;
	for (int i = 0; i < 2 * n_kv; ++i)
		scanf_s("%i", &a[i]);

	for (int str = 0; str < n; ++str)
	{
		for (int col = 0; col < n; ++col)
		{
			int s = 0;
			int h = 0;
			int w = 0;
			while (w < n)
			{
				s += a[n * str + w] * a[n_kv + col + h];
				++w;
				h += n;
			}
			printf("%i ", s);
		}
		printf("\n");
	}
}