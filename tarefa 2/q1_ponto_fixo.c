#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double g(double x){
  return (-1*pow(x,3) + (1.7*pow(x,2)) + 10.08);
}

double f(double x){
  return (-12.78*x - g(x));
}

int main(void) {
  int iteracoes_maximas = 12, contador = 0;
  double e = 0.01; //critério de parada
  double x = -1; //chute inicial

  for(int i = 0; i < iteracoes_maximas; i++){
    contador++;
    printf("x: %lf  g(x): %lf  f(x): %lf\n", x, g(x),f(x));
    if(f(x) < e && f(x) > -1*e){
      printf("Raiz: %lf\n", x);
    }
    x = g(x);
  }
  printf("Iteracoes pelo metodo do ponto fixo: %d\n", contador);
  return 0;
}