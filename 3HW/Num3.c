#include <stdio.h>

void print_even(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		if (i % 2 == 0)
			printf("%i ", i);
	}
}

int main()
{
	print_even(45, 64);
}
