#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorDimArreglo(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[17]){
         //Indicador de definicion de arreglo
        cout<<"INDICADOR DIMENSION DE ARREGLO--------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "lexema"){
            cout<<"ARREGLO A DIMESIONAR------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"DIMENSION DEL ARREGLO-----------------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[11]){
                    //avance de carro
                    cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba un numero para la dimsion del arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba una variable arreglo\n";
            exit(0);
        }
    }
    return pos;
}//validador Dimension arreglo
