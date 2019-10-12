#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//funcion que valida inicio y fin de codigo
void validadorInicioFin(vector<string> algoAnalizado){
    //verificando que el incio del codigo contenga la palabra reservada adecuada
    if(algoAnalizado[0] == TOKENST[21]){
        //todo bien        
       cout<<"INICIO DE CODIGO CORRECTO-------------------SINTACTICO\n";
    }else{
        //se muere 
        cout<<"El codigo debe iniciar con la palabra reservada 'INICIO'\n";
        exit(0);
    }//ifelse
    //verificando que el final del codigo contenga la palabra reservada adecuada
    if(algoAnalizado[algoAnalizado.size()-1] == TOKENST[20]){
        //todo bien        
        cout<<"FIN DE CODIGO CORRECTO----------------------SINTACTICO\n";
    }else{
        //se muere 
        cout<<"El codigo debe finalizar con la palabra reservada 'FINCODIGO'\n";
        exit(0);
    }//ifelse
}//validadorInicioFin
