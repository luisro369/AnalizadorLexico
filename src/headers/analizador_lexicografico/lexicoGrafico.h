#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "Lexico.h"
#include "manejadorTokens.h"

//funcion que valida si la variable es solo de letras
bool checkAlpha(string str){
    bool retVal;
    for(int i = 0; i < str.size(); i++){
        if(isalpha(str[i]) == 0){
            //retorna true si encontro algo que no es letra
            retVal = true;
            break;
        }
        else{
            //todo bien
            retVal = false;
        }
    }
    return retVal;
}//checkAlpha

bool checkNumeric(string str){
    bool retVal;
    for(int i = 0; i < str.size()-1; i++){
        if(isdigit(str[i]) == 0){
            //retorna true si encontro algo que no es numero
            retVal = true;
            break;
        }
        else{
            //todo bien
            retVal = false;
        }
    }
    return retVal;
}//checkNumeric

bool isDecimal(string str){
    bool retVal;
    int punto = 0;
    for(int i = 0; i < str.size()-1; i++){
        if(str[i] == '.'){
            punto = punto + 1;
            i = i + 1;
        }
        if(isdigit(str[i]) == 0){
            //retorna true si encontro algo que no es numero
            retVal = true;
            break;
        }
        else{
            //todo bien
            retVal = false;
        }
        if(punto == 2){
            retVal = true;
            break;
        }
    }
    return retVal;
}//checkNumeric

vector<string> analizadorVariablesDatos(vector<string> algoAnalizado, string lexema){
    if(lexema.length() == 3 && lexema.substr(0,1) == "'" && lexema.substr(2,2) == "'" && !(checkAlpha(lexema.substr(1,1)))){
        cout<<lexema<<" -----------> "<<" LET "<<"\n";
        algoAnalizado.push_back("LET");
    }else{
        if(lexema == "VERDADERO" || lexema == "FALSO"){
            cout<<lexema<<" -----------> "<<" LOG "<<"\n";
            algoAnalizado.push_back("LOG");
        }else{
            if(lexema.length() <= 15 && lexema.substr(0,1) != "'" && lexema.substr(0,1) != "\"" && lexema.substr(lexema.length()-1,lexema.length()-1) != "'" &&
                 lexema.substr(lexema.length()-1,lexema.length()-1) != "\"" && !(checkAlpha(lexema))){
                 cout<<lexema<<" -----------> "<<" VAR "<<"\n";
                 algoAnalizado.push_back("VAR");
            }else{
                if(lexema.length() <= 4 && !(checkNumeric(lexema))){
                    cout<<lexema<<" -----------> "<<" NUM "<<"\n";
                    algoAnalizado.push_back("NUM");
                }else{
                    if(lexema.length() >= 3 && lexema.substr(0,1) == "\"" && lexema.substr(lexema.length()-1,lexema.length()-1) == "\"" && !checkAlpha(lexema.substr(1,lexema.length()-2))){
                        cout<<lexema<<" -----------> "<<" PAL "<<"\n";
                        algoAnalizado.push_back("PAL");
                    }else{
                        if(lexema.length() <= 9 && !(isDecimal(lexema))){
                             cout<<lexema<<" -----------> "<<" DEC "<<"\n";
                             algoAnalizado.push_back("DEC");
                        }else{
                            cout<<lexema<<" -----------> "<<" lexema "<<"\n";
                            algoAnalizado.push_back("lexema");
                        }
                    }
                }
            }
        }
    }
    return algoAnalizado;    
}

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
      algoAnalizado = analizadorVariablesDatos(algoAnalizado,algo[i]);  
    }//else
  }//for
  
  return algoAnalizado;
}//AnalizadorLexicoGrafico
