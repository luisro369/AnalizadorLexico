#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida
int validadorManejoArchivos(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[22] || VSin[pos] == TOKENST[23] || VSin[pos] == TOKENST[24]){
        //Indicador de repetidor
        cout<<"FUNCION DE MANEJO DE ARCHIVOS---------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE ARCHIVO-----SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"RUTA DEL ARCHIVO----------------------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[8]){
                    //todobien
                    cout<<"PARENTESIS QUE INDICA FIN DE ARCHIVO--------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[11]){
                        //avance de carro
                        cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                        pos;
                    }else{
                        //se muere
                        cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de archivo ')'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba una ruta al archivo\n";
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de incio de archivo '('\n";
            exit(0);
        }    
    }    
    return pos;
}//validador Manejo de archivos
