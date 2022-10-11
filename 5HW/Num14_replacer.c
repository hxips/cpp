#include <stdio.h>


int main(int argc, char const *argv[])
{
	char* s_r = &argv[argc - 2][0];
	char* s_o = &argv[argc - 1][0];

	size_t k = 0;

	while (s1[k] != '\0')
		++k;

	FILE* start = fopen("three_little_pigs.txt", "r");
	FILE* end = fopen("result.txt", "w");
	char words[500][100];
	int number_of_words = 0;

	while (fscanf(start, "%s", words[number_of_words]) != -1)
	{
		++number_of_words;

		char string[100] = fscanf(start, "%99s", words[number_of_words]);
		char* str = &string[0];

		int r = 1;
		int o = 0;
		while(str[o] != 0)
		{
			if (srt[o] != s_r[o])
			{
				r = 0;
				break;
			}
			++o;
		}

		if (r)
			fprintf(end, "%s ", argv[argc - 1]);
		else
			fprintf(end, "%s ", string);

	}

	fclose(end);
	fclose(start);
}