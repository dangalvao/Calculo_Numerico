#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return (pow(x,3) - (1.7*pow(x,2)) - 12.78*x - 10.08);
}

int main(void) {
  int iteracoes_maximas = 12, contador = 0;
  double e = 0.01; //critério de parada
  double x0 = -3, x1 = -1.5, x2; //chute inicial
  x2 = (x1 - ((f(x1)*(x1-x0))/(f(x1)-f(x0))));
  for(int i = 0; i < iteracoes_maximas; i++){
    contador++;
    printf("x: %lf f(x): %lf\n", x2, f(x2));
    if(f(x2) < e && f(x2) > -1*e){
      printf("Raiz: %lf\n", x2);
      break;
    }
    if(f(x0)*f(x2) < 0){
      x0 = x0;
      x1 = x2;
      x2 = (x1 - ((f(x1)*(x1-x0))/(f(x1)-f(x0))));
    }
    else if(f(x1)*f(x2) < 0){
      x0 = x2;
      x1 = x1;
      x2 = (x1 - ((f(x1)*(x1-x0))/(f(x1)-f(x0))));
    }
    
  }
  printf("Iteracoes pelo metodo da falsa posicao: %d\n", contador);
  return 0;
}