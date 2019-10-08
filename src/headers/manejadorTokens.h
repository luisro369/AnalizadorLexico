#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//archivos necesarios
#include "EvaluarVariable.h"
#include "EvaluarAsignacion.h"
#include "EvaluarTipoValor.h"
using namespace std;

int bloque(vector<string> algo,int token,int posicion);

//funcion que obtiene el token
int obtenerTokens(vector<string> algo,int posicion){
    //se recorre el arreglo de tokens hasta encontrar el correspondiente
    for(int i = 0; i <= 32; i++){
        if(algo[posicion] == TOKENS[i]){
            cout<<TOKENST[i]<<"\n";
            return i;
        }
    } 
    return 0;
}//obtener tokens

void evaluarFinLinea(string variable){
    //validacion del caracter de asignación
    if(variable != ";"){
      cout<<"Error en la validacion de finalizacion de linea\n debe ser ;\n";
      //mata el programa
      exit(0);
    }
    cout<<variable<<"  -------------------fin de linea\n";    
}//evaluarAsignar

void evaluarParentesisInicio(string variable){
    //validacion del caracter de asignación
    if(variable != "("){
      cout<<"Error en la validacion de inicion de condicion debe ser (\n";
      //mata el programa
      exit(0);
    }
    cout<<variable<<"  -------------------inicio de condicion\n";    
}//evaluarAsignar

void evaluarParentesisFinal(string variable){
    //validacion del caracter de asignación
    if(variable != ")"){
      cout<<"Error en la validacion de final de condicion debe ser )\n";
      //mata el programa
      exit(0);
    }
    cout<<variable<<"  -------------------final de condicion\n";    
}//evaluarAsignar

void evaluarInicioDeBloque(string variable){
    //validacion del caracter de asignación
    if(variable != "{"){
      cout<<"Error en la validacion de inicio de bloque debe ser {\n";
      //mata el programa
      exit(0);
    }
    cout<<variable<<"  -------------------inicio de bloque\n";    
}//evaluarAsignar

void evaluarFinDeBloque(string variable){
    //validacion del caracter de asignación
    if(variable != "}"){
      cout<<"Error en la validacion de fin de bloque debe ser }\n";
      //mata el programa
      exit(0);
    }
    cout<<variable<<"  -------------------fin de bloque\n";    
}//evaluarAsignar

void evaluarCondicion(string variable){
    //validacion del caracter de asignación
    if(variable != "<" && variable != ">" && variable != "<=" && variable != ">=" && variable != "=="){
      cout<<"Error en la validacion de condicionales solo estan aceptadas ( '<' , '>' , '<=' , '=>' , '==')\n";
      //mata el programa
      exit(0);
    }
    cout<<variable<<"  -------------------condicion valida\n";    
}//evaluarAsignar

int nuevoBloque(vector<string> algo,int posicion){
    int tokenTemp;
    for(int i=posicion; i < algo.size() ; i++){
    if(algo[i] == "}"){
        return i;
    }
    if(find(TOKENS.begin(), TOKENS.end(), algo[i]) != TOKENS.end()){
      cout<<algo[i]<<"  ----------------->";
      //funcion en manejador que obtiene el token correspondiente  
      tokenTemp = obtenerTokens(algo,i);
      //funcion que avanza el carro una posicion y se encarga de validar variables
      i = bloque(algo,tokenTemp,i);
    }//if
    else{
        cout<<algo[i]<<"\n";
    }//else
  }//for
}



//funcion que manejara el flujo
int bloque(vector<string> algo,int token,int posicion){
    //verifica si el token esta entre 1 y 5 porque son las de los tipo de datos
    if(token == 1 || token == 2 || token == 3 || token == 4 || token == 5){
        //se avanza el carro
        posicion = posicion+1;
        //si es un identificador de tipo de datos por consecuencia sigue una variable asi que la valida
        evaluarVariable(algo[posicion]);
        //se avanza el carro
        posicion = posicion+1;
        evaluarAsignar(algo[posicion]);
        //se avanza el carro
        posicion = posicion+1;
        evaluarValor(algo[posicion],token);
        //se avanza el carro
        posicion = posicion+1;
        evaluarFinLinea(algo[posicion]);
    }
    if(token == 6 || token == 7){
        //se avanza el carro
        posicion = posicion+1;
        evaluarParentesisInicio(algo[posicion]);
        //se avanza el carro
        posicion = posicion+1;
        //si es un identificador de tipo de datos por consecuencia sigue una variable asi que la valida
        evaluarVariable(algo[posicion]);
        //se avanza el carro
        posicion = posicion+1;
        evaluarCondicion(algo[posicion]);
        posicion = posicion+1;
        //si es un identificador de tipo de datos por consecuencia sigue una variable asi que la valida
        evaluarVariable(algo[posicion]);
        //se avanza el carro
        posicion = posicion+1;
        evaluarParentesisFinal(algo[posicion]);
        posicion = posicion+1;
        evaluarInicioDeBloque(algo[posicion]);
        posicion = posicion+1;
        posicion = nuevoBloque(algo,posicion);
        evaluarFinDeBloque(algo[posicion]);
    }
    if(token == 22){
        cout<<"=======================GRACIAS POR USAR AGORA==============================\n";
    }
    //se retorna la nueva posicion de lectura
    return posicion;
}//bloque


