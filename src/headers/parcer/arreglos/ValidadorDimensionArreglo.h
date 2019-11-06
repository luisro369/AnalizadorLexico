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
        if(VSin[pos] == "VAR"){
            cout<<"ARREGLO A DIMESIONAR------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "NUM"){
                //todo bien
                cout<<"DIMENSION DEL ARREGLO-----------------------SINTACTICO\n";
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
                cout<<ERRORES[20];
                exit(0);
            }   
        }else{
            //se muere
            cout<<ERRORES[21];
            exit(0);
        }
    }
    return pos;
}//validador Dimension arreglo
