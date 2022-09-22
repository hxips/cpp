#include <stdio.h>

int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int k = 1;
	for (int i = 1; i <= n; ++i)
		k *= i;

	return k;
}

void factorials(int arr[], int s)
{
	for (int i = 0; i < s; ++i)
		arr[i] = fact(arr[i]);
}

int main()
{
	int array[1000];
	int size;
	scanf_s("%i", &size);
	for (int i = 0; i < size; ++i)
		scanf_s("%i", &array[i]);

	factorials(array, size);

	for (int i = 0; i < size; ++i)
		printf("%i ", array[i]);
}