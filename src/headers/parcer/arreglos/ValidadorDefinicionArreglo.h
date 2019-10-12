#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorDefArreglo(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[16]){
         //Indicador de definicion de arreglo
        cout<<"INDICADOR DEFINCION DE ARREGLO--------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == TOKENST[1] || VSin[pos] == TOKENST[2] || VSin[pos] == TOKENST[3] || VSin[pos] == TOKENST[4] || VSin[pos] == TOKENST[5]){
            cout<<"INDICADOR DEL TIPO DEL ARREGLO--------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"NOMBRE DE ARREGLO---------------------------SINTACTICO\n";
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
                cout<<"ERROR: se esperaba un nombre para asignar al arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba un tipo de dato valido para el arreglo 'ENT', 'FLOT','CAD','CAR','BOOL'\n";
            exit(0);
        }
    }
    return pos;
}//validadorArreglo
