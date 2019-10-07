#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//funcion que valida si la variable es solo de letras
bool checkAlpha(string str){
    bool retVal;
    for(int i = 0; i < str.size(); i++){
        if(isalpha(str[i]) == 0){
            //retorna true si encontro algo que no es letra
            retVal = true;
            break;
        }
        else{
            //todo bien
            retVal = false;
        }
    }
    return retVal;
}//checkAlpha



//funcion de validaciones
void evaluarVariable(string variable){
    //validacion de tamaño igual o menor que 12
    if(variable.length() > 12){
        cout<<"la variable contiene mas de 12 caracteres\n";
        //mata el programa
        exit(0);
    }
    //funcion que chequea si es solo letras
    if(checkAlpha(variable)){
        //mata el programa
        cout<<"la variable solo debe contener letras\n";
        exit(0);
    }
}// evaluarVariable

