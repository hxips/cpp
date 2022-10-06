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

int main()
{
	int n = 13;

	char s[100] = "Green Terra";
	char* a = &s[0];

	encrypt(a, n);

	printf("%s\n", s);
}