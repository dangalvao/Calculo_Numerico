#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double modulo(double valor){
  if(valor < 0){
    return (-1*valor);
  }
  return valor;
}

void gauss_pivoteamento(double** a, double* b, double* x, int n){
  double m, soma, pivo, aux;
  int indice_pivo;
  for(int k = 0; k < n-1; k++){
    pivo = a[k][k];
    indice_pivo = k;
    for(int i = k+1; i < n; i++){
      if(modulo(a[i][k]) > modulo(pivo)){
        pivo = a[i][k];
        indice_pivo = i;
      }
    }
    if(indice_pivo != k){
      for(int j = 0; j < n; j++){
        aux = a[k][j];
        a[k][j] = a[indice_pivo][j];
        a[indice_pivo][j] = aux;
      }
      aux = b[k];
      b[k] = b[indice_pivo];
      b[indice_pivo] = aux;
    }
    for(int i = k+1; i < n; i++){
      m = a[i][k]/a[k][k];
      a[i][k] = 0;
      for(int j = k+1; j < n; j++){
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

double calcula_residual_norma(double* b, double* ax, int n){
  double *residual = (double*)malloc(n*sizeof(double));
  for(int i = 0; i < n; i++){
    residual[i] = b[i] - ax[i];
  }
  
  double norma = 0;
  for(int i = 0; i < n; i++){
    norma += pow(residual[i], 2.0);
  }
  norma = pow(norma, 0.5);
  return norma;
}

int main(void) {
  double norma;
  int n, contador = 0;
  
  FILE *entrada;
  entrada = fopen ("m3.in", "r");
  if (entrada == NULL)
    return 0;

  fscanf(entrada, "%d", &n);

  double **a_original = (double **)malloc(n*sizeof(double*));
  for(int i = 0; i < n; i++){
    a_original[i] = (double*)malloc(n*sizeof(double));
  }

  double **a = (double **)malloc(n*sizeof(double*));
  for(int i = 0; i < n; i++){
    a[i] = (double*)malloc(n*sizeof(double));
  }

  double *b = (double*)malloc(n*sizeof(double));
  double *x = (double*)malloc(n*sizeof(double));
  double *ax = (double*)malloc(n*sizeof(double));

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      fscanf(entrada, "%lf", a_original[i] + j);
    }
    fscanf(entrada, "%lf", b + i);
  }

  fclose (entrada);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      a[i][j] = a_original[i][j];
    }
  }

  while(contador < 150){
    contador++;

    gauss_pivoteamento(a, b, x, n);

    multiplica_ax(a, x, ax, n);

    norma = calcula_residual_norma(b, ax, n);

    printf("Norma: %lf\nNumero de iteracoes: %d\n", norma, contador);
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        a[i][j] = a_original[i][j];
      }
      b[i] = ax[i];
    }

  }

  return 0;
}