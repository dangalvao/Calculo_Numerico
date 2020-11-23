#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
  return x*sin(x);
}

double trapezio(double a, double b){
  double n = 6;
  double h = (b-a)/n;
  double resultado = 0;
  for(int i = 0; i < n; i++){
    resultado += f(a+(i*h)) + f(a+((i+1)*h));
  }
  resultado = (resultado*h)/2;
  return resultado;
}

int main() {
  double a = -5, b = 5;
  cout << trapezio(a, b) << endl;
}