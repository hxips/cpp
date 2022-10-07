#include <stdio.h>


void safe_strcpy(char* result, size_t n, char* original)
{
	int i = 0;

	while (i != n - 1 && original[i] != '\0')
	{
		result[i] = original[i];
		++i;
	}

	result[i] = '\0';
	return;
}


int main()
{
	char st1[12];
	char* s1 = &st1[0];

	char st2[50];
	char* s2 = &st2[0];

	size_t k = 12;

	scanf("%s %s", st1, st2);

	safe_strcpy(s1, k, s2);

	printf("%s", st1);
}