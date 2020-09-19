#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double s(double t){
  double s0 = 300, m = 0.25, k = 0.1, g = 32.17, euler = 2.17;

  double fator1 = (m*g)/k;

  double fator2 = (pow(m,2)*g/pow(k,2));

  double fator_expoente = (-1*k*t)/m;

  double fator3 = 1 - pow(euler, fator_expoente);

  return s0 - fator1*t + fator2*fator3;
}

int main(void) {
  double e = 0.00001; //critério de parada
  double x0 = 5, x1 = 6, x2; //chute inicial
  x2 = (x1 - ((s(x1)*(x1-x0))/(s(x1)-s(x0))));

  while(1){
    printf("x: %lf s(x): %lf\n", x2, s(x2));
    if(s(x2) < e && s(x2) > -1*e){
      printf("Raiz: %lf\n", x2);
      break;
    }
    x0 = x1;
    x1 = x2;
    x2 = (x1 - ((s(x1)*(x1-x0))/(s(x1)-s(x0))));
  }

  return 0;
}