#include <stdio.h>
#include <ctype.h>


void encrypt(char* str, const int k)
{
	char U = 64;
	char l = 96;

	while (*str != '\0')
	{
		if (isalpha(*str))
		{
			if (isupper(*str))
			{
				char z = (*str - U + k) % 26;
				if (z == 0)
					*str = 'Z';
				else
					*str = U + z;
			}

			else
			{
				char z = (*str - l + k) % 26;
				if (z == 0)
					*str = 'z';
				else
					*str = l + z;
			}
		}

		str++;
	}
}


int main(int argc, char const *argv[])
{
	const int n = argv[argc - 1];

	FILE* start = fopen("three_little_pigs.txt", "r");
	FILE* end = fopen("result.txt", "w");
	char words[500][100];
	int number_of_words = 0;

	while (fscanf(start, "%s", words[number_of_words]) != -1)
	{
		++number_of_words;

		char string[100] = fscanf(start, "%99s", words[number_of_words]);
		char* str = &string[0];

		encrypt(str, n);
		fprintf(end, "%s\n", string);
	}

	fclose(end);
	fclose(start);
}