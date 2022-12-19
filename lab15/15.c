#include <stdio.h>
#include <limits.h>

enum {maxn = 8};

void input(int n, int (*m)[n]);
void process(int n, int (*m)[n]);

int main() {
    int m[maxn][maxn];
    int n;
    scanf("%d",&n);
    input(n, (int (*)[n]) m);
    printf("\n");
    process(n, (int (*)[n]) m);
    return 0;
}
void input(int n, int (*m)[n]) {    
    for (int i = 0; i != n; i += 1) {
        for (int j = 0; j != n; j += 1) 
            scanf("%d", &m[i][j]); 
    }
}

void process (int n, int (*m)[n]) {
    int i = 0, j = 0, maxelem = INT_MIN;
    while (n > i) {
        while (j < n) {
            if ((m[i][j]) > maxelem) {
                maxelem = m[i][j];
                j += 1; 
            } else 
                j += 1;
        }
        j = i;
        m[i][j] = maxelem;
        for (int j = 0; j < n; j += 1) 
            printf("%d ", m[i][j]);
        printf("\n");
        maxelem = -10000000;
        i += 1;
        j = 0;
    }
}   
