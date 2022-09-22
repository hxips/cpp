#include <stdio.h>

void last_digits(int arr[], int s)
{
	for (int i = 0; i < s; ++i)
		arr[i] %= 10;
}

int main()
{
	int array[1000];
	int size;
	scanf_s("%i", &size);
	for (int i = 0; i < size; ++i)
		scanf_s("%i", &array[i]);

	last_digits(array, size);

	for (int i = 0; i < size; ++i)
		printf("%i ", array[i]);
}