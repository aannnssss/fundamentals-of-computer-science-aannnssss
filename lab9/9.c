#include <stdio.h>


int mod (int a, int b)
{
    return a -(a/b)*b;
}
        
int max(int a, int b)
{
    if (a > b) return a;
    else
        return b;
}
    
int min(int a, int b)
{
    if (a < b) return a;
    else
        return b;
}
    
    
int fi(int a, int b, int c, int d)
{
        return (mod(a * min(b , c) + b * min(a , c) +  d*d, 20 ));
}
int fj(int a, int b, int c, int d)
{
        return (mod(mod(a , 10 - d) * mod(b , 10+d) * mod (c, 10-d) , 25 ));
}
int fl(int a, int b, int c, int d)
{
        return (max(mod(min(a+b,b+c), 25), mod( max(a+c,b +d), 20)) +10);
}
    
const int i0 = -22, d0 = 14, l0 = -14;
int i=i0, j=d0, l=l0, k=0;
    
int p1, p2;
int sh = 0;
                
int main(void)
{
    for (int k=0; k<50; ++k)
    {
        int tshi, tshj, tshl;
        p1 = (i+j+10);
        p2 = (i+j+20);
        if ((p1==0 ) && (p2==0 )) {
            printf("Точка попала в полосу, ограниченную прямыми, конечные координаты : (%d,%d), значение динамического параметра движения: %d, шаг: %d.\n", i,j,l,sh);
            break;
            
        } else
        {
            tshi = fi(i, j, l, k);
            tshj = fj(i, j, l, k);
            tshl = fl(i, j, l, k);
            i = tshi;
            j = tshj;
            l = tshl;
            sh+=1;
        }
        
    }
    if (sh == 50) {
        printf("Точка не попала в полосу, ограниченную прямыми, конечные координаты : (%d,%d), значение динамического параметра движения: %d, шаг: %d.\n", i,j,l,sh);
    }
    return 0;
}
