#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion para validar
int validadorEscritura(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[12]){
        //Indicador de repetidor
        cout<<"FUNCION DE ESCRITURA CONSOLA----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE ESCRITURA---SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"VARIABLE A ASIGNAR LA LECTURA---------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[8]){
                    //todobien
                    cout<<"PARENTESIS QUE INDICA FIN DE ESCRITURA------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[11]){
                        //avance de carro
                        cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                        pos;
                    }else{
                        //se muere
                        cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de escritura ')'\n";
                    exit(0);
                }
            }else{
                if(VSin[pos] == ESPT[15]){
                    //todo bien
                    cout<<"SIMBOLO DE CADENA DE INICIO-----------------SINTACTICO\n";
                    pos = pos+1;
                    while(VSin[pos] != ESPT[15]){
                        cout<<"CADENA DE ESCRITRA--------------------------SINTACTICO\n";   
                        pos = pos+1;                                  
                    }
                    cout<<"SIMBOLO DE CADENA DE FINAL------------------SINTACTICO\n";
                }
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de incio de escritura '('\n";
            exit(0);
        }
    }
    return pos;
}//validador escritura
