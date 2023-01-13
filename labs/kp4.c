#include <stdio.h>
#include <math.h>

typedef long double ldbl;

ldbl machine_epsilon() {
    ldbl eps = 1.0;
    while (1 + eps / 2.0 != 1)
        eps /= 2.0;
    return eps;
}

ldbl F19(ldbl x) {
    return x - 1/(3 + sin(3.6*x));
}

ldbl f19(ldbl x) {
    return 1/(3 + sin(3.6*x));
}

ldbl f19_first_derivative(ldbl x) {
    return -(3.6*cos(3.6*x)/(3+sin(3.6*x)*(3+sin(3.6*x))));
}

ldbl F19_first_derivative(ldbl x) {
    return 1 + (3.6*cos(3.6*x)/(3+sin(3.6*x)*(3+sin(3.6*x))));
}

ldbl F19_second_derivative(ldbl x) {
    return (-3.6*3.6*sin(3.6*x)*(3+sin(3.6*x))*(3+sin(3.6*x)) - (3.6*cos(3.6*x))*2*3.6*cos(3.6*x)*(3+sin(3.6*x)))/(pow(3+sin(3.6*x),4));
}

ldbl F20(ldbl x) {
    return 0.1*x*x-x*logl(x);
}

ldbl f20(ldbl x) {
    return sqrt(10*x*logl(x));
}

ldbl f20_first_derivative(ldbl x) {
    return (10*logl(x)+1)/(2*sqrt(10*x*logl(x)));
}

ldbl F20_first_derivative(ldbl x) {
    return 0.2*x-logl(x)-1;
}

ldbl F20_second_derivative(ldbl x) {
    return 0.2-1/x;
}

ldbl dichotomya(ldbl (*F)(ldbl), ldbl a, ldbl b, ldbl abs_epsilon, ldbl otn_epsilon) {
    ldbl x = (a + b) / 2;
    if (F(a) * F(b) < 0){
        while (fabs(a - b) > fmax(otn_epsilon * fabs(x), abs_epsilon)) {
            x = (a + b) / 2;
            if (F(x) * F(a) < 0) 
                b = x;
            else 
                a = x;   
        }
        return x;
    }
    else
        return 0;
}

ldbl iteration(ldbl (*f)(ldbl), ldbl (*f_first_derivative)(ldbl), ldbl a, ldbl b, ldbl abs_epsilon, ldbl otn_epsilon)
{
    ldbl x = (a + b) / 2;
    if (fabs(f_first_derivative(x)) < 1) {
        while (fabs(f(x) - x) >= fmax(otn_epsilon * fabs(x), abs_epsilon))
            x = f(x);
        return x;
    }
    else 
        return 0;
}

ldbl newton(ldbl (*F)(ldbl),ldbl (*F_first_derivative)(ldbl),ldbl (*F_second_derivative)(ldbl),ldbl a,ldbl b, ldbl abs_epsilon, ldbl otn_epsilon) {
    ldbl x = (a + b / 2);
    if (fabs(F(x) * F_second_derivative(x)) < (F_first_derivative(x) * F_first_derivative(x))) {
        while (fabs(F(x) / F_first_derivative(x)) > fmax(otn_epsilon * fabs(x), abs_epsilon)) 
            x -= F(x) / F_first_derivative(x);
        return x;
    }
    else 
        return 0;
}

void result(ldbl d, ldbl i, ldbl n) {
   if (d != 0) printf("The dichotomya method: %.10Lf\n", d);
   else printf("The dechotomya method isn't suitable\n");
   if (i != 0) printf("The iteration method: %.10Lf\n", i);
   else printf("The iteration method isn't suitable\n");
   if (n != 0) printf("The Newton's method: %.10Lf\n", n);
   else printf("The Newton's method isn't suitable\n");
}

int main() {
    ldbl a2 = 0, b2 = 0.85;
    ldbl a3 = 1, b3 = 2;
    ldbl abs_epsilon = machine_epsilon();
    ldbl otn_epsilon = sqrt(abs_epsilon);
    ldbl d1 = dichotomya(F19, a2, b2, otn_epsilon, abs_epsilon);
    ldbl i1 = iteration(f19, f19_first_derivative, a2, b2, otn_epsilon, abs_epsilon);
    ldbl n1 = newton(F19, F19_first_derivative, F19_second_derivative, a2, b2, otn_epsilon, abs_epsilon);
    printf("Machine epsilon is %.40Lf\n", abs_epsilon);
    printf("Function 19 var: x - 1/(3+sin(3.6x))\n");
    result(d1, i1, n1);
    printf("\n");
    ldbl d2 = dichotomya(F20, a3, b3, otn_epsilon, abs_epsilon);
    ldbl i2 = iteration(f20, f20_first_derivative, a3, b3, otn_epsilon, abs_epsilon);
    ldbl n2 = newton(F20, F20_first_derivative, F20_second_derivative, a3, b3, otn_epsilon, abs_epsilon);
    printf("Function 20 var: 0.1*x^2-x*ln(x)\n");
    result(d2, i2, n2);
    return 0;
}

