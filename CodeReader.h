#include<iostream>
#include <vector>
#include <fstream>

using namespace std;
// archivos necesarios
#include "StringAnalyzer.h"

/*
Con esta funcion soy capaz de leer archivos .txt
- Transformalos a un vector de palabras linea por linea con la funcion Separar
*/

vector<string> CodeReader(string File){
  //variables
  vector<string> VectorDePalabras;
  vector<string> vectorDeArchivo;
  
  ifstream file(File);
  
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      //VectorDePalabras.push_back((Separar( line.c_str(), ' ')));
      vectorDeArchivo = (Separar(line.c_str(), ' '));
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

