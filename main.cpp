#include <iostream>
#include <string>
#include <vector>
//archivos necesarios
#include "StringAnalyzer.h"

using namespace std;


int main (void){
  string cadenaDeTexto = "ENT NombreDeVariable := 10 ;";
  vector<string> x = Separar(cadenaDeTexto, ' ');

  cout<<"tamanio de la cadena: "<<x.size()<<"\n";
  
  cout<<x[0]<<"\n";
  cout<<x[1]<<"\n";
  cout<<x[2]<<"\n";
  cout<<x[3]<<"\n";
  cout<<x[4]<<"\n";
  cout<<x[5]<<"\n";
  
  return 0;
}//main
