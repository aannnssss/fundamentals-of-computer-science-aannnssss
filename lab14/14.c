#include <stdio.h>

enum {maxn = 7};

int main() {
    int m[maxn][maxn];
    int n;
    printf("Введите размер: n = ");
    scanf("%d",&n);
    printf("Введите матрицу: \n");
    for (int i = 0; i != n; i += 1) {
        for (int j = 0; j != n; j += 1) 
            scanf("%d", &m[i][j]); 
    }
    printf("Полученный результат: \n");
    
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
    printf("\n");
    return 0;
}
