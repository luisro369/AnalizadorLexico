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
                        cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba un numero para la posicion del arreglo\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba una variable para ingresarla en el arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba una variable arreglo\n";
            exit(0);
        }
    }
    return pos;
}//validador ingresar arreglo
