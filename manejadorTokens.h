#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//archivos necesarios

using namespace std;


//funcion que obtiene el token
int obtenerTokens(vector<string> algo,int posicion){
    //se recorre el arreglo de tokens hasta encontrar el correspondiente
    for(int i = 0; i <= 32; i++){
        if(algo[posicion] == TOKENS[i]){
            //se retorna la posicion del token
            return i;
        }
    } 
    return 0;
}

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
}


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
}

//funcion que manejara el flujo
int bloque(vector<string> algo,int token,int posicion){
    //verifica si el token esta entre 1 y 5 porque son las de los tipo de datos
    if(token == 1 || token == 2 || token == 3 || token == 4 || token == 5){
        //se avanza el carro
        posicion = posicion+1;
        //si es un identificador de tipo de datos por consecuencia sigue una variable asi que valida
        evaluarVariable(algo[posicion]);
    }
    //se retorna la nueva posicion de lectura
    return posicion;
}


