#include <stdio.h>

int main()
{
	char str[100];
	scanf("%99s", str);

	int i = 0;

	while(str[i] != '\0')
	{
		for (int j = 0; j <= i; ++j)
			printf("%c", str[j]);

		++i;
		printf("\n");
	}
}