#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida
int validadorManejoArchivos(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[22] || VSin[pos] == TOKENST[23] || VSin[pos] == TOKENST[24]){
        //Indicador de repetidor
        cout<<"FUNCION DE MANEJO DE ARCHIVOS---------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                //cout<<ERRORES[17];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[17];
                imprimirError(posTemp,17);
            }
        }else{
            //se muere
            //cout<<ERRORES[6];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
            imprimirError(posTemp,6);
        }    
    }    
    return pos;
}//validador Manejo de archivos
