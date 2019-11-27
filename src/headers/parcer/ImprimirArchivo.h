#include <fstream>
#include <string>

void imprimirError(int Linea,int Error){
	ofstream salida;
	salida.open("./data/salida.txt",ios::app);
	salida<<"En linea: "<<est.VectorLineas[Linea]<<" "<<ERRORES[Error];
	salida.close();
}