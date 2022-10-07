#include <stdio.h>


void is_palindrom(const char* str, int n)
{
	for (int i = 0; i < n / 2; ++i)
	{
		if (str[i] != str[n - i - 1])
		{
			printf("No");
			return;
		}
	}

	printf("Yes");
	return;
}


int main()
{
	char string[100];
	scanf("%s", string);
	char* s = &string[0];

	int i = 0;
	while(s[i] != 0)
		++i;

	is_palindrom(s, i);
}