#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorLectura(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[11]){
        //Indicador de repetidor
        cout<<"FUNCION DE LECTURA CONSOLA------------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                      //cout<<ERRORES[9];
                      cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[9];
                      imprimirError(posTemp,9);
                    }
                }else{
                    //se muere
                    //cout<<ERRORES[3];
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[3];
                    imprimirError(posTemp,3);
                }
            }else{
                //se muere
                //cout<<ERRORES[4];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[4];
                imprimirError(posTemp,4);
            }
        }else{
            //se muere
            //cout<<ERRORES[6];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
            imprimirError(posTemp,6);
        }
    }
    return pos;
}//validador lectura
