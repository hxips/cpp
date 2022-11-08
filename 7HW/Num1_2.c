#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	char* p = (char*)malloc(9 * sizeof(char));

	strcpy(p, "Elephant");

    printf("%s\n", p);

    free(p);
}
