#include <stdio.h>
#include <math.h>

const long double k = 10e2;
const long double e = 2.71828182846;
int MAX_ITER = 100;

long double machine_eps(long double x) {
    long double eps = 1;
    while (1<1+eps)
        eps /= 2;
    return eps;
}

int factorial(long long n) {
    long double ans = 1;
    for (long long i = 2; i <= n; i += 1) 
        ans *= i;
    return ans;
}

long double func(long double x) {
    return ( (pow(e,x) + pow(e,-x)) /2 );
}

long double taylor(long double x, int n) {
    long double sum = 0;
    for (long double i = 0.0; i <= n; i += 1) 
        sum += (pow(x,2*i)/factorial(2*i));
    return sum;
}

int main() {
    long double a = 0.1, b = 0.6, step, result;
    int n;
    printf("Enter the iterations: ");
    scanf("%d",&n);
    printf("\n");
    step = (b-a)/n;
    long double ps = machine_eps(a);
    printf("Machine epsilon: %.40Lf\n",ps);
    printf("Taylor series value table for f(x) = ch x\n");
    printf("___________________________________________________________________\n");
    printf("|  x    |       sum of row       |        function        |   iter |\n");
    printf("___________________________________________________________________\n");
    for (long double x = a; x <= b; x += step) {
        long double eps = machine_eps(x);
        for (n = 0; n < MAX_ITER; n++) {
            result = taylor(x, n);
            if (fabs(result) < eps * k) 
                break;
        }
        printf("| %.3Lf | %.20Lf | %.20Lf |  %d   |\n",x,result,func(x),n);
        result = 0.0;
    }
    printf("|_______|________________________|________________________|________|\n");
    return 0;
}
  
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
 
            
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
        
