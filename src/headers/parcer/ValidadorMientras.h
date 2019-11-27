#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida
int validadorMientras(vector<string> VSin, int pos){
     int posTemp,posTempAux;
    if(VSin[pos] == TOKENST[9]){
        //Indicador de mientras
        cout<<"INICIO DE MIENTRAS CORRECTO-----------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
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
                                posTempAux = posTemp;
                                while(VSin[pos] != ESPT[1] && pos != VSin.size()-1){
                                    cout<<"CODIGO DENTRO DE MIENTRAS-------------------SINTACTICO\n";   
                                    pos = pos+1;                                  
                                }
                                if(pos != VSin.size()-1){
                                    cout<<"CORCHETE QUE INDICA FIN DE CODIGO-----------SINTACTICO\n";
                                }else{
                                    cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[25];
                                    imprimirError(posTemp,25);
                                }
                            }else{
                            //se muere
                            cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[2];
                            imprimirError(posTemp,2);
                            }
                        }else{
                        //se muere
                        cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[3];
                        imprimirError(posTemp,3);
                        }
                    }else{
                    //se muere
                    cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[4];
                    imprimirError(posTemp,4);
                    }
                }else{
                //se muere
                cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[5];
                imprimirError(posTemp,5);
                }
            }else{
            //se muere
            cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[4];
            imprimirError(posTemp,4);
            }
        }else{
        //se muere
        cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[6];
        imprimirError(posTemp,6);
        } 
    }
    return pos;
}//validadorRepetidor
