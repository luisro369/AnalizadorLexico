#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;
// archivos necesarios


/*
Con esta funcion soy capaz de leer archivos .txt
- Transformalos a un vector de palabras linea por linea con la funcion Separar
*/

vector<string> CodeReader(string File){
  vector<string> VectorDePalabras;
  const char *tokensEsp = "%^*-+/:={}[]><==()/##\\;,&&||'";//<---valores a comparar
  fstream file;
  int posCaracter = 0;
  string palabra,palabraDosPuntos;
  
  file.open(File.c_str());
  while(file >> palabra){
    posCaracter = palabra.find_first_of(tokensEsp);//<--Asigno a posCaracter el lugar en donde encuentra el tokenEsp
        
    if(posCaracter >= 0){//<-----si encuentra el token en la palabra
    size_t prev = 0, pos;
    while ((pos = palabra.find_first_of(tokensEsp, prev)) != std::string::npos){//<=recorre la palabra separando lexemas de los token espeaciales
 
      if( (pos-prev) > 0){//<----cuando no sea vacia (correccion de bug que habia)
        VectorDePalabras.push_back(palabra.substr(prev,pos-prev));//<--agrego lexemas
      }//if
      
      palabraDosPuntos.push_back(palabra[pos]);
      if( strcmp(palabraDosPuntos.c_str(),":") == 0 ){//<-- si es el token de asignacion
        VectorDePalabras.push_back(palabra.substr(pos,2));
        pos = pos +1;
      }//if
      else{//<--- si es otro token perteneciente a tokenEsp
        VectorDePalabras.push_back(palabra.substr(pos,1));
      }//else
      
      prev = pos+1;
      palabraDosPuntos = "";
    }//while    
  }//if
  
  else{VectorDePalabras.push_back(palabra);}//<--- si la palabra es token
  
  }//while
  file.close();
  return VectorDePalabras;
}//nuevo metodo


/*por si acaso USAR ESTA, esta requiere que todo este dividido por espacios
//funcion mejorada (ya no necesita de el archivo StringAnalyzer por ende es mas eficiente)
vector<string> CodeReader(string File){
  vector<string> VectorDePalabras;
  fstream file;
  string palabra;
  file.open(File.c_str());
  while(file >> palabra){
    cout<<palabra<<endl;
    VectorDePalabras.push_back(palabra);
    
  }//while
  file.close();
  return VectorDePalabras;
}//nuevo metodo
*/

