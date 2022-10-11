#include <stdio.h>
#include <string.h>


void reverse(char* w)
{
	int size = 0;
	while (w[size] != '\0')
		++size;

	for (int i = 0; i < size / 2; ++i)
	{
		char temp = w[i];
		w[i] = w[size - i - 1];
		w[size - i - 1] = temp;
	}

	return;
}


int main()
{
	FILE* start = fopen("input.txt", "r");
	FILE* end = fopen("output.txt", "w");

	char words[500][100];

	int k = 0;
	while(fscanf(f, "%s", words[k]) != -1)
	{
		++k;

		char word[100] = fscanf(f, "%99s", words[k]);
		char* p = &word[0];
		reverse(p);
		
		fprintf(end, "%s ", word);
	}

	fclose(end);
	fclose(start);
}