#include <stdio.h>


void delete_chars(char* str, char c)
{
	int i = 0;
	int shift = 0;

	while (str[i + shift] != '\0')
	{
		while (str[i + shift] == c)
			++shift;

		str[i] = str[i + shift];
		++i;
	}

	str[i] = '\0';
}


int main()
{
	char string[100];
	char a;
	scanf("%s %c", string, &a);

	char* s = &string[0];

	delete_chars(s, a);
	printf("%s\n", string);
}