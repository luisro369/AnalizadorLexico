#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//archivos necesarios
//#include "EvaluarVariable.h"
//#include "EvaluarAsignacion.h"
//#include "EvaluarTipoValor.h"
using namespace std;


//funcion que obtiene el token
int obtenerTokens(vector<string> vectorPalabras,int posicion,vector<string> Lexico){
    //se recorre el arreglo de tokens hasta encontrar el correspondiente
  for(int i = 0; i <= Lexico.size(); i++){
        if(vectorPalabras[posicion] == Lexico[i]){
            //se retorna la posicion del token
            return i;
        }
    } 
    return 0;
}//obtener tokens


/*
//funcion que manejara el flujo
int bloque(vector<string> algo,int token,int posicion){
    //verifica si el token esta entre 1 y 5 porque son las de los tipo de datos
    if(token == 1 || token == 2 || token == 3 || token == 4 || token == 5){
        //se avanza el carro
        posicion = posicion+1;
        //si es un identificador de tipo de datos por consecuencia sigue una variable asi que la valida
        evaluarVariable(algo[posicion]);
        posicion = posicion+1;
        evaluarAsignar(algo[posicion]);
        posicion = posicion+1;
        evaluarValor(algo[posicion],token);
    }
    //se retorna la nueva posicion de lectura
    return posicion;
}//bloque
*/

