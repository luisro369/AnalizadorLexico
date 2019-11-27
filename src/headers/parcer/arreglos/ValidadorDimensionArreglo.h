#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorDimArreglo(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[17]){
         //Indicador de definicion de arreglo
        cout<<"INDICADOR DIMENSION DE ARREGLO--------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                    //cout<<ERRORES[9];
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[9];
                    imprimirError(posTemp,9);
                }
            }else{
                //se muere
                //cout<<ERRORES[20];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[20];
                imprimirError(posTemp,20);
            }   
        }else{
            //se muere
            //cout<<ERRORES[21];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[21];
            imprimirError(posTemp,21);
        }
    }
    return pos;
}//validador Dimension arreglo
