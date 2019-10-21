#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;
// archivos necesarios
#include "StringAnalyzer.h"
//#include "analizador_lexicografico/Lexico.h"
/*
Con esta funcion soy capaz de leer archivos .txt
- Transformalos a un vector de palabras linea por linea con la funcion Separar
*/


vector<string> CodeReader(string File){
  vector<string> VectorDePalabras;
  //stringstream stringStream(File);
  ifstream file(File);
  string line;
  if(file.is_open()){
    while(getline(file, line)) {
      size_t prev = 0, pos;
      while ((pos = line.find_first_of(" := ;", prev)) != std::string::npos){//<=aca le digo que mierdas no quiero que lea
        if (pos > prev){
          VectorDePalabras.push_back(line.substr(prev, pos-prev));
        }//if
        prev = pos+1;
      }//while
      if (prev < line.length()){
        VectorDePalabras.push_back(line.substr(prev, std::string::npos));
      }//if
    }//while
    return VectorDePalabras;
  }//if
  else{
    file.close();
    VectorDePalabras.push_back("archivo no encontrado");
    return VectorDePalabras;
  }
}//CodeReader


/*
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


/*
//Funcion original
vector<string> CodeReader(string File){
  //declarando el vector de caracteres especiales del lenguaje
  vector<char> ESPchar = {'{','}','[',']','>','<','(',')',';',',','='};
  //variables
  vector<string> VectorDePalabras;
  vector<string> vectorDeArchivo;
  
  ifstream file(File);
  
  if (file.is_open()) {
    string line,palabra;
    while (getline(file, line)) {
      //VectorDePalabras.push_back((Separar( line.c_str(), ' ')));
      vectorDeArchivo = (Separar(line.c_str(), ' ' ));
      //cout<< line<<"\n";
      //vectorDeArchivo.push_back( getline(line, palabra, (ESPchar.begin(), ESPchar.end())) );
      VectorDePalabras.insert(end(VectorDePalabras),begin(vectorDeArchivo), end(vectorDeArchivo));
    }
    file.close();
    return VectorDePalabras;
  }
  else{
    vector<string> error;
    error.push_back("Archivo no encontrado");
    return error;
  }
}//CodeReader

*/
