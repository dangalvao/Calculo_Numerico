#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double s(double L){
  double A = 8, x1 = 20, x2 = 30;

  double fator1 = 1/(sqrt(pow(x1,2)-pow(L,2)));

  double fator2 = 1/(sqrt(pow(x2,2)-pow(L,2)));

  double fator3 = 1/A;

  return (fator1 + fator2 - fator3);
}

int main(void) {
  double e = 0.00001; //critério de parada
  double a = 10, b = 20, c = (a+b)/2; //intervalo

  while(1){
    printf("a:%lf  b:%lf  c:%lf\n s(a):%lf  s(b):%lf  s(c):%lf\n", a, b, c, s(a),s(b),s(c));
    if(s(a)*s(b) < 0){
      if(s(c) < e && s(c) > (-1*e)){
        printf("Raiz: %lf -> %lf\n", c, s(c));
        break;
      }
      if(s(a)*s(c) < 0){
        b = c;
        c = (a+b)/2;
      }
      else if(s(c)*s(b) < 0){
        a = c;
        c = (a+b)/2;
      }
      else {
        break;
      }
    }
  }

  return 0;
}