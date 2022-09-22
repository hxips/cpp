#include <stdio.h>

int is_even(int a)
{
	if (a % 2)
		return 0;
	else
		return 1;
}

int main()
{
	printf("%i\n", is_even(90));
	printf("%i\n", is_even(91));
}
