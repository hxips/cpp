#include <stdio.h>


int main(int argc, char const *argv[])
{
	printf("%s", argv[0]);
	for (int i = 0; i < argv[1]; ++i)
		printf("%s ", argv[0]);
}