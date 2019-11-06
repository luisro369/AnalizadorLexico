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
                if(VSin[pos] == "VAR"){
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
                        cout<<ERRORES[9];
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<ERRORES[3];
                    exit(0);
                }
            }else{
                //se muere
                cout<<ERRORES[4];
                exit(0);
            }
        }else{
            //se muere
            cout<<ERRORES[6];
            exit(0);
        }
    }
    return pos;
}//validador lectura
