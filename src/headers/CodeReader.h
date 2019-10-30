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

/*
vector<string> CodeReader(string File){
  vector<string> VectorDePalabras;
  const char *tokensEsp = " %^*-+/:={}[]><==()/##\\;,&&||'";
  ifstream file(File);
  string line;
 
  if(file.is_open()){
    while(getline(file, line)) {
      
      size_t prev = 0, pos;
      while ((pos = line.find_first_of(tokensEsp, prev)) != std::string::npos){//<=aca le digo que no quiero que lea
        if (pos > prev){
          VectorDePalabras.push_back(line.substr(prev, pos-prev));
          VectorDePalabras.push_back(line.substr(pos, 1));
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
  }//else
  
}//CodeReader
*/


//funcion mejorada (ya no necesita de el archivo StringAnalyzer por ende es mas eficiente)
vector<string> CodeReader(string File){
  
  const char *tokensEsp = "%^*-+/:={}[]><==()/##\\;,&&||'";
  int posCaracter=0,posSiguiente=0;
  vector<string> VectorDePalabras;
  fstream file;
  string palabra,palabraDosPuntos;
  file.open(File.c_str());

  while(file >> palabra){
    cout<<palabra<<endl;
    posCaracter = palabra.find_first_of(tokensEsp);
    
    cout<<"Lo encontro en: "<<posCaracter<<endl;
    if(posCaracter < 0){
        VectorDePalabras.push_back(palabra);
      }
      
      if(posCaracter == 0){
        //ingresa el muy caracter especial haciendo la diferencia entre si es := o los demas
        palabraDosPuntos.push_back(palabra[posCaracter]);
        if( strcmp(palabraDosPuntos.c_str(),":") == 0 ){
          cout<<"holi si entre!!1"<<endl;
          VectorDePalabras.push_back(palabra.substr(posCaracter,2));
        }//if
        else{
          VectorDePalabras.push_back(palabra.substr(posCaracter,1));
        }//else
      }
    

    //====================si encontro algun token especial=========================
    if(posCaracter > 0){
      //ingresa la palabra que esta a la izquierda del simbolo especial
      VectorDePalabras.push_back(palabra.substr(0,posCaracter));
      
      //ingresa el muy caracter especial haciendo la diferencia entre si es := o los demas
      palabraDosPuntos.push_back(palabra[posCaracter]);
      if( strcmp(palabraDosPuntos.c_str(),":") == 0 ){
        cout<<"holi si entre!!1"<<endl;
        VectorDePalabras.push_back(palabra.substr(posCaracter,2));
      }//if
      else{
        VectorDePalabras.push_back(palabra.substr(posCaracter,1));
      }//else

      //verifico si el caracter siguiente es un simbolo especial tambien
      posSiguiente = posCaracter + 1;
      if(palabra.find(tokensEsp) >= 0){
        //VectorDePalabras.push_back(palabra[posCaracter+1]);
      }//if
    }//====================si encontro algun token especial=========================


    
    //CREANDO UNA NUEVA PALABRA CON LO QUE RESTA DEL CODIGO para analizarla

    palabra = palabra.substr(posCaracter+1,std::string::npos);
    
    size_t prev = 0, pos;
    while ((pos = palabra.find_first_of(tokensEsp, prev)) != std::string::npos){//<=aca le digo que no quiero que lea
      if (pos > prev){
        VectorDePalabras.push_back(palabra.substr(prev, pos-prev));
        VectorDePalabras.push_back(palabra.substr(pos, 1));
      }//if
      prev = pos+1;
    }//while
    
    //reseteando variables
    posSiguiente = 0;
    palabraDosPuntos = "";
  }//while
  file.close();
  return VectorDePalabras;
}//nuevo metodo




/*
//Funcion original
vector<string> CodeReader(string File){
  //tokens que funcionan para delimitar
  const char *tokensEsp = "%^*-+/ := {}[]>< == () /# #\\ ;,&&||'";
  //variables
  vector<string> VectorDePalabras;
  vector<string> vectorDeArchivo;
  
  ifstream file(File);
  
  if (file.is_open()) {
    string line,palabra;
    while (getline(file, line)) {
      
      cout<<"linea: "<<line<<endl;
      line = line.find_first_of(tokensEsp, 1);

      
    }//while
    file.close();
    return VectorDePalabras;
  }//if
  else{
    vector<string> error;
    error.push_back("Archivo no encontrado");
    return error;
  }//else
}//CodeReader

*/
