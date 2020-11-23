#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
  return x*sin(x);
}

double tres_oitavos(double a, double b){
  double n = 2;
  double h = ((b - a) / n) / 3;
  double resultado = 0;
  for(int i = 0; i < n; i++){
    resultado += (f(a+(3*i*h)) + 3*f(a+h+(3*i*h)) + 3*f(a+2*h+(3*i*h)) + f(a+3*h+(3*i*h)));
  }
  resultado = (resultado*h*3)/8;
  return resultado;
}

int main() {
  double a = -5, b = 5;
  cout << tres_oitavos(a, b) << endl;
}