#include <stdio.h>


int longest_word(const char* str, char* result)
{
	int l = 0;

	char i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			int j = 0;

			while (str[i + j] != '\0' && str[i + j] != ' ')
				++j;

			if (j > l)
			{
				l = j;
				for (int y = 0; y < l; ++y)
					result[y] = str[i + y];
			}

			i += j - 1;
		}

		++i;
	}

	return l;
}

int main()
{
	char s[100] = "cat dog elephant mouse";
	char* a = &s[0];

	char res[100];
	char* r = &res[0];

	int size = longest_word(a, r);

	for (int i = 0; i < size; ++i)
		printf("%c", r[i]);
}