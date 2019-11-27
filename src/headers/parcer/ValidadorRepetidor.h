#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida
int validadorRepetidor(vector<string> VSin, int pos){
  int posTemp;
    if(VSin[pos] == TOKENST[8]){
        //Indicador de repetidor
        cout<<"INICIO DE REPETIDOR CORRECTO----------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                                    //cout<<ERRORES[3];
                                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[3];
                                    imprimirError(posTemp,3);
                                    }
                                }else{
                                //se muere
                                //cout<<ERRORES[4];
                                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[4];
                                imprimirError(posTemp,4);
                                }
                            }else{
                            //se muere
                            //cout<<ERRORES[6];
                            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
                            imprimirError(posTemp,6);
                            }
                        }else{
                        //se muere
                        //cout<<ERRORES[7];
                        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[7];
                        imprimirError(posTemp,7);
                        }
                    }else{
                    //se muere
                    //cout<<ERRORES[6];
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
                    imprimirError(posTemp,6);
                    }
                }else{
                //se muere
                //cout<<ERRORES[7];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[7];
                imprimirError(posTemp,7);
                }
            }else{
            //se muere
            //cout<<ERRORES[6];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
            imprimirError(posTemp,6);
            }
        }else{
        //se muere
        //cout<<ERRORES[5];
        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[5];
        imprimirError(posTemp,5);
        }
    }
    return pos;
}//validadorRepetidor
