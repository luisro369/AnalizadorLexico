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
    if(find(TOKENS.begin(), TOKENS.end(), algo[i]) != TOKENS.end()){
      cout<<"este elemento pertenece "<<algo[i]<<"\n";
      //funcion en manejador que obtiene el token correspondiente  
      tokenTemp = obtenerTokens(algo,i);
      //funcion que avanza el carro una posicion y se encarga de validadr variables
      i = bloque(algo,tokenTemp,i);
    }//if
    else{
        cout<<algo[i]<<"\n";
    }//else
  }//for
  
  return 0;
}
