#include<iostream>

using namespace std;

double cuadrado(int &n);

double cuadrado(int &n)
{
  return n*=n;
}

int main(){
  int x=3;
  cuadrado(x);
  cout<<x;
}
