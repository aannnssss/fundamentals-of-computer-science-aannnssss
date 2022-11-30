#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void multiply(size_t n, int p[], int m[2]) {
    for (ptrdiff_t i = n; i >= 0; --i) {
        if (i==0) {
            p[i] = m[0] * p[i];
        } else if (i==n) {
            p[i] = m[1] * p[i - 1];
        } else {
            p[i] = m[0] * p[i];
            p[i] += m[1] * p[i - 1];
        }
    }
}

int main(void) {
    int p[4] = { 13, 7, -5 }, m[2] = { 3, -3 };
    multiply(3, p, m);
    assert(
        p[0] == 39 && p[1] == -18 &&
        p[2] == -36 && p[3] == 15
    );
    return 0;
}

