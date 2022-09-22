#include <stdio.h>

void reverse(int arr[], int s)
{
	for (int i = 0; i < s / 2; ++i)
	{
		int temp = arr[i];
		arr[i] = arr[s - i - 1];
		arr[s - i - 1] = temp;
	}
}

int main()
{
	int array[1000];
	int size;
	scanf_s("%i", &size);
	for (int i = 0; i < size; ++i)
		scanf_s("%i", &array[i]);

	reverse(array, size);

	for (int i = 0; i < size; ++i)
		printf("%i ", array[i]);
}