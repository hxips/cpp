#include <stdio.h>

void sort(int arr[], int s)
{
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s - i - 2; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int array[4] = {6, 2, 8, 1};
	int size = 4;

	sort(array, size);

	for (int i = 0; i < size; ++i)
		printf("%i ", array[i]);
}