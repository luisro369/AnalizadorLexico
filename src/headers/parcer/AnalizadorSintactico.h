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
//#include "../../headers/CodeReader.h"


int validadorProceso(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[13]){
         //Indicador de repetidor
        cout<<"INDICADOR INICIO DE PROCESO-----------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                        //cout<<ERRORES[3];
                        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[3];
                        exit(0);
                        }
                    }else{
                    //se muere
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<"ERROR: se esperaba simbolo de fin de parametro ')'\n";
                    exit(0);
                    }
                }else{
                //se muere
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<"ERROR: se esperaba parametro\n";
                exit(0);
                }
            }else{
            //se muere
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<"ERROR: se esperaba simbolo de inicio de parametro '('\n";
            exit(0);
            }
        }else{
         //se muere
        cout<<"En linea: "<<est.VectorLineas[posTemp]<<"ERROR: se esperaba nombre para el proceso\n";
        exit(0);
        }
    }
    return pos;
}



//funcion que manejara el flujo
void AnalizadorSintactico(vector<string> vectorPalabrasAnalizadas){
  cout<<"=========================ANALIZADOR SINTACTICO========================\n";
  validadorInicioFin(vectorPalabrasAnalizadas,0);//s
  //for para recorrer el vector de tokens y lexemas analizados
  for(int pos=1; pos<vectorPalabrasAnalizadas.size()-2;pos++){
    pos = validadorAsignacion(vectorPalabrasAnalizadas,pos);//s
    pos = validadorCondicional(vectorPalabrasAnalizadas,pos);//s
    pos = validadorRepetidor(vectorPalabrasAnalizadas,pos);//s
    pos = validadorLectura(vectorPalabrasAnalizadas,pos);//s
    pos = validadorEscritura(vectorPalabrasAnalizadas,pos);//s
    pos = validadorManejoArchivos(vectorPalabrasAnalizadas,pos);//s
    pos = validadorProceso(vectorPalabrasAnalizadas,pos);//s
    pos = validadorFuncion(vectorPalabrasAnalizadas,pos);//s
    pos = validadorDefArreglo(vectorPalabrasAnalizadas,pos);//s
    pos = validadorDimArreglo(vectorPalabrasAnalizadas,pos);//s
    pos = validadorIngArreglo(vectorPalabrasAnalizadas,pos);//s
    pos = validadorLeerArreglo(vectorPalabrasAnalizadas,pos);//s    
  }
  cout<<"=========================GRACIAS POR USAR AGORA=======================\n";
}//Analizador sintactico
