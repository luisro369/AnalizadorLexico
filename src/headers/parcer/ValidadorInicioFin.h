#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//funcion que valida inicio y fin de codigo
void validadorInicioFin(vector<string> vectorPalabrasAnalizadas){
    //verificando que el incio del codigo contenga la palabra reservada adecuada
    if(vectorPalabrasAnalizadas[0] == TOKENST[21]){
        //todo bien        
       cout<<"INICIO DE CODIGO CORRECTO-------------------SINTACTICO\n";
    }else{
        //se muere 
        cout<<ERRORES[0];
        exit(0);
    }//ifelse
    //verificando que el final del codigo contenga la palabra reservada adecuada
    if(vectorPalabrasAnalizadas[vectorPalabrasAnalizadas.size()-1] == TOKENST[20]){
        //todo bien        
        cout<<"FIN DE CODIGO CORRECTO----------------------SINTACTICO\n";
    }else{
        //se muere 
        cout<<ERRORES[1];
        exit(0);
    }//ifelse
}//validadorInicioFin
