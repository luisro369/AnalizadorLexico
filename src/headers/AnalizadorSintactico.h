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

int validadorAsignacion(vector<string> VSin, int pos){
    //verifica si se ha ingresado un token de tipo dato
    if(VSin[pos] == TOKENST[1] || VSin[pos] == TOKENST[2] || VSin[pos] == TOKENST[3] || VSin[pos] == TOKENST[4] || VSin[pos] == TOKENST[5]){
        //avance de carro        
        cout<<"DECLARACION DE VARIABLE---------------------SINTACTICO\n";
        pos = pos+1;
        //verifica que acontinuacion cotenga un lexema adecuado para nombre de variable
        if(VSin[pos] == "lexema"){
            //avance de carro
            cout<<"NOMBRE DE VARIABLE ADECAUDA-----------------SINTACTICO\n";
             pos = pos+1;
            //verifica que acontinuacion contenga el simbolo asigando para asignacion
            if(VSin[pos] == ARITMT[6]){
                //avance de carro
                cout<<"SIMBOLO DE ASIGNACON CORRECTA---------------SINTACTICO\n";
                 pos = pos+1;
                //verifica si lo siguiente es un lexema adecuado segun el tipo de dato que se ha declarado
                if(VSin[pos] == "lexema"){
                    //avance de carro
                    cout<<"VALOR DE VARIABLE ADECUADA------------------SINTACTICO\n";
                     pos = pos+1;
                    //verifica que al final de la linea este el simbolo asignado para fin de linea
                    if(VSin[pos] == ESPT[11]){
                        //avance de carro
                        cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                    }else{
                        //se muere
                        cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<"ERROR: valor no corresponde con tipo de dato\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba simbolo de asignacion ':='\n"; 
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba un nombre para la asginacion de la varible\n"; 
            exit(0);
        }
    }
    return pos;
}

int validadorCondicional(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[6] || VSin[pos] == TOKENST[7] || VSin[pos] == TOKENST[9]){
        //todo bien 
        cout<<"DECLARACION DE CONDICIONAL------------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
        //todobien
        cout<<"PARENTESIS QUE INDICA INICIO DE CONDICION---SINTACTICO\n";
        pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"LLAMADA A UNA VARIABLE CORRECTA-------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[4] || VSin[pos] == ESPT[5] || VSin[pos] == ESPT[6]){
                    //todo bien
                    cout<<"SIMBOLO DE COMPARACION----------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == "lexema"){
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
}

int validadorRepetidor(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[8]){
        //Indicador de repetidor
        cout<<"INICIO DE REPETIDOR CORRECTO----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE CONDICION---SINTACTICO\n";
            pos = pos+1;
                if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"NUMERO QUE INDICA EL INCIO DEL REPETIDOR----SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[12]){
                    //todobien
                    cout<<"SIMBOLO DE SEPARADOR------------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == "lexema"){
                        //todo bien
                        cout<<"NUMERO QUE INDICA EL LIMITE DEL REPETIDOR---SINTACTICO\n";
                        pos = pos+1;
                        if(VSin[pos] == ESPT[12]){
                            //todobien
                            cout<<"SIMBOLO DE SEPARADOR------------------------SINTACTICO\n";
                            pos = pos+1;
                            if(VSin[pos] == "lexema"){
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
                            cout<<"ERROR: se esperaba un numero\n";
                            exit(0);
                            }
                        }else{
                        //se muere
                        cout<<"ERROR: se esperaba un simbolo de separacion ','\n";
                        exit(0);
                        }
                    }else{
                    //se muere
                    cout<<"ERROR: se esperaba un numero\n";
                    exit(0);
                    }
                }else{
                //se muere
                cout<<"ERROR: se esperaba un simbolo de separacion ','\n";
                exit(0);
                }
            }else{
            //se muere
            cout<<"ERROR: se esperaba un numero\n";
            exit(0);
            }
        }else{
        //se muere
        cout<<"ERROR: se esperaba un simbolo de inicio de codigo '('\n";
        exit(0);
        }
    }
    return pos;
}

int validadorLectura(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[11]){
        //Indicador de repetidor
        cout<<"FUNCION DE LECTURA CONSOLA------------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE LECTURA-----SINTACTICO\n";
            pos = pos+1;
                if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"VARIABLE A ASIGNAR LA LECTURA---------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[8]){
                    //todobien
                    cout<<"PARENTESIS QUE INDICA FIN DE LECTURA--------SINTACTICO\n";
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
                    cout<<"ERROR: se esperaba simbolo de fin de lectura ')'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba una variable asiganble\n";
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de incio de lectura '('\n";
            exit(0);
        }
    }
    return pos;
}

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
}

int validadorManejoArchivos(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[22] || VSin[pos] == TOKENST[23] || VSin[pos] == TOKENST[24]){
        //Indicador de repetidor
        cout<<"FUNCION DE MANEJO DE ARCHIVOS---------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
            //todobien
            cout<<"PARENTESIS QUE INDICA INICIO DE ARCHIVO-----SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"RUTA DEL ARCHIVO----------------------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[8]){
                    //todobien
                    cout<<"PARENTESIS QUE INDICA FIN DE ARCHIVO--------SINTACTICO\n";
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
                    cout<<"ERROR: se esperaba simbolo de fin de archivo ')'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba una ruta al archivo\n";
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de incio de archivo '('\n";
            exit(0);
        }    
    }    
    return pos;
}

int validadorProceso(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[13]){
         //Indicador de repetidor
        cout<<"INDICADOR INICIO DE PROCESO-----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "lexema"){
            //todo bien
            cout<<"NOMBRE DE PROCESO---------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == ESPT[7]){
                //todobien
                cout<<"PARENTESIS QUE INDICA INICIO DE PARAMETRO---SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == "lexema"){
                    //todo bien
                    cout<<"PARAMETRO DE PROCESO------------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[8]){
                        //todobien
                        cout<<"PARENTESIS QUE INDICA FIN DE PARAMETRO------SINTACTICO\n";
                        pos = pos+1;
                        if(VSin[pos] == ESPT[0]){
                            //todobien
                            cout<<"CORCHETE  QUE INDICA INICIO DE CODIGO-------SINTACTICO\n";
                            pos = pos+1;
                            while(VSin[pos] != ESPT[1]){
                                cout<<"CODIGO DE PROCESO---------------------------SINTACTICO\n";   
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
                    cout<<"ERROR: se esperaba simbolo de fin de parametro ')'\n";
                    exit(0);
                    }
                }else{
                //se muere
                cout<<"ERROR: se esperaba parametro\n";
                exit(0);
                }
            }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de inicio de parametro '('\n";
            exit(0);
            }
        }else{
         //se muere
        cout<<"ERROR: se esperaba nombre para el proceso\n";
        exit(0);
        }
    }
    return pos;
}

int validadorFuncion(vector<string> VSin, int pos){
   if(VSin[pos] == TOKENST[14]){
         //Indicador de repetidor
        cout<<"INDICADOR INICIO DE FUNCION-----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "lexema"){
            //todo bien
            cout<<"NOMBRE DE FUNCION---------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == ESPT[7]){
                //todobien
                cout<<"PARENTESIS QUE INDICA INICIO DE PARAMETRO---SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == "lexema"){
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
                            if(VSin[pos] == "lexema"){
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
                                        cout<<"ERROR: se esperaba simbolo de fin de subcodigo '}'\n";
                                        exit(0);
                                    }
                                }else{
                                    //se muere
                                    cout<<"ERROR: se esperaba simbolo de fin de liena ';'\n";
                                    exit(0);
                                }
                            }else{
                                //se muere
                                cout<<"ERROR: se esperaba una variable para el retorno\n";
                                exit(0);
                            }
                        }else{
                            //se muere
                            cout<<"ERROR: se esperaba simbolo de incio de subcodigo '{'\n";
                            exit(0);
                        }
                    }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de paramtro ')'\n";
                    exit(0);
                    }
                }else{
                //se muere
                cout<<"ERROR: se esperaba parametro\n";
                exit(0);
                }
            }else{
            //se muere
            cout<<"ERROR: se esperaba simbolo de inicio de parametro '('\n";
            exit(0);
            }
        }else{
         //se muere
        cout<<"ERROR: se esperaba nombre para la funcion\n";
        exit(0);
        }
    }
    return pos;
}

int validadorDefArreglo(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[16]){
         //Indicador de definicion de arreglo
        cout<<"INDICADOR DEFINCION DE ARREGLO--------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == TOKENST[1] || VSin[pos] == TOKENST[2] || VSin[pos] == TOKENST[3] || VSin[pos] == TOKENST[4] || VSin[pos] == TOKENST[5]){
            cout<<"INDICADOR DEL TIPO DEL ARREGLO--------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"NOMBRE DE ARREGLO---------------------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[11]){
                    //avance de carro
                    cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba un nombre para asignar al arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba un tipo de dato valido para el arreglo 'ENT', 'FLOT','CAD','CAR','BOOL'\n";
            exit(0);
        }
    }
    return pos;
}

int validadorDimArreglo(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[17]){
         //Indicador de definicion de arreglo
        cout<<"INDICADOR DIMENSION DE ARREGLO--------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "lexema"){
            cout<<"ARREGLO A DIMESIONAR------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"DIMENSION DEL ARREGLO-----------------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[11]){
                    //avance de carro
                    cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba un numero para la dimsion del arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba una variable arreglo\n";
            exit(0);
        }
    }
    return pos;
}

int validadorIngArreglo(vector<string> VSin, int pos){
    if(VSin[pos] == TOKENST[18]){
         //Indicador de ingreso de arreglo
        cout<<"INDICADOR INSERCION DE ARREGLO--------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "lexema"){
            cout<<"ARREGLO A INGRESAR DATOS--------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"VARIABLE A INGRESAR EN EL ARREGLO-----------SINTACTICO\n";
                pos = pos+1;
                 if(VSin[pos] == "lexema"){
                    //todo bien
                    cout<<"POSICION DEL ARREGLO A INGRESAR-------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == ESPT[11]){
                        //avance de carro
                        cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                    }else{
                        //se muere
                        cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba un numero para la posicion del arreglo\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba una variable para ingresarla en el arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba una variable arreglo\n";
            exit(0);
        }
    }
    return pos;
}

int validadorLeerArreglo(vector<string> VSin, int pos){
   if(VSin[pos] == TOKENST[19]){
         //Indicador de lectura de arreglo
        cout<<"INDICADOR LECTRUA DE ARREGLO----------------SINTACTICO\n";
        pos = pos+1;
        if(VSin[pos] == "lexema"){
            cout<<"ARREGLO A LEER------------------------------SINTACTICO\n";
            pos = pos+1;
            if(VSin[pos] == "lexema"){
                //todo bien
                cout<<"POSICION DEL ARREGLO AL LEER----------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[11]){
                    //avance de carro
                    cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                }else{
                    //se muere
                    cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba un numero para la posicion del arreglo\n";
                exit(0);
            }   
        }else{
            //se muere
            cout<<"ERROR: se esperaba una variable arreglo\n";
            exit(0);
        }
    }
    return pos;
}

//funcion que manejara el flujo
void AnalizadorSintactico(vector<string> algoAnalizado){
    cout<<"=========================ANALIZADOR SINTACTICO========================\n";
    validadorInicioFin(algoAnalizado);
    //for para recorrer el vector de tokens y lexemas analizados
    for(int pos=1; pos<algoAnalizado.size()-2;pos++){
        pos = validadorAsignacion(algoAnalizado,pos);
        pos = validadorCondicional(algoAnalizado,pos);
        pos = validadorRepetidor(algoAnalizado,pos);
        pos = validadorLectura(algoAnalizado,pos);
        pos = validadorEscritura(algoAnalizado,pos);
        pos = validadorManejoArchivos(algoAnalizado,pos);
        pos = validadorProceso(algoAnalizado,pos);
        pos = validadorFuncion(algoAnalizado,pos);
        pos = validadorDefArreglo(algoAnalizado,pos);
        pos = validadorDimArreglo(algoAnalizado,pos);
        pos = validadorIngArreglo(algoAnalizado,pos);
        pos = validadorLeerArreglo(algoAnalizado,pos);    
    }
    cout<<"=========================GRACIAS POR USAR AGORA=======================\n";
}//bloque
