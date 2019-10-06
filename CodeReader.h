#include<iostream>
#include <vector>
#include <fstream>

using namespace std;
// archivos necesarios
#include "StringAnalyzer.h"

//Lee archivos desde un .txt
vector<string> CodeReader(string File){
  vector<string> vectorDeArchivo;
  //variables
  vector<string> VectorDePalabras;
  int i = 0;
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
    vector<string> error = {"archivo no encontrado"};
    return error;
  }
}//CodeReader

