#include <fstream>
#include <string>

void archivoSalida(){
	ofstream salida;
	salida.open("./data/salida.txt",ios::out);
	salida<<"=========ARCHIVO DE COMPILACION DE ERRORES DE AURIGA=========\n";
	salida.close();
}

void finalArchivo(){
	ofstream salida2;
	salida2.open("./data/salida.txt",ios::app);
	salida2<<"================GRACIAS POR USAR CODIGO AURIGA================\n";
	salida2.close();
}