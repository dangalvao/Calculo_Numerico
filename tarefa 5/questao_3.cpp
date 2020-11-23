#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
  return x*sin(x);
}

double trapezio(double a, double b, double n){
  double h = (b-a)/n;
  double resultado = 0;
  for(int i = 0; i < n; i++){
    resultado += f(a+(i*h)) + f(a+((i+1)*h));
  }
  resultado = (resultado*h)/2;
  return resultado;
}

double um_terco(double a, double b, double n){
  double h = ((b - a) / n) / 2;
  double resultado = 0;
  for(int i = 0; i < n; i++){
    resultado += (f(a+(2*i*h)) + 4*f(a+h+(2*i*h)) + f(a+2*h+(2*i*h)));
  }
  resultado = (resultado*h)/3;
  return resultado;
}

double tres_oitavos(double a, double b, double n){
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
  for(int k = 1; k <= 6; k++){
    cout << "K: " << k << endl;
    cout << "Trapézio: " << trapezio(a, b, k*6) << endl;
    cout << "1/3 de Simpson: " << um_terco(a, b, k*3) << endl;
    cout << "3/8 de Simpson: " << tres_oitavos(a, b, k*2) << endl;
    cout << "============================" << endl;
  }
}