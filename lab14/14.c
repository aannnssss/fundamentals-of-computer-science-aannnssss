#include <stdio.h>

enum {maxn = 7};

void input(int n, int (*m)[n]);
void process(int n, int (*m)[n]);

int main() {
    int m[maxn][maxn];
    int n;
    scanf("%d",&n);
    input(n, (int (*)[n]) m);
    process(n, (int (*)[n]) m);
    printf("\n");
    return 0;
}
void input(int n, int (*m)[n]) {    
    for (int i = 0; i != n; i += 1) {
        for (int j = 0; j != n; j += 1) 
            scanf("%d", &m[i][j]); 
    }
}

void process (int n, int (*m)[n]) {
    int i = 0, j = 0, p = 0, cnt = 0;
    while (n * n != p ) {
        if (i % 2 == 0) {
            if (j % 2 == 0) {
                printf("%d ",m[i][j]);
                p += 1;
                j += 1; 
            } else {
                printf("%d ",m[i][j]);
                p += 1;
                if (cnt % 2 == 0) {
                    while (i != j) {
                        i += 1;
                        printf("%d ",m[i][j]); 
                        p += 1; 
                        }
                        cnt += 1; 
                } else {    
                    while (i != j) {
                        j += 1;
                        printf("%d ",m[i][j]);
                        p += 1; 
                    }
                    cnt += 1; 
                    while (i > 0) {
                        i -= 1;
                        printf("%d ",m[i][j]);
                        p += 1; 
                    }
                    j += 1; 
                }       
            }
        } else {
            while (j > 0) {
                j -= 1;
                printf("%d ",m[i][j]);
                p += 1; 
            }
            i += 1;
        }
    }    
    
}
