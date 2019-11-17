#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>


using namespace std;
// archivos necesarios

//=================Estructura para poder llevar track de las lineas=========
struct vectorLineas {
  std::vector<int> VectorLineas;
  std::vector<int> VectorPos;
  //--metodo de conversion de vector de palabras analizadas al vector de posiciones (sirve para conseguir la linea del error)
  int conversion(int posAnalizado){
    int j = 0;
    for(int i=0; i<VectorPos.size(); i++){
      if(VectorPos[i] <= posAnalizado){
        j = i+1;
      }//if
    }//for
    return j;
  }//conversion
}est;

/*
Con esta funcion soy capaz de leer archivos .txt
- Transformalos a un vector de palabras linea por linea con la funcion Separar
*/

vector<string> CodeReader(string File){
  vector<string> VectorDePalabras;
  const char *tokensEsp = "%^*-+:=/{}[]'><()##\\;,&&||";//<---valores a comparar
  fstream file;
  int posCaracter = 0,linea = 0;
  string palabra,palabraCompuesta,palabraINICIOFIN;
  
  file.open(File.c_str());
  while(file >> palabra){
    posCaracter = palabra.find_first_of(tokensEsp);//<--Asigno a posCaracter el lugar en donde encuentra el tokenEsp
        
    if(posCaracter >= 0){//<-----si encuentra el token en la palabra
    size_t prev = 0, pos;
    while ((pos = palabra.find_first_of(tokensEsp, prev)) != std::string::npos){//<=recorre la palabra separando lexemas de los token espeaciales
 
      if( (pos-prev) > 0){//<----cuando no sea vacia (correccion de bug que habia)
        VectorDePalabras.push_back(palabra.substr(prev,pos-prev));//<--agrego lexemas
      }//if
      //==================asignacion=================
      palabraCompuesta.push_back(palabra[pos]);
      if( strcmp(palabraCompuesta.c_str(),":") == 0 ){//<-- si es el token de asignacion
        VectorDePalabras.push_back(palabra.substr(pos,2));
        pos = pos +1;
      }//if
      //=============slash==================
      else if( strcmp(palabraCompuesta.c_str(),"/") == 0 ) {
        palabraCompuesta = "";
        palabraCompuesta.push_back(palabra[pos+1]);
        if( strcmp(palabraCompuesta.c_str(),"#") == 0 ){
          VectorDePalabras.push_back(palabra.substr(pos,2));
          pos = pos +1;
        }
        else{VectorDePalabras.push_back(palabra.substr(pos,1));}
      }//elseif slash
      //=================hashtag========================
      else if( strcmp(palabraCompuesta.c_str(),"#") == 0 ){//<-- si es el token de asignacion
        palabraCompuesta = "";
        palabraCompuesta.push_back(palabra[pos+1]);
        if( strcmp(palabraCompuesta.c_str(),"\\") == 0 ){
          VectorDePalabras.push_back(palabra.substr(pos,2));
          pos = pos +1;
        }//if
      }//elseif
      //================token normal============
      else{//<--- si es otro token perteneciente a tokenEsp
        VectorDePalabras.push_back(palabra.substr(pos,1));
      }//else
      
      prev = pos+1;
      palabraCompuesta = "";
    }//while
    //--------------------estructura vectores de linea------------------
    linea += 1;
    int n = VectorDePalabras.size();
    est.VectorPos.push_back(n-1);//ingreso la posicion del ultimo token de la linea (sirve para tener track de el)
    est.VectorLineas.push_back(linea);
    }//if


    
    //==========================Token normal==========
    else{
      VectorDePalabras.push_back(palabra);
      //--------------------------estructura vectores de linea-------------
      int m = VectorDePalabras.size();
      palabraINICIOFIN = VectorDePalabras[m-1];
      if(strcmp(palabraINICIOFIN.c_str(),"INICIO") == 0){
        linea += 1;
        est.VectorPos.push_back(m-1);//ingreso la posicion del ultimo token de la linea (sirve para tener track de el)
        est.VectorLineas.push_back(linea);
      }
      if(strcmp(palabraINICIOFIN.c_str(),"FINCODIGO") == 0){
        linea += 1;
        est.VectorPos.push_back(m-1);//ingreso la posicion del ultimo token de la linea (sirve para tener track de el)
        est.VectorLineas.push_back(linea);
      }
    }//<--- si la palabra es token
    
  }//while
  file.close();
  return VectorDePalabras;
}//nuevo metodo



/*//============METODO DE EMERGENCIA PERRO====================
vector<string> CodeReader(string File){
  vector<string> VectorDePalabras;
  int linea = 0;
  string line;
  ifstream fin;
  fin.open(File);
  if(fin.is_open()){
    while ( getline ( fin, line )){
      stringstream ss(line);
      
      while ( getline (ss ,line, ' ')){
        VectorDePalabras.push_back(line);
      }//while
      if(line.length() == 0){
        linea += 0;
      }
      else{
        linea += 1;
        int n = VectorDePalabras.size();
        est.VectorPos.push_back(n-1);//ingreso la posicion del ultimo token de la linea (sirve para tener track de el)
        est.VectorLineas.push_back(linea);
      }
    }//while
    return VectorDePalabras;
  }//if
  
  else{
    return VectorDePalabras;
  }
}//VECTORSTRING
*/
