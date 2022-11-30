#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y; 	
    int a;
    int b;
} Ellips;

bool isInEllips(Ellips e, Point p) {
    return (((p.x * p.x) / (e.a * e.a) + (p.y * p.y) / (e.b * e.b)) <= 1);
}

int main() {
    Point p = { 2, 2};
    Ellips c = { 8, 2, 10, 5};
    if (isInEllips(c, p) )
    	printf("ok\n");
    else printf("no\n");
    return 0;
}


