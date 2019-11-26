#include<iostream>
#include <vector>

using namespace std;

//declarando el vector con los tokens del lenguaje
vector<string> TOKENS =
{"CONTS","ENT","FLOT","CAR","CAD","BOOL","SI","SINO","PARA","MIENTRAS","HACER","LECT",
"ESCR","PROC","FUNC","DEV","*DEF","*DIM","*ING","*LEER","FINCODIGO","INICIO","ABRIR","GUARDAR","LEER",};


//declarando el vector de tokens
vector<string> TOKENST = 
{"constok","enttok","flotok","cartok","cadtok","booltok","sitok","sinotok","paratok","mientrastok","hacertok","lecttok",
"escrtok","proctok","functok","devtok","deftok","dimtok","ingtok","leertok","fincodigo","iniciocodigo","abrirtok","guardartok","leertok"};

//declarando el vector de caracteres aritmeticos del lenguaje
vector<string> ARITM = 
{"%","^","*","-","+","/",":="};

//declarando el vector de caracteres aritmeticos
vector<string> ARITMT =
 {"op_mod","op_exp","op_mul","op_res","op_sum","op_div","op_asig"};

//declarando el vector de caracteres especiales del lenguaje
vector<string> ESP = 
{"{","}","[","]",">","<","==","(",")","/#","#\\",";",",","||","&&","'"};

//declarando el vector de caracteres especiales 
vector<string> ESPT = 
{"llave_a","llave_c","cor_a","cor_c","mayr","menr","igual","pare_a","pare_c","comen_a","comen_c","puntcoma","coma","olog","ylog","comilla"};

//declarando arreglo de Variables
struct variable
{
	string nombre;
	string tipo;
	string valor;
};

vector<variable> VARIABLES;

