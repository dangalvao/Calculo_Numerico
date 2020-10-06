#include <stdio.h>
#include <stdlib.h>

void gauss(double** a, double* b, int n){
  double *x = (double*)malloc(n*sizeof(double));
  double m, soma;
  for(int k = 0; k < n-1; k++){
    for(int i = k+1; i <= n-1; i++){
      m = a[i][k]/a[k][k];
      a[i][k] = 0;
      for(int j = k+1; j <= n-1; j++){
        a[i][j] = a[i][j] - m*a[k][j];
      }
      b[i] = b[i] - m*b[k];
    }
  }
  x[n-1] = b[n-1]/a[n-1][n-1];
  for(int i = n-2; i >= 0; i--){
    soma = 0;
    for(int j = i+1; j < n; j++){
      soma = soma + a[i][j]*x[j];
    }
    x[i] = (b[i] - soma)/a[i][i];
  }
  printf("X: ");
  for(int j = 0; j < n; j++){
    printf("%lf ", x[j]);
  }
  printf("\n");
}

int main(void) {
  int n;
  
  FILE *entrada;
  entrada = fopen ("m1.in", "r");
  if (entrada == NULL)
      return 0;

  fscanf(entrada, "%d", &n);

  double **a = (double **)malloc(n*sizeof(double*));
  for(int i = 0; i < n; i++){
    a[i] = (double*)malloc(n*sizeof(double));
  }
  double *b = (double*)malloc(n*sizeof(double));

  for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
          fscanf(entrada, "%lf", a[i] + j);
      }
      fscanf(entrada, "%lf", b + i);
  }

  fclose (entrada);

  gauss(a, b, n);

  return 0;
}