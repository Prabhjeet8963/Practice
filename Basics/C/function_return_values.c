#include <stdio.h>

double square(double x){

    double result = x * x;
    return result;
}


int main(){

    double x = square(5.0);
    printf("%0.2lf\n",x);

    return 0;
}