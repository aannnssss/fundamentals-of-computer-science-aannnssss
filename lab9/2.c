#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) 
    return b < a ? b : a;

int max(int a, int b) 
   return a < b ? b : a;
   
int mod (int a, int b)
    return a -(a/b)*b;

typedef struct {
    int i;
    int j;
    int l;
} Point;

 typedef struct {
    int x;
    int y;
    int z;
} Line;

Point updatePoint(Point p, int k) {
    Point next;
    next.i = (mod(p.i * min(p.j, p.l) + p.j * min(p.i ,p.l) + k * k, 20));
    next.j = (mod(mod(p.i, 10 - k) * mod(p.j, 10 + k) * mod(p.l, 10 - k), 25));
    next.l = (max(mod(min(p.i + p.j, p.i + p.l), 25), mod(max(p.i + p.l, p.j + k), 20)) + 10);
    return next;
}

bool isInStripe(Line c, Point p){
	
    return ((c.x + c.y + 10 <= 0) && (c.x + c.y + 20 >= 0));
}

int main() {
    Point p = { -22, 14, -14 };
    Line c = { -10, -10, 10 };
    Line b = { -20, -20, 10 };
    for (int k = 0; k <= 50; ++k) {
        p = updatePoint(p, k);
        if (isInStripe(c, p) && isInStripe(b, p)) {
            printf("The point fell into the specified area at step %d with coordinates (%d, %d) and the motion parameter %d\n", k, p.i, p.j, p.l);
            break;
        } else if (k == 50)
            printf("In 50 moves, the dot never got to the area we needed.\nk=%d, i=%d, j=%d, l=%d\n", k, p.i, p.j, p.l);
    }
    return 0;
}

