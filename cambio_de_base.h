#ifndef CAMBIO_DE_BASE
#define CAMBIO_DE_BASE

#include<string>
using namespace std;

float convertir_A_base_10(int,string);
/*
	la funcion convertir_A_base_10 tendra como 
	primer parametro a la base que queremos 
	convertir y como segundo el numero.
	y devolvera el numero en base 10 a la base 
	que dicha.
	
*/
int returnNumberAlpha(char);
/*
	esta funcion retorna en numero de el caracter
	dado (no ascci) A = 10, B = 11, ...... G = 16.
*/
string returnAlphaNumber(int);
/*
	 esta funcion retornara el caracter del numero 
	dado, paso inverso a la funcion anterio.
*/
int GetPosicionComma(string);
/*
	Recibira como unico parametro un cadena(numero)
	y devolvera la pocion en la que se encuentra la 
	coma.
*/
string convertir_base_N(string, int, int);
/*
	Esta funcion ya mas generica. que utiliza las 
	funciones anteriores retorna el numero convertido
	de la base dada a la requerida.
	( numero / base / abase)
*/


#endif // CAMBIO_DE_BASE
