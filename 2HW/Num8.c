#include <stdio.h>

int main()
{
	int a[100];
	int b[100];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n * n; ++i)
		scanf_s("%i", &a[i]);
	scanf_s("%i", &n);
	for (int i = 0; i < n * n; ++i)
		scanf_s("%i", &b[i]);

	for (int str = 0; str < n; ++str)
	{
		for (int col = 0; col < n; ++col)
		{
			int w = 0;
			int h = 0;
			int s = 0;
			while (w < n)
			{
				s += a[n * str + w] * b[col + h];
				++w;
				h += n;
			}
			printf("%i ", s);
		}
		printf("\n");
	}
}