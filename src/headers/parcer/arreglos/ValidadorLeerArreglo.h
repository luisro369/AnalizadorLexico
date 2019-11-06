#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorLeerArreglo(vector<string> VSin, int pos){
   if(VSin[pos] == TOKENST[19]){
         //Indicador de lectura de arreglo
        cout<<"INDICADOR LECTRUA DE ARREGLO----------------SINTACTICO\n";
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
                    cout<<ERRORES[9];
                    exit(0);
                }
            }else{
                //se muere
                cout<<ERRORES[24];
                exit(0);
            }   
        }else{
            //se muere
            cout<<ERRORES[21];
            exit(0);
        }
    }
    return pos;
}//Validador leer arreglo
