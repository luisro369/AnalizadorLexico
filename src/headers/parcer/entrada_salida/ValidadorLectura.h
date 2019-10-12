#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorLectura(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[11]){
        //Indicador de repetidor
        cout<<"FUNCION DE LECTURA CONSOLA------------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE LECTURA-----SINTACTICO\n";
            pos = pos+1;
                if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"VARIABLE A ASIGNAR LA LECTURA---------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[8]){
                    //todobien
                    cout<<"PARENTESIS QUE INDICA FIN DE LECTURA--------SINTACTICO\n";
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
                    cout<<"ERROR: se esperaba simbolo de fin de lectura ')'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba una variable asiganble\n";
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de incio de lectura '('\n";
            exit(0);
        }
    }
    return pos;
}//validador lectura
