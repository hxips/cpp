#include <stdio.h>


size_t fact(size_t n)
{
	size_t y = n / 2;
	size_t result = 1;
	for (size_t i = 1; i <= y; ++i)
		result = result * i * (n - i + 1);

	if (n % 2 == 0)
		return result;

	else
		return result * (n / 2 + 1);
}


int main()
{
	size_t k;
	scanf("%zu", &k);

	printf("%zu\n", fact(k));
}
