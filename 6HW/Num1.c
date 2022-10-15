#include <stdio.h>
#include <math.h>



struct point
{
	double x, y;
};
typedef struct point Point;


struct triangle
{
	Point a, b, c;
};
typedef struct triangle Triangle;



void print_point(Point g)
{
	printf("(%0.2f, %0.2f)", g.x, g.y);
}


void print_triangle(Triangle t)
{
	printf("{");
	print_point(t.a);
	printf(", ");
	print_point(t.b);
	printf(", ");
	print_point(t.c);
	printf("}");

}


float distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


float get_triangle_perimeter(Triangle t)
{
	float perimetr = 0;

	perimetr += distance(t.a, t.b);
	perimetr += distance(t.b, t.c);
	perimetr += distance(t.c, t.a);

	return perimetr;
}


float get_triangle_area(Triangle t)
{
	float half_per = get_triangle_perimeter(t) / 2;

	float per_a = half_per - distance(t.a, t.b);
	float per_b = half_per - distance(t.b, t.c);
	float per_c = half_per - distance(t.c, t.a);

	return sqrt(half_per * per_a * per_b * per_c);
}


Triangle moved_triangle(const Triangle* t, Point v)
{
	Triangle tri;

	tri.a.x = t -> a.x + v.x;
	tri.b.x = t -> b.x + v.x;
	tri.c.x = t -> c.x + v.x;
	tri.a.y = t -> a.y + v.y;
	tri.b.y = t -> b.y + v.y;
	tri.c.y = t -> c.y + v.y;

	return tri;
}


void move_triangle(Triangle* t, Point v)
{
	t -> a.x += v.x;
	t -> b.x += v.x;
	t -> c.x += v.x;
	t -> a.y += v.y;
	t -> b.y += v.y;
	t -> c.y += v.y;
}



int main()
{
	Point A = {5.768, 4.89};
	Point B = {1.3166, 0.0641};
	Point C = {5.51161, -9.2163};
	Point V = {14.61, 2.35};

	Triangle T = {A, B, C};

	Triangle* p = &T;

//	1_1
	printf("1_1\n");
	print_point(A);
	printf("\n");

//	1_2
	printf("1_2\n");
	print_triangle(T);
	printf("\n");

//	1_3
	printf("1_3\n%0.4f\n", distance(A, B));

//	1_4
	printf("1_4\n%0.5f\n", get_triangle_perimeter(T));

//	1_5
	printf("1_5\n%0.5f\n", get_triangle_area(T));

//	1_6
	printf("1_6\n");
	print_triangle(moved_triangle(p, V));
	printf("\n");

//	1_7
	printf("1_7\n");
	move_triangle(p, V);
	print_triangle(T);
}