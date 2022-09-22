#include <stdio.h>

void dec(int arr[], int s)
{
	for (int i = 0; i < s; ++i)
	{
		--arr[i];
	}
}

int main()
{
	int array[1000];
	int size;
	scanf_s("%i", &size);
	for (int i = 0; i < size; ++i)
		scanf_s("%i", &array[i]);

	dec(array, size);

	for (int i = 0; i < size; ++i)
		printf("%i ", array[i]);

}