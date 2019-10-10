#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "Lexico.h"
#include "manejadorTokens.h"

void AnalizadorLexicoGrafico(vector<string> algo){
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
}//AnalizadorLexicoGrafico
