#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "Lexico.h"
#include "manejadorTokens.h"

vector<string> AnalizadorLexicoGrafico(vector<string> algo){
  vector<string> algoAnalizado;
  int posTok,posAritm,posEsp,posLex;
  //recorriendo vector del archivo .txt y viendo si son iguales
  for(int i= 0; i < algo.size() ; i++){
    //si el valor pertenece a un token
    if(find(TOKENS.begin(), TOKENS.end(), algo[i]) != TOKENS.end()){
      posTok = obtenerTokens(algo,i,TOKENS);
      cout<<algo[i]<<" -----------> "<<TOKENST[posTok]<<"\n";
      algoAnalizado.push_back(TOKENST[posTok]);
      continue;
    }//if
    //si el valor pertenece a un caracter aritmetico
    if(find(ARITM.begin(), ARITM.end(), algo[i]) != ARITM.end()){
      posAritm = obtenerTokens(algo,i,ARITM);
      cout<<algo[i]<<" -----------> "<<ARITMT[posAritm]<<"\n";
      algoAnalizado.push_back(ARITMT[posAritm]);
      continue;
    }//if
    //si el valor pertenece a un caracter especial
    if(find(ESP.begin(), ESP.end(), algo[i]) != ESP.end()){
      posEsp = obtenerTokens(algo,i,ESP);
      cout<<algo[i]<<" -----------> "<<ESPT[posEsp]<<"\n";
      algoAnalizado.push_back(ESPT[posEsp]);
      continue;
    }//if
    else{
      cout<<algo[i]<<" -----------> "<<" lexema "<<"\n";
      algoAnalizado.push_back("lexema");
    }//else
  }//for
  
  return algoAnalizado;
}//AnalizadorLexicoGrafico
