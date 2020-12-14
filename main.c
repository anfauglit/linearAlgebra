#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
	int a;
	int b;
} Point;

int compPoints(Point* p1, Point* p2) {
	if (p1->a == p2->a && p1->b == p2->b) 
		return 1;
	return 0;
}

typedef struct vector {
	Point* a;
	Point* b;
} Vector;

Point* sumOfPoints (Point* p1, Point* p2) {
	Point* p;
	p = malloc(sizeof(Point));

	p->a = p1->a + p2->a;
	p->b = p1->b + p2->b;

	return p;
}

Point* multByNumber (Point* p1, int n) {
	Point* p;
	p = malloc(sizeof(Point));

	p->a = p1->a * n;
	p->b = p1->b * n;

	return p;
}

Vector* init_vectorAtOrigin(Point* p) {
	Vector* v;
	v = malloc(sizeof(Vector));

	Point* origin;
	origin = malloc(sizeof(Point));

	origin->a = 0;
	origin->b = 0;

	v->a = origin;
	v->b = p;

	return v;
}

Vector* init_vector(Point* p1, Point* p2) {
	Vector* v;
	v = malloc(sizeof(Vector));

	v->a = p1;
	v->b = p2;

	return v;
}

void printVector(Vector* v) {
	printf("(%i, %i) (%i, %i)", v->a->a, v->a->b, v->b->a, v->b->b);
}


int isVectorEqual (Vector* v1, Vector* v2) {
	printVector(v1);	
	printVector(v2);	
	return compPoints(sumOfPoints(v1->b, multByNumber(v1->a, -1)), sumOfPoints(v2->b, multByNumber(v2->a, -1)));
}

int main (void)
{
	Vector *v1, *v2;

	Point *p1, *p2, *p;

	p1 = malloc(sizeof(Point));
	p2 = malloc(sizeof(Point));
	p = malloc(sizeof(Point));

	p1->a = 3;
	p1->b = 1;

	p2->a = 1;
	p2->b = 2;

	p = sumOfPoints(p1, p2);

	v1 = init_vectorAtOrigin(p1);
	v2 = init_vectorAtOrigin(p2);

	Vector *v3, *v4;

	v3 = init_vectorAtOrigin(sumOfPoints(p2, multByNumber(p1, -1)));
	v4 = init_vector(p1, p2);
	
	printVector(v1);
	printVector(v2);
	printVector(v3);
	printVector(v4);

	if (isVectorEqual(v3, v4))
		printf("Vectors v3 and v4 are equal\n");

	printf("The sum of two points is <%i, %i>\n", p->a, p->b);

	
	return 0;
}

