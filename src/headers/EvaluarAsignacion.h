#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Con esta funcion puedo evaluar si la asignacion es la
correcta aceptada por el lenguaje (:=)
*/

void evaluarAsignar(string variable){
    //validacion del caracter de asignación
    if(variable != ":="){
      cout<<"Error en la validacion del identificador\n debe ser :=\n";
      //mata el programa
      exit(0);
    }
    
}//evaluarAsignar
