#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//archivos necesarios

#include "CodeReader.h"

using namespace std;

int main (void){

  vector<string> algo;
  algo = CodeReader("code.txt");
  
  for(int i= 0; i < algo.size() ; i++){
    cout<<algo[i]<<"\n";
  }//for
  
  return 0;
}
