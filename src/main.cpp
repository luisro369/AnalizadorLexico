#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "headers/CodeReader.h"
#include "headers/analizador_lexicografico/lexicoGrafico.h"
#include "headers/parcer/AnalizadorSintactico.h"

using namespace std;

int main (void){

  //generar el vector con los strings de cada palabra para ser analizados
  vector<string> vectorPalabras,vectorPalabrasAnalizadas;
  vectorPalabras = CodeReader("./data/code.txt");
  vectorPalabrasAnalizadas = AnalizadorLexicoGrafico(vectorPalabras);
  
  //for de prueba borrar todo esto
  cout<<"====================PALABRAS ANALIZADAS============ \n";
  for(int i =0; i< vectorPalabrasAnalizadas.size(); i++){
    cout<<vectorPalabrasAnalizadas[i]<<"\n";
  }//for de prueba borrar
  
  AnalizadorSintactico(vectorPalabrasAnalizadas);
  return 0;
}//main
