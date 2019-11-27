#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Funcion que valida
int validadorFuncion(vector<string> VSin, int pos){
  int posTemp;
   if(VSin[pos] == TOKENST[14]){
         //Indicador de repetidor
        cout<<"INDICADOR INICIO DE FUNCION-----------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
        pos = pos+1;
        if(VSin[pos] == "VAR"){
            //todo bien
            cout<<"NOMBRE DE FUNCION---------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == ESPT[7]){
                //todobien
                cout<<"PARENTESIS QUE INDICA INICIO DE PARAMETRO---SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == "VAR"){
                    //todo bien
                    cout<<"PARAMETRO DE FUNCION------------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[8]){
                        //todobien
                        cout<<"PARENTESIS QUE INDICA FIN DE PARAMETRO------SINTACTICO\n";
                        pos = pos+1;
                        if(VSin[pos] == ESPT[0]){
                            //todobien
                            cout<<"CORCHETE  QUE INDICA INICIO DE CODIGO-------SINTACTICO\n";
                            pos = pos+1;
                            while(VSin[pos] != TOKENST[15]){
                                cout<<"CODIGO DENTRO DE FUNCION--------------------SINTACTICO\n";   
                                pos = pos+1;                                  
                            }
                            cout<<"INDICADOR DE RETORNO DE FUNCION-------------SINTACTICO\n";
                            pos=pos+1;   
                            if(VSin[pos] == "VAR"){
                                //todo bien
                                cout<<"VARIABLE DE RETONRO-------------------------SINTACTICO\n";
                                pos = pos+1;
                                if(VSin[pos] == ESPT[11]){
                                    //avance de carro
                                    cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                                    pos=pos+1;
                                    if(VSin[pos] == ESPT[1]){
                                        //todo bien
                                        cout<<"CORCHETE QUE INDICA FIN DE SUBCODIGO--------SINTACTICO\n";
                                    }else{
                                        //se muere
                                        //cout<<ERRORES[13];
                                        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[13];
                                        imprimirError(posTemp,13);
                                    }
                                }else{
                                    //se muere
                                    //cout<<ERRORES[9];
                                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[9];
                                    imprimirError(posTemp,9);
                                }
                            }else{
                                //se muere
                                //cout<<ERRORES[14];
                                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[14];
                                imprimirError(posTemp,14);
                            }
                        }else{
                            //se muere
                            //cout<<ERRORES[2];
                            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[2];
                            imprimirError(posTemp,2);
                        }
                    }else{
                    //se muere
                    //cout<<ERRORES[3];
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[3];
                    imprimirError(posTemp,3);
                    }
                }else{
                //se muere
                //cout<<ERRORES[15];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[15];
                imprimirError(posTemp,15);
                }
            }else{
            //se muere
            //cout<<ERRORES[6];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
            imprimirError(posTemp,6);
            }
        }else{
         //se muere
          //cout<<ERRORES[16];
        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[16];
        imprimirError(posTemp,16);
        }
    }
    return pos;
}//validador funcion
