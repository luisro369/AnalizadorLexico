#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida
int validadorRepetidor(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[8]){
        //Indicador de repetidor
        cout<<"INICIO DE REPETIDOR CORRECTO----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE CONDICION---SINTACTICO\n";
            pos = pos+1;
                if(VSin[pos] == "NUM"){
                //todo bien
                cout<<"NUMERO QUE INDICA EL INCIO DEL REPETIDOR----SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[12]){
                    //todobien
                    cout<<"SIMBOLO DE SEPARADOR------------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == "NUM"){
                        //todo bien
                        cout<<"NUMERO QUE INDICA EL LIMITE DEL REPETIDOR---SINTACTICO\n";
                        pos = pos+1;
                        if(VSin[pos] == ESPT[12]){
                            //todobien
                            cout<<"SIMBOLO DE SEPARADOR------------------------SINTACTICO\n";
                            pos = pos+1;
                            if(VSin[pos] == "NUM"){
                                //todo bien
                                cout<<"NUMERO QUE INDICA EL PASO DEL REPETIDOR-----SINTACTICO\n";
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
                                            cout<<"CODIGO DENTRO DE REPETIDOR------------------SINTACTICO\n";   
                                            pos = pos+1;                                  
                                        }
                                        cout<<"CORCHETE QUE INDICA FIN DE CODIGO-----------SINTACTICO\n";
                                    }else{
                                    //se muere
                                    cout<<ERRORES[3];
                                    exit(0);
                                    }
                                }else{
                                //se muere
                                cout<<ERRORES[4];
                                exit(0);
                                }
                            }else{
                            //se muere
                            cout<<ERRORES[6];
                            exit(0);
                            }
                        }else{
                        //se muere
                        cout<<ERRORES[7];
                        exit(0);
                        }
                    }else{
                    //se muere
                    cout<<ERRORES[6];
                    exit(0);
                    }
                }else{
                //se muere
                cout<<ERRORES[7];
                exit(0);
                }
            }else{
            //se muere
            cout<<ERRORES[6];
            exit(0);
            }
        }else{
        //se muere
        cout<<ERRORES[5];
        exit(0);
        }
    }
    return pos;
}//validadorRepetidor
