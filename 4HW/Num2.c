#include <stdio.h>


size_t placememts(size_t n, size_t k)
{
	size_t result = 1;

	for (size_t i = n; i > (n - k); --i)
		result *= i;

	return result;
}


int main()
{
	size_t b;
	size_t s;
	scanf("%zu %zu", &b, &s);

	printf("%zu\n", placememts(b, s));
}
