#include "parametros.h"

//palabras reservadas
extern char *lexpal[MAXPAL];

//lista de tokens
enum simbolo {ident,numero,igual,parena,parenc,puntoycoma,punto,asignacion,
			  consttok,enttok,flottok,cartok,cadtok,booltok,sitok,sinotok,igualtok,mayortok
			  paratok,mientrastok,hacertok,lecttok,escrtok,proctok,functok,devtok,deftok,dimtok,ingtok,leertok,
			  sumtok,restok,multtok,divtok,modtok,exptok,concattok,logytok,logotok,negtok}; //definido aquí en el encabezado

extern enum simbolo token;

//tabla de tokens de palabras reservadas
extern enum simbolo tokpal[MAXPAL]; 

//tabla de tokens correspondientes a operadores y símbolos especiales
extern enum simbolo espec[255] ;
