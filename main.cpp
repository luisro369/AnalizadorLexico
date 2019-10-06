#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//archivos necesarios
#include "StringAnalyzer.h"

using namespace std;

int main (void){
  std::ifstream file("code.txt");
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
        vector<string> x = Separar( line.c_str(), ' ');
        for(int i=0; i<x.size() ; i++){
  			cout<<x[i]<<"\n";
  		}
    }
    file.close();
  }else{
  	cout<<"archivo no encontrado";
  }
  return 0;
}
