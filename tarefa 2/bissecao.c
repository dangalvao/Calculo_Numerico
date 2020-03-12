#include <stdio.h>
#include <math.h>

double f(double x){
  return (pow(x,3) - 1.7*pow(x,2) - 12.78*x - 10.08);
}

int tem_zero(double a, double b){
  if(f(a)*f(b) < 0){
    return 1;
  }
  else{
    return 0;
  }
}

double achar_zero(double a, double b, int c){
  double m = (a+b)/2;
  c += 1;
  if(f(m) >= -0.00000001 && f(m) <= 0.00000001){
    printf("%.2lf\n", m);
    printf("Iterações: %d\n", c);
  }
  else{
    if(tem_zero(a,m)){
      achar_zero(a,m, c);
    }
    if(tem_zero(m,b)){
      achar_zero(m,b, c);
    }
  }
}

int main(void) {
  printf("Encontrando zeros entre -5 e 5 em intervalos de distância 1:\n");
  for(int i = -5; i < 5; i++){
      achar_zero(i,i+1,0);
  }
  return 0;
}