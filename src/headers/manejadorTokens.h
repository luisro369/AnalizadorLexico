#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//archivos necesarios
# include "EvaluarVariable.h"
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



bool checkNumeric(string str){
    bool retVal;
    for(int i = 0; i < str.size()-1; i++){
        if(isdigit(str[i]) == 0){
            //retorna true si encontro algo que no es numero
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




void evaluarAsignar(string variable){
    //validacion del caracter de asignación
    if(variable != ":="){
        cout<<"Error en la validacion del identificador\n debe ser :=\n";
        //mata el programa
        exit(0);
    }
    
}

void evaluarValor(string variable,int token){
    //validacion del caracter ;
    switch(token){
        case 1:
                if(checkNumeric(variable)){
                    if(variable.length()>1){
                        if(checkNumeric(variable.substr(0,variable.length()-1))){
                            //mata el programa
                            cout<<"el ingreso debe ser entero y terminar en ;\n";
                            exit(0);
                        }else{
                            if(variable.substr(variable.length()-1,variable.length()) != ";"){
                                //mata el programa
                                cout<<"solo se permite terminar una linea de codigo con el caracter -> ;\n";
                                exit(0);
                            }
                        }
                    }
                }
        break;
        case 2:
                if(variable.length()>11){
                    //mata el programa
                    cout<<"solo se permite ingresar flotantes con magnitud de 5 enteros y 5 decimales maximo;\n";
                    exit(0);
                }
        break;
        case 3:
                if(variable.length() != 3 && variable.length() != 4){
                    //mata el programa
                    cout<<"el ingreso de un caracter debe ser entre comillas simple pudiendo incluir el caracter -> ;\n";
                    exit(0);
                }
                if(!(variable.substr(0,1) == "\'") && (variable.substr(2,variable.length()) == "\'")){
                    //mata el programa
                    cout<<"el ingreso de un caracter debe ser entre comillas simple pudiendo incluir el caracter ->;\n";
                    exit(0);
                }
        break;
        case 4:
                if(variable.length()<2){
                     //mata el programa
                    cout<<"el ingreso de una cadena debe ser entre comillas dobles;\n";
                    exit(0);
                }    
        break;
        case 5:
                if(variable != "VERDADERO" && variable != "FALSO" && variable != "VERDADERO;" && variable != "FALSO;"){
                     //mata el programa
                     cout<<"la variable solo acepta los valores VERDADERO Y FALSO;\n";
                     exit(0);
                }
        break;
    }
}

//funcion que manejara el flujo
int bloque(vector<string> algo,int token,int posicion){
    //verifica si el token esta entre 1 y 5 porque son las de los tipo de datos
    if(token == 1 || token == 2 || token == 3 || token == 4 || token == 5){
        //se avanza el carro
        posicion = posicion+1;
        //si es un identificador de tipo de datos por consecuencia sigue una variable asi que la valida
        evaluarVariable(algo[posicion]);
        posicion = posicion+1;
        evaluarAsignar(algo[posicion]);
        posicion = posicion+1;
        evaluarValor(algo[posicion],token);
    }
    //se retorna la nueva posicion de lectura
    return posicion;
}


