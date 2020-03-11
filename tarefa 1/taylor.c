#include <stdio.h>
#include <math.h>

double f_par(int k){
    return (pow(-1,k/2)*k*sin(0));
}

double f_impar(int k){
    return (pow(-1,(k-1)/2)*k*cos(0));
}

int fat(int x){
  if(x == 0){
    return 1;
  }
  else{
    return x*fat(x-1);
  }
}

double f_final(int x){
    double soma = 0;
    for(int i = 0; i<= 15; i++){
      if(i % 2 == 0){
        soma += 0;
      }
      else{
        soma += (f_impar(i)*pow(x,i))/fat(i);
      }
    }
    return soma;
}

int main(void){
  printf("Resultados da k-ésima derivada (até 12)\n");
  for(int k = 0; k <= 12; k++){
    if(k%2==0){
      printf("%d: %.2lf\n", k, f_par(k));
    }
    else{
      printf("%d: %.2lf\n", k, f_impar(k));
    }
  }
  printf("\n\nAproximação pela Série de Taylor:\n");
  for(int x = -6; x <= 6; x++){
    printf("%d: %.2lf\n", x, f_final(x));
  }
}