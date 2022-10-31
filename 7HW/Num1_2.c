#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	char* p = (char*)malloc(9 * sizeof(char));

	strcpy(p, "Elephant");

	for (size_t i = 0; i < 8; ++i)
        printf("%c", p[i]);
    printf("\n");

    free(p);
}