#include <stdio.h>
#include <ctype.h>


int main()
{
	char a;
	scanf("%c", &a);

	if (!(isalpha(a)))
		printf("Not a letter");

	else
	{
		char i;

		if (isupper(a))
			i = 64;

		else
			i = 96;

		printf("%hhi", a - i);
	}
}