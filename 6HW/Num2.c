#include <stdio.h>
#include <float.h>
#include <stdlib.h>


struct Games
{
	char title[100];
	float mid;
};
typedef struct Games game;



int main()
{
	int n;
	scanf("%i", &n);

	game* p = (game*)malloc(n * sizeof(game));

	for (int i = 0; i < n; ++i)
	{
		scanf("%[^:]", p[i].title);

		int k;
		scanf(":%i", &k);

		float sum = 0;

		for (int j = 0; j < k; ++j)
		{
			int y;
			scanf("%i", &y);
			sum += y;
		}

		p[i].mid = sum / k;
	}

	int* ord = (int*)malloc(n * sizeof(int));

	float sup = FLT_MAX;

	for (int i = 0; i < n; ++i)
	{
		float max = FLT_MIN;

		for (int j = 0; j < n; ++j)
		{
			if (max < p[j].mid && p[j].mid < sup)
			{
				max = p[j].mid;
				ord[i] = j;
			}
		}

		sup = p[ord[i]].mid;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%s, %0.3f", p[ord[i]].title, p[ord[i]].mid);
	}

	free(ord);
	free(p);
}