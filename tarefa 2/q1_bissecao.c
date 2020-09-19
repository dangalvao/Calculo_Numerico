#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return (pow(x,3) - (1.7*pow(x,2)) - 12.78*x - 10.08);
}

int main(void) {
  int iteracoes_maximas = 12, contador = 0;
  double e = 0.01; //critério de parada
  double a = -10, b = 10, c = (a+b)/2; //intervalo

  for(int i = 0; i < iteracoes_maximas; i++){
    contador++;
    printf("a:%lf  b:%lf  c:%lf\n f(a):%lf  f(b):%lf  f(c):%lf\n", a, b, c, f(a),f(b),f(c));
    if(f(a)*f(b) < 0){
      if(f(c) < e && f(c) > (-1*e)){
        printf("Raiz: %lf -> %lf\n", c, f(c));
      }
      if(f(a)*f(c) < 0){
        b = c;
        c = (a+b)/2;
      }
      else if(f(c)*f(b) < 0){
        a = c;
        c = (a+b)/2;
      }
      else {
        break;
      }
    }
  }
  printf("Iteracoes pelo metodo da bissecao: %d\n", contador);
  return 0;
}