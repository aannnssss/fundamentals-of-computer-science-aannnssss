#include <math.h>
#include <stdio.h>

#define MAX_ITER 100

typedef long double ld;
typedef unsigned uint;

ld computer_epsilon() {
    ld eps = 1.0;
    while (1.0 + eps / 2.0 != 1.0)
        eps *= 0.5;
    return eps;
}

ld func(ld x) {
    return cosh(x);
}

ld taylor(ld x) {
    ld eps = computer_epsilon();
    int n = 0.0; 
    ld cur_member = 1.0, ch = 1.0, fac = 1.0, result = 0.0;
    while ((fabsl(cur_member) > sqrt(eps) && n <= MAX_ITER)) {
        cur_member *= ch / fac;
        ch *= x*x;
        fac *= 2*(n + 1);
        result += cur_member;
        n++;
    }
    return result;
}

void tabulation(const ld a, const ld b, const uint steps) {
    const ld step = b/steps - a/steps;
    for (ld x = a; x <= b; x += step) 
        printf("|%.3Lf|%.19Lf|%.19Lf|\n", x, func(x), taylor(x));
}

int main() {
    ld eps = computer_epsilon();
    printf("Machine epsilon: %.45Lf\n", eps);
    printf("__________________________________________________\n");
    printf("|  x  |    function         |     Teylor          |\n");
    printf("|_____|_____________________|_____________________|\n");
    tabulation(0.1, 0.6, 14);
    printf("|_____|_____________________|_____________________|\n");
}
