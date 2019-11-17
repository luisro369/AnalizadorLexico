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
  //analizar en que linea va el codigo,
  
  
  //for de prueba borrar todo esto
  cout<<"====================PALABRAS ANALIZADAS==================== \n";
  for(int i =0; i< vectorPalabrasAnalizadas.size(); i++){
    cout<<vectorPalabrasAnalizadas[i]<<"\n";
  }//for de prueba borrar

  /*
  cout<<"====================LINEAS============ \n";
  int i = 0;
  while(i < est.VectorLineas.size()){
    cout<<"pos: "<<est.VectorPos[i]<<" lex: "<<vectorPalabras[est.VectorPos[i]]<<" linea---> "<<est.VectorLineas[i]<<endl;
    i += 1;
  }//while
  */
  
  AnalizadorSintactico(vectorPalabrasAnalizadas);

  cout<<"====================VARIABBLES ALMACENADAS=================\n";
  cout<<"Variables Almacenadas: "<<VARIABLES.size()<<"\n";

  for(int i=0; i< VARIABLES.size(); i++){
  	cout<<VARIABLES[i].nombre<<" <----nombre "<<VARIABLES[i].tipo<<" <----tipo "<<VARIABLES[i].valor<<" <----valor\n";
  }
  cout<<"=================GRACIAS POR USAR AGORA====================\n";
  return 0;
}//main
