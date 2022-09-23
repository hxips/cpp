#include <stdio.h>

void reverse_subarray(int arr[], int l, int r)
{
	for (int i = 0; i < (r - l) / 2; ++i)
	{
		int temp = arr[l + i];
		arr[l + i] = arr[r - i - 1];
		arr[r - i - 1] = temp;
	}
}

int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int left;
	int right;
	scanf_s("%i %i", &left, &right);

	reverse_subarray(array, left, right);

	for (int i = 0; i < 10; ++i)
		printf("%i ", array[i]);
}
