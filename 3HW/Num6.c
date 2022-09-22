#include <stdio.h>

void print_binary_rec(int a)
{
	if (a == 1)
	{
		printf("1");
		return;
	}
	else if (a == 0)
	{
		printf("0");
		return;
	}
	print_binary_rec(a / 2);
	printf("%i", a % 2);
}

int main()
{
	print_binary_rec(7);
	printf("\n");
	print_binary_rec(0);
	printf("\n");
	print_binary_rec(6);
	printf("\n");
	print_binary_rec(128);
	printf("\n");
	print_binary_rec(4823564);
}