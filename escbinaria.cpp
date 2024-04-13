#include <iostream>
#include <fstream>
using namespace std;


int main(){
fstream archivo("personal.bin",ios::out | ios::binary);
char nombre[80];
int codigo;
double sueldo;
if(!archivo) cout<<"Error en la apertura del archivo";
else{
 do{
 cout<<"Escriba el codigo del empleado (0 para salir): ";
 cin>>codigo;
 if(codigo!=0){
 cout<<"Escriba el nombre: ";
 cin>>nombre;
 fflush(stdin);//vacía el bufer de lectura
 cout<<"Escriba el sueldo: ";
 cin>>sueldo;
 //escritura en el archivo
 archivo.write(
 reinterpret_cast<char *>(&codigo),sizeof(codigo));
 archivo.write(nombre,80);
archivo.write(
 reinterpret_cast<char *>(&sueldo),sizeof(sueldo));
 }
 }while(codigo!=0);
 }
 archivo.close();
 return 0;
}
