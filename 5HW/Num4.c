#include <stdio.h>

int main()
{
	char str1[100];
	char str2[100];

	scanf("%s %s", str1, str2);

	int i = 0;
	int t = 1;

	while (t)
	{
		if (str1[i] == '\0')
		{
			while (str2[i] != '\0')
			{
				printf("%c", str2[i]);
				++i;
			}

			t = 0;
		}

		else if (str2[i] == '\0')
		{
			while (str1[i] != '\0')
			{
				printf("%c", str1[i]);
				++i;
			}
			
			t = 0;
		}

		else
		{
			printf("%c%c", str1[i], str2[i]);
			++i;
		}
	}
}