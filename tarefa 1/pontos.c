#include <stdio.h>
#include <math.h>

double f(double x){
    return (cos(x) - (x * sin(x)));
}

int main(void){
  double x, h, fx;

  x = 0;
  h = 1;
  fx = 1;
  for(int i = 0; i < 6; i++){
    fx += h*f(x);
    x += h;
    printf("%.0lf %.2lf\n", x, fx);
  }

  x = 0;
  h = -1;
  fx = 1;
  for(int i = 0; i < 6; i++){
    fx += h*f(x);
    x += h;
    printf("%.0lf %.2lf\n", x, fx);
  }
}