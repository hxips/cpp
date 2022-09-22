#include <stdio.h>

void alice(int);
void bob(int);

void alice(int n)
{
	n = n * 3 + 1;
	printf("Alice: %3i\n", n);
	bob(n);
}

void bob(int n)
{
	while (n % 2 == 0)
	{
		n /= 2;
		printf("Bob: %5i\n", n);
	}

	if (n == 1)
	{
		printf("Bob: %5i", n);
		return;
	}
	alice(n);
}

int main()
{
	int i;
	scanf_s("%i", &i);
	alice(i);
}