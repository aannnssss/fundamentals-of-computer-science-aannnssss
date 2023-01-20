#include <stdio.h>
#include <math.h>

int MAX_ITER = 100;

long double machine_epsilon() {
    long double eps = 1;
    while (1 + eps / 2 != 1)
        eps /= 2;
    return eps;
}

int factorial(long long n) {
    long double ans = 1;
    for (long long i = 2; i <= n; i += 1) 
        ans *= i;
    return ans;
}

long double function(long double x) {
    return ( exp(x) + exp(-x)) /2 ;
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
    long double abs_epsilon = machine_epsilon();
    long double otn_epsilon = sqrt(abs_epsilon);
    printf("Machine epsilon: %.40Lf\n",abs_epsilon);
    printf("Taylor series value table for f(x) = ch x\n");
    printf("___________________________________________________________________\n");
    printf("|  x    |       sum of row       |        function        |   iter |\n");
    printf("___________________________________________________________________\n");
    for (long double x = a; x <= b; x += step) {
        for (n = 0; n < MAX_ITER; n += 1) {
            result = taylor(x, n);
            if (fabs(result) <= fmax(otn_epsilon * fabs(result), abs_epsilon))
                break;
        }
        printf("| %.3Lf | %.20Lf | %.20Lf |  %d   |\n",x,result,function(x),n);
        result = 0.0;
    }
    printf("|_______|________________________|________________________|________|\n");
    return 0;
}
  
