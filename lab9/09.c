#include <stdio.h>

int mod (int a, int b)
{
    return a - (a / b) * b;
}
    
    
int min(int a, int b) {
    return a < b ?  a : b;
}


int max(int a, int b) {
    return a > b ?  a : b;
}

int main() {
    int i = -22, j = 14, l = -14, k = 0, i1, j1;
    while (k <= 50) {
        if (k == 50) {
            printf("The point did not fall into the specified area. End coordinates: (%d,%d),dynamic motion parameter: %d, steps: 50.\n", i, j, l);
            break;
        }
        if  ( (i + j + 10 <= 0) && (i + j + 20 >= 0)) {
            printf("The point hit the specified area in %d steps.\n", k);
            break;
        }
        i1 = i;
        j1 = j;
        i = (mod (i1 * min(j1, l) + j1 * min(i1, l) + k * k, 20));
        j = (mod (mod(i1, 10 - k) * mod(j1, 10 + k) * mod(l, 10-k), 25));
        l = (max (mod(min(i1 + j1, i1 + l), 25), mod(max(i1 + l, j1 + k), 20)) + 10);
        k += 1;
    }
    return 0;
}
