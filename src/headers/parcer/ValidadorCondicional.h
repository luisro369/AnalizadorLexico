#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Fucion que valida
int validadorCondicional(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[6] || VSin[pos] == TOKENST[7] || VSin[pos] == TOKENST[9]){
        //todo bien 
        cout<<"DECLARACION DE CONDICIONAL------------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
        //todobien
        cout<<"PARENTESIS QUE INDICA INICIO DE CONDICION---SINTACTICO\n";
        pos = pos+1;
            if(VSin[pos] == "VAR"){
                //todo bien
                cout<<"LLAMADA A UNA VARIABLE CORRECTA-------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[4] || VSin[pos] == ESPT[5] || VSin[pos] == ESPT[6]){
                    //todo bien
                    cout<<"SIMBOLO DE COMPARACION----------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == "VAR"){
                       //todo bien
                       cout<<"LLAMADA A UNA VARIABLE CORRECTA-------------SINTACTICO\n";
                       pos = pos+1;
                       if(VSin[pos] == ESPT[8]){
                        //todobien
                        cout<<"PARENTESIS QUE INDICA FIN DE CONDICION------SINTACTICO\n";
                        pos = pos+1;
                            if(VSin[pos] == ESPT[0]){
                                //todobien
                                cout<<"CORCHETE  QUE INDICA INICIO DE CODIGO-------SINTACTICO\n";
                                pos = pos+1;
                                while(VSin[pos] != ESPT[1]){
                                    cout<<"CODIGO DENTRO DE CONDICIONAL----------------SINTACTICO\n";   
                                    pos = pos+1;                                  
                                }
                                cout<<"CORCHETE QUE INDICA FIN DE CODIGO-----------SINTACTICO\n";
                            }else{
                            //se muere
                            cout<<"ERROR: se esperaba simbolo de incio de subcodigo '{'\n";
                            exit(0);
                            }
                        }else{
                        //se muere
                        cout<<"ERROR: se esperaba simbolo de fin de codicion ')'\n";
                        exit(0);
                        }
                    }else{
                    //se muere
                    cout<<"ERROR: se esperaba una variable\n";
                    exit(0);
                    }
                }else{
                //se muere
                cout<<"ERROR: se esperaba simbolo de comparacion '<','>','=='\n";
                exit(0);
                }
            }else{
            //se muere
            cout<<"ERROR: se esperaba una variable\n";
            exit(0);
            }
        }else{
        //se muere
        cout<<"ERROR: se esperaba simbolo de inicio de condicion '('\n";
        exit(0);
        }
    }
    return pos;
}//validador condicional
