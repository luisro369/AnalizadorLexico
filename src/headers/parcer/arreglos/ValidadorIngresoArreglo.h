#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorIngArreglo(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[18]){
         //Indicador de ingreso de arreglo
        cout<<"INDICADOR INSERCION DE ARREGLO--------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                        //cout<<ERRORES[9];
                        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[9];
                        imprimirError(posTemp,9);
                    }
                }else{
                    //se muere
                    //cout<<ERRORES[22];
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[22];
                    imprimirError(posTemp,22);
                }
            }else{
                //se muere
                //cout<<ERRORES[23];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[23];
                imprimirError(posTemp,23);
            }   
        }else{
            //se muere
            //cout<<ERRORES[21];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[21];
            imprimirError(posTemp,21);
        }
    }
    return pos;
}//validador ingresar arreglo
