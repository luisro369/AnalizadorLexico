#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void evaluarAsignar(string variable){
    //validacion del caracter de asignación
    if(variable != ":="){
        cout<<"Error en la validacion del identificador\n debe ser :=\n";
        //mata el programa
        exit(0);
    }
    
}
