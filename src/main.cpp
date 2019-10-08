#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "headers/Lexico.h"
#include "headers/CodeReader.h"
#include "headers/manejadorTokens.h"

using namespace std;

int main (void){

  //generar el vector con los strings de cada palabra para ser analizados
  vector<string> algo;
  algo = CodeReader("./data/code.txt");
  int tokenTemp;
  //recorriendo vector del archivo .txt y viendo si son iguales
  for(int i= 0; i < algo.size() ; i++){
    //si el valor pertenece a un token
    if(find(TOKENS.begin(), TOKENS.end(), algo[i]) != TOKENS.end()){
      cout<<algo[i]<<" -----------> "<<TOKENST[obtenerTokens(algo,i,TOKENS)]<<"\n";
      continue;
    }//if
    //si el valor pertenece a un caracter aritmetico
    if(find(ARITM.begin(), ARITM.end(), algo[i]) != ARITM.end()){
      cout<<algo[i]<<" -----------> "<<ARITMT[obtenerTokens(algo,i,ARITM)]<<"\n";
      continue;
    }//if
    //si el valor pertenece a un caracter especial
    if(find(ESP.begin(), ESP.end(), algo[i]) != ESP.end()){
      cout<<algo[i]<<" -----------> "<<ESPT[obtenerTokens(algo,i,ESP)]<<"\n";
      continue;
    }//if
    else{
      cout<<algo[i]<<" -----------> "<<" lexema "<<"\n";
    }//else
  }//for
  
  return 0;
}

/*   esto es mas para el sintactico
      //funcion en manejador que obtiene el token correspondiente  
      tokenTemp = obtenerTokens(algo,i);
      //funcion que avanza el carro una posicion y se encarga de validar variables
      i = bloque(algo,tokenTemp,i);
      }//if
    else{
    cout<<algo[i]<<"\n";
    }//else*/
