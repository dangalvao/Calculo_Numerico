#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss(double** a, double* b, double* x, int n){
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
}

void multiplica_ax(double** a, double* x, double* ax, int n){
  for (int i = 0; i < n; i++) {
    ax[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ax[i] += a[i][j] * x[j];
    }
  }
}

void calcula_residual_norma(double* b, double* ax, int n){
  double *residual = (double*)malloc(n*sizeof(double));
  for(int i = 0; i < n; i++){
    residual[i] = b[i] - ax[i];
  }
  
  double norma = 0;
  for(int i = 0; i < n; i++){
    norma += pow(residual[i], 2.0);
  }
  printf("Norma: %lf\n", pow(norma, 0.5));
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
  double *x = (double*)malloc(n*sizeof(double));
  double *ax = (double*)malloc(n*sizeof(double));

  for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
          fscanf(entrada, "%lf", a[i] + j);
      }
      fscanf(entrada, "%lf", b + i);
  }

  fclose (entrada);

  gauss(a, b, x, n);

  multiplica_ax(a, x, ax, n);

  calcula_residual_norma(b, ax, n);

  return 0;
}