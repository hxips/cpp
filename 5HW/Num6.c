#include <stdio.h>

int main()
{
	char str[100];
	scanf("%99s", str);

	int k = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ')')
			--k;

		else
			++k;

		if (k < 0)
			str[i + 1] = '\0';

		++i;
	}

	if (k == 0)
		printf("Yes");
	else
		printf("No");
}