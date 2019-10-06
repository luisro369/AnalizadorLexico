#include <iostream>
#include <string>
#include <vector>


#include <algorithm>
//archivos necesarios
#include "Lexico.h"
#include "CodeReader.h"

using namespace std;

int main (void){

  //generar el vector con los strings de cada palabra para ser analizados
  vector<string> algo;
  algo = CodeReader("code.txt");
  //recorriendo vector del archivo .txt y viendo si son iguales
  for(int i= 0; i < algo.size() ; i++){
    if(find(TOKENS.begin(), TOKENS.end(), algo[i]) != TOKENS.end()){
      cout<<"este elemento pertenece ";
    }//if
    cout<<algo[i]<<"\n";
  }//for
  
  return 0;
}
