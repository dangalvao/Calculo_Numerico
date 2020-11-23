#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
  return x*sin(x);
}

double um_terco(double a, double b){
  double n = 3;
  double h = ((b - a) / n) / 2;
  double resultado = 0;
  for(int i = 0; i < n; i++){
    resultado += (f(a+(2*i*h)) + 4*f(a+h+(2*i*h)) + f(a+2*h+(2*i*h)));
  }
  resultado = (resultado*h)/3;
  return resultado;
}

int main() {
  double a = -5, b = 5;
  cout << um_terco(a, b) << endl;
}