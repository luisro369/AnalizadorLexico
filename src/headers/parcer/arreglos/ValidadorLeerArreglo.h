#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorLeerArreglo(vector<string> VSin, int pos){
  int posTemp;
   if(VSin[pos] == TOKENST[19]){
         //Indicador de lectura de arreglo
        cout<<"INDICADOR LECTRUA DE ARREGLO----------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
        pos = pos+1;
        if(VSin[pos] == "VAR"){
            cout<<"ARREGLO A LEER------------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "NUM"){
                //todo bien
                cout<<"POSICION DEL ARREGLO AL LEER----------------SINTACTICO\n";
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
                //cout<<ERRORES[24];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[24];
                imprimirError(posTemp,24);
            }   
        }else{
            //se muere
            //cout<<ERRORES[21];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[21];
            imprimirError(posTemp,21);
        }
    }
    return pos;
}//Validador leer arreglo
