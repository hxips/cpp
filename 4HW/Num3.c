#include <stdio.h>


float yearfrac(int year, int day)
{
	if (year % 4 == 0)
		return (float)day / 366;

	else
		return day / 365.0;
}


int main()
{
	int y;
	int d;
	scanf("%i %i", &y, &d);

	printf("%0.5f\n", yearfrac(y, d));
}