#include <stdio.h>
#include <math.h>


const float eps = 0.00001;


void intersection_of_circles(int x1, int y1, float r1, int x2, int y2, float r2)
{
	float ro = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));


	if (r1 + r2 < ro)
		printf("Do not intersect\n");

	else if ((fabs(r1 + r2 - ro) < eps) || (fabs(fabs(r1 - r2) - ro) < eps))
		printf("Touch\n");

	else
		printf("Intersect\n");

	return;
}


int main()
{
	intersection_of_circles(0, 0, 1, 0, 2, 1);
	intersection_of_circles(0, 0, 1, 1, 1, 1);
	intersection_of_circles(0, 0, 3, 5, 5, 4);
	intersection_of_circles(0, 0, 4, 5, 5, 4);
	intersection_of_circles(-2, 1, 4, 2, 4, 1);
}