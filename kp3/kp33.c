#include <math.h>
#include <stdio.h>

#define MAX_ITER 100

typedef long double ld;
typedef unsigned uint;

ld computer_epsilon() {
    ld eps = 1;
    while (1 + eps / 2 != 1)
        eps *= 0.5;
    return eps;
}

ld func(ld x) {
    return cosh(x);
}

ld taylor(ld x) {
    ld eps = computer_epsilon();
    int n = 0; 
    ld cur_member = 1;
    ld result = 0;
    ld temp = 1;
    while ((fabsl(cur_member) > sqrt(eps) && n < MAX_ITER)) {
        cur_member = temp/(2*n+1);
        temp *= x*x;
        result += cur_member;
        n++;
    }
    return result;
}

void tabulation(const ld a, const ld b, const uint steps) {
    const ld step = (b - a) / steps;
    for (ld x = a; x < b + step; x += step) {
        printf("|%.3Lf|%.19Lf|%.19Lf|\n", x, func(x), taylor(x));
    }
}

int main() {
    ld eps=computer_epsilon();
    printf("%.50Lf\n",eps);
    printf("__________________________________________________\n");
    printf("|  x  |   Inner function    |     Sum of row      |\n");
    printf("|_____|_____________________|_____________________|\n");
    tabulation(0.1, 0.6, 15);
    printf("|_____|_____________________|_____________________|\n");
}
