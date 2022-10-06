#include <stdio.h>


int main()
{
	int x = 0;
	int y = 0;

	int n;
	scanf("%i", &n);

	char direction[6];
	char* d = &direction[0];

	int r;

	for (int i = 0; i < n; ++i)
	{
		scanf("%5s %i", &direction, &r);

		char d = direction[0];

		if (d == 'N')
			y += r;

		else if (d == 'E')
			x += r;

		else if (d == 'S')
			y -= r;

		else if (d == 'W')
			x -= r;
	}

	printf("%i %i", x, y);
}