#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return (pow(x,3) - (1.7*pow(x,2)) - 12.78*x - 10.08);
}

double f_derivada(double x){
  return (3*pow(x,2) - (3.4*x) - 12.78);
}

int main(void) {
  int iteracoes_maximas = 12, contador = 0;
  double e = 0.01; //critério de parada
  double x = 4; //chute inicial

  for(int i = 0; i < iteracoes_maximas; i++){
    contador++;
    printf("x: %lf f(x): %lf\n", x, f(x));
    if(f(x) < e && f(x) > -1*e){
      printf("Raiz: %lf\n", x);
      break;
    }
    x = (x-(f(x)/f_derivada(x)));
  }
  printf("Iteracoes pelo metodo de Newton: %d\n", contador);
  return 0;
}