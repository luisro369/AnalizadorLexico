#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida 
int validadorAsignacion(vector<string> VSin, int pos){
    //verifica si se ha ingresado un token de tipo dato
    if(VSin[pos] == TOKENST[1] || VSin[pos] == TOKENST[2] || VSin[pos] == TOKENST[3] || VSin[pos] == TOKENST[4] || VSin[pos] == TOKENST[5]){
        //avance de carro        
        cout<<"DECLARACION DE VARIABLE---------------------SINTACTICO\n";
        pos = pos+1;
        //verifica que acontinuacion cotenga un lexema adecuado para nombre de variable
        if(VSin[pos] == "lexema"){
            //avance de carro
            cout<<"NOMBRE DE VARIABLE ADECAUDA-----------------SINTACTICO\n";
             pos = pos+1;
            //verifica que acontinuacion contenga el simbolo asigando para asignacion
            if(VSin[pos] == ARITMT[6]){
                //avance de carro
                cout<<"SIMBOLO DE ASIGNACON CORRECTA---------------SINTACTICO\n";
                 pos = pos+1;
                //verifica si lo siguiente es un lexema adecuado segun el tipo de dato que se ha declarado
                if(VSin[pos] == "lexema"){
                    //avance de carro
                    cout<<"VALOR DE VARIABLE ADECUADA------------------SINTACTICO\n";
                     pos = pos+1;
                    //verifica que al final de la linea este el simbolo asignado para fin de linea
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
                    cout<<"ERROR: valor no corresponde con tipo de dato\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba simbolo de asignacion ':='\n"; 
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba un nombre para la asginacion de la varible\n"; 
            exit(0);
        }
    }
    return pos;
}//validador asignacion
