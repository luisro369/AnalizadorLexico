#include "lexico.h"

//se define e inicializa la tabla de lexemes correspondientes a las palabras reservadas
char *lexpal[MAXPAL]={"CONTS","ENT","FLOT","CAR","CAD","BOOL","SI","SINO","IGUAL","MAYOR","PARA",
					  "MIENTRAS","HACER","LECT","ESCR","PROC","FUNC","DEV","DEF","DIM","ING","LEER",
					  "SUM","RES","MULT","DIV","MOD","EXP","CONCAT","LOGY","LOGO","NEG"};

//el token
enum simbolo token;

//se define e inicializa la tabla de tokens de palabras reservadas
enum simbolo tokpal [MAXPAL]={consttok,enttok,flottok,cartok,cadtok,booltok,sitok,sinotok,igualtok,mayortok
			  paratok,mientrastok,hacertok,lecttok,escrtok,proctok,functok,devtok,deftok,dimtok,ingtok,leertok,
			  sumtok,restok,multtok,divtok,modtok,exptok,concattok,logytok,logotok,negtok};

//tabla de tokens correspondientes a operadores y símbolos especiales
enum simbolo espec[255] ;
