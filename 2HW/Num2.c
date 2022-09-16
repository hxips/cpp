#include <stdio.h>
int main()
{
	int n;
	int a[1000];
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);
	int x;
	scanf_s("%i", &x);
	int l = -1, r = n;
	while (r > l + 1)
	{
		int mid = (l + r) / 2;
		if (a[mid] >= x)
			r = mid;
		else
			l = mid;
	}
	if (r == n)
		printf("%i", n);
	else
		printf("%i", l + 1);
}