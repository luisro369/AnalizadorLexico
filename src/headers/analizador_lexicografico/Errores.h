#include<iostream>
#include <vector>

using namespace std;

//declarando el vector con los tokens del lenguaje
vector<string> ERRORES =
{
	"ERROR_0000: El codigo debe iniciar con la palabra reservada 'INICIO'\n",
	"ERROR_0001: El codigo debe finalizar con la palabra reservada 'FINCODIGO'\n",
	"ERROR_0002: se esperaba simbolo de incio de subcodigo '{'\n",
	"ERROR_0003: se esperaba simbolo de fin de codicion ')'\n",
	"ERROR_0004: se esperaba una variable\n",
	"ERROR_0005: se esperaba simbolo de comparacion '<','>','=='\n",
	"ERROR_0006: se esperaba simbolo de inicio de condicion '('\n",
	"ERROR_0007: se esperaba un numero\n",
	"ERROR_0008: se esperaba un simbolo de separacion ','\n",
	"ERROR_0009: se esperaba simbolo de fin de linea ';'\n",
	"ERROR_0010: valor no corresponde con tipo de dato\n",
	"ERROR_0011: se esperaba simbolo de asignacion ':='\n",
	"ERROR_0012: se esperaba un nombre para la asginacion de la varible\n",
	"ERROR_0013: se esperaba simbolo de fin de subcodigo '}'\n",
	"ERROR_0014: se esperaba una variable para el retorno\n",
	"ERROR_0015: se esperaba parametro\n",
	"ERROR_0016: se esperaba nombre para la funcion\n",
	"ERROR_0017: se esperaba una ruta al archivo\n",
	"ERROR_0018: se esperaba un nombre para asignar al arreglo\n",
	"ERROR_0019: se esperaba un tipo de dato valido para el arreglo 'ENT', 'FLOT','CAD','CAR','BOOL'\n",
	"ERROR_0020: se esperaba un numero para la dimension del arreglo\n",
	"ERROR_0021: se esperaba una variable arreglo\n",
	"ERROR_0022: se esperaba un numero para la posicion del arreglo\n",
	"ERROR_0023: se esperaba una variable para ingresarla en el arreglo\n",
	"ERROR_0024: se esperaba un numero para la posicion del arreglo\n"
};
