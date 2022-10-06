#include <stdio.h>
#include <ctype.h>

int main()
{
	char str[100];
	scanf("%[^\n]", str);

	printf("%c", str[0]);

	int i = 1;

	while (str[i] != '\0')
	{
		if ((str[i] == ' ') && isalpha(str[i - 1]))
			printf("! ");

		else
			printf("%c", str[i]);

		++i;
	}

	printf("!");
}