#include <iostream>
#include <stdlib.h>

using namespace std;

double potencia(double base, int exponente);

int main(){
  system("cls");
  double b;
  int e;
  cout<<"Ingrese la base: ";
    cin>>b;
    cout<<"Ingrese el exponente: ";
    cin>>e;
    cout<<"El resultado es: "<<potencia(b,e);
    return 0;
}

double potencia(double base, int exponente){
  int contador;
  bool negativo=false;
  double resultado = 1.0;
  if(exponente<0){
    exponente = -exponente;
    negativo = true;
  }
  for(contador=1; contador<=exponente; contador++){
    resultado *= base;
    if(negativo){
      return 1/resultado;
      return resultado;
    }
    }
  }
