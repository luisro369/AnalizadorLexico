#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorIngArreglo(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[18]){
         //Indicador de ingreso de arreglo
        cout<<"INDICADOR INSERCION DE ARREGLO--------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "VAR"){
            cout<<"ARREGLO A INGRESAR DATOS--------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "VAR"){
                //todo bien
                cout<<"VARIABLE A INGRESAR EN EL ARREGLO-----------SINTACTICO\n";
                pos = pos+1;
                 if(VSin[pos] == "NUM"){
                    //todo bien
                    cout<<"POSICION DEL ARREGLO A INGRESAR-------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[11]){
                        //avance de carro
                        cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                    }else{
                        //se muere
                        cout<<ERRORES[9];
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<ERRORES[22];
                    exit(0);
                }
            }else{
                //se muere
                cout<<ERRORES[23];
                exit(0);
            }   
        }else{
            //se muere
            cout<<ERRORES[21];
            exit(0);
        }
    }
    return pos;
}//validador ingresar arreglo
