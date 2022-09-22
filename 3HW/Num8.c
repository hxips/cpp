#include <stdio.h>

int count_even(int arr[], int s)
{
	int k = 0;

	for (int j = 0; j < s; ++j)
	{
		if (arr[j] % 2 == 0)
			k += 1;
	}
	return k;
}

int main()
{
	int array[4] = {10, 20, 30, 40};
	int size = 4;
	printf("%i\n", count_even(array, size));
}