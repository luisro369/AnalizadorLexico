#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios
#include "ValidadorInicioFin.h"
#include "ValidadorAsignacion.h"
#include "ValidadorCondicional.h"
#include "ValidadorRepetidor.h"
#include "entrada_salida/ValidadorLectura.h"
#include "entrada_salida/ValidadorEscritura.h"
#include "ValidadorManejadorArchivos.h"
#include "ValidadorFuncion.h"
#include "arreglos/ValidadorDefinicionArreglo.h"
#include "arreglos/ValidadorDimensionArreglo.h"
#include "arreglos/ValidadorIngresoArreglo.h"
#include "arreglos/ValidadorLeerArreglo.h"


int validadorProceso(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[13]){
         //Indicador de repetidor
        cout<<"INDICADOR INICIO DE PROCESO-----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "VAR"){
            //todo bien
            cout<<"NOMBRE DE PROCESO---------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == ESPT[7]){
                //todobien
                cout<<"PARENTESIS QUE INDICA INICIO DE PARAMETRO---SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == "VAR"){
                    //todo bien
                    cout<<"PARAMETRO DE PROCESO------------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[8]){
                        //todobien
                        cout<<"PARENTESIS QUE INDICA FIN DE PARAMETRO------SINTACTICO\n";
                        pos = pos+1;
                        if(VSin[pos] == ESPT[0]){
                            //todobien
                            cout<<"CORCHETE  QUE INDICA INICIO DE CODIGO-------SINTACTICO\n";
                            pos = pos+1;
                            while(VSin[pos] != ESPT[1]){
                                cout<<"CODIGO DE PROCESO---------------------------SINTACTICO\n";   
                                pos = pos+1;                                  
                            }
                            cout<<"CORCHETE QUE INDICA FIN DE CODIGO-----------SINTACTICO\n";
                        }else{
                        //se muere
                        cout<<ERRORES[3];
                        exit(0);
                        }
                    }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de parametro ')'\n";
                    exit(0);
                    }
                }else{
                //se muere
                cout<<"ERROR: se esperaba parametro\n";
                exit(0);
                }
            }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de inicio de parametro '('\n";
            exit(0);
            }
        }else{
         //se muere
        cout<<"ERROR: se esperaba nombre para el proceso\n";
        exit(0);
        }
    }
    return pos;
}



//funcion que manejara el flujo
void AnalizadorSintactico(vector<string> vectorPalabrasAnalizadas){
  cout<<"=========================ANALIZADOR SINTACTICO========================\n";
  validadorInicioFin(vectorPalabrasAnalizadas);//
  //for para recorrer el vector de tokens y lexemas analizados
  for(int pos=1; pos<vectorPalabrasAnalizadas.size()-2;pos++){
    pos = validadorAsignacion(vectorPalabrasAnalizadas,pos);//
    pos = validadorCondicional(vectorPalabrasAnalizadas,pos);//
    pos = validadorRepetidor(vectorPalabrasAnalizadas,pos);//
    pos = validadorLectura(vectorPalabrasAnalizadas,pos);//
    pos = validadorEscritura(vectorPalabrasAnalizadas,pos);//
    pos = validadorManejoArchivos(vectorPalabrasAnalizadas,pos);//
    pos = validadorProceso(vectorPalabrasAnalizadas,pos);//
    pos = validadorFuncion(vectorPalabrasAnalizadas,pos);//
    pos = validadorDefArreglo(vectorPalabrasAnalizadas,pos);//
    pos = validadorDimArreglo(vectorPalabrasAnalizadas,pos);//
    pos = validadorIngArreglo(vectorPalabrasAnalizadas,pos);//
    pos = validadorLeerArreglo(vectorPalabrasAnalizadas,pos);//    
  }
  cout<<"=========================GRACIAS POR USAR AGORA=======================\n";
}//Analizador sintactico
