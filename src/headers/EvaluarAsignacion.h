#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void evaluarAsignar(string variable){
    //validacion del caracter de asignación
    if(variable != ":="){
      cout<<"Error en la validacion del identificador\n debe ser :=\n";
      //mata el programa
      exit(0);
    }
    
}//evaluarAsignar
