#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorDefArreglo(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[16]){
         //Indicador de definicion de arreglo
        cout<<"INDICADOR DEFINCION DE ARREGLO--------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
        pos = pos+1;
        if(VSin[pos] == TOKENST[1] || VSin[pos] == TOKENST[2] || VSin[pos] == TOKENST[3] || VSin[pos] == TOKENST[4] || VSin[pos] == TOKENST[5]){
            cout<<"INDICADOR DEL TIPO DEL ARREGLO--------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "VAR"){
                //todo bien
                cout<<"NOMBRE DE ARREGLO---------------------------SINTACTICO\n";
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
                //cout<<ERRORES[18];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[18];
                imprimirError(posTemp,18);
            }   
        }else{
            //se muere
            //cout<<ERRORES[19];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[19];
            imprimirError(posTemp,19);
        }
    }
    return pos;
}//validadorArreglo
