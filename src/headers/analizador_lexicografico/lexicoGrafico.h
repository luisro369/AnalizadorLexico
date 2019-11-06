#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "Lexico.h"
#include "manejadorTokens.h"
#include "Errores.h"

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

vector<string> analizadorVariablesDatos(vector<string> vectorPalabrasAnalizadas, string lexema){
    if(lexema.length() == 3 && lexema.substr(0,1) == "'" && lexema.substr(2,2) == "'" && !(checkAlpha(lexema.substr(1,1)))){
        cout<<lexema<<" -----------> "<<" LET "<<"\n";
        vectorPalabrasAnalizadas.push_back("LET");
    }else{
        if(lexema == "VERDADERO" || lexema == "FALSO"){
            cout<<lexema<<" -----------> "<<" LOG "<<"\n";
            vectorPalabrasAnalizadas.push_back("LOG");
        }else{
            if(lexema.length() <= 15 && lexema.substr(0,1) != "'" && lexema.substr(0,1) != "\"" && lexema.substr(lexema.length()-1,lexema.length()-1) != "'" &&
                 lexema.substr(lexema.length()-1,lexema.length()-1) != "\"" && !(checkAlpha(lexema))){
                 cout<<lexema<<" -----------> "<<" VAR "<<"\n";
                 vectorPalabrasAnalizadas.push_back("VAR");
            }else{
                if(lexema.length() <= 4 && !(checkNumeric(lexema))){
                    cout<<lexema<<" -----------> "<<" NUM "<<"\n";
                    vectorPalabrasAnalizadas.push_back("NUM");
                }else{
                    if(lexema.length() >= 3 && lexema.substr(0,1) == "\"" && lexema.substr(lexema.length()-1,lexema.length()-1) == "\"" && !checkAlpha(lexema.substr(1,lexema.length()-2))){
                        cout<<lexema<<" -----------> "<<" PAL "<<"\n";
                        vectorPalabrasAnalizadas.push_back("PAL");
                    }else{
                        if(lexema.length() <= 9 && !(isDecimal(lexema))){
                             cout<<lexema<<" -----------> "<<" DEC "<<"\n";
                             vectorPalabrasAnalizadas.push_back("DEC");
                        }else{
                            cout<<lexema<<" -----------> "<<" lexema "<<"\n";
                            vectorPalabrasAnalizadas.push_back("lexema");
                        }
                    }
                }
            }
        }
    }
    return vectorPalabrasAnalizadas;    
}

vector<string> AnalizadorLexicoGrafico(vector<string> vectorPalabras){
  vector<string> vectorPalabrasAnalizadas;
  int posTok,posAritm,posEsp,posLex;
  //recorriendo vector del archivo .txt y viendo si son iguales
  for(int i= 0; i < vectorPalabras.size() ; i++){
    //si el valor pertenece a un token
    if(find(TOKENS.begin(), TOKENS.end(), vectorPalabras[i]) != TOKENS.end()){
      posTok = obtenerTokens(vectorPalabras,i,TOKENS);
      cout<<vectorPalabras[i]<<" -----------> "<<TOKENST[posTok]<<"\n";
      vectorPalabrasAnalizadas.push_back(TOKENST[posTok]);
      continue;
    }//if
    //si el valor pertenece a un caracter aritmetico
    if(find(ARITM.begin(), ARITM.end(), vectorPalabras[i]) != ARITM.end()){
      posAritm = obtenerTokens(vectorPalabras,i,ARITM);
      cout<<vectorPalabras[i]<<" -----------> "<<ARITMT[posAritm]<<"\n";
      vectorPalabrasAnalizadas.push_back(ARITMT[posAritm]);
      continue;
    }//if
    //si el valor pertenece a un caracter especial
    if(find(ESP.begin(), ESP.end(), vectorPalabras[i]) != ESP.end()){
      posEsp = obtenerTokens(vectorPalabras,i,ESP);
      cout<<vectorPalabras[i]<<" -----------> "<<ESPT[posEsp]<<"\n";
      vectorPalabrasAnalizadas.push_back(ESPT[posEsp]);
      continue;
    }//if
    else{
      vectorPalabrasAnalizadas = analizadorVariablesDatos(vectorPalabrasAnalizadas,vectorPalabras[i]);  
    }//else
  }//for
  
  return vectorPalabrasAnalizadas;
}//AnalizadorLexicoGrafico
