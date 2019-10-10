#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Con esta funcion puedo evaluar si el tipo de la variable
corresponde al tipo entero
*/

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
}//checkNumeric


/*
Con esta funcion puedo evaluar si el tipo de la variable
corresponde al tipo declarado por el usuario
*/

void evaluarValor(string variable,int token){
    //validacion del caracter ;
    cout<<variable;
    if(variable.substr(variable.length()-1,variable.length()) == ";"){
        variable = variable.substr(0,variable.length()-1);
    }
    cout<<" - "<<variable;
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
}//Evaluar tipo de valor
