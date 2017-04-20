
#include"cambio_de_base.h"

#include<string>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;


float convertir_A_base_10(int base,string number){
	int res = 0;
	float resf = 0.0, resnew = 0.0;
	int digito;
	
	int posicion = GetPosicionComma(number);
	// parte entera
	for(int e = 0 ; e < posicion ;  e++){
		if(  !isalpha(number[e])   )
			digito = int(number[e]) - '0'; // ´0' = 48
			
		if(   isalpha(number[e])   )
			digito = returnNumberAlpha( number[e] );
		
		res += (digito * pow(base, posicion - 1 - e) ); 
			
	}
	
	//parte decimal
	short c = -1;
	for(int e = posicion + 1  ; e < number.length() ; e++){
		if(  !isalpha(number[e])   )
			digito = int(number[e]) - '0'; // ´0' = 48
			
		if(   isalpha(number[e])   )
			digito = returnNumberAlpha( number[e] );
			
		resf += (digito * pow(base, c ) );
		c--;
	}
	
	if(resf == 0.0)
		return res;
	else
		resnew = static_cast<float>(res);
		return resnew + resf;
}


int returnNumberAlpha(char MAY){
	int num = -1;
	switch(MAY){
		case 'A': num = 10; break;
		case 'B': num = 11; break;
		case 'C': num = 12; break;
		case 'D': num = 13; break;
		case 'E': num = 14; break;
		case 'F': num = 15; break;
		case 'G': num = 16; break;
	}
	return num;

}


string returnAlphaNumber(int number){
	string chs;
	switch(number){
		case 10: chs = 'A'; break;
		case 11: chs = 'B'; break;
		case 12: chs = 'C'; break;
		case 13: chs = 'D'; break;
		case 14: chs = 'E'; break;
		case 15: chs = 'F'; break;
		case 16: chs = 'G'; break;
	}
	return chs;
}
	

int GetPosicionComma(string number){

	int posicion = number.length();
	for(int e = 0 ; e < number.length() ;  e++){
		if( number[e] == ',' || number[e] == '.')
			posicion = e;
	}
	return posicion;
}


string convertir_base_N(string inumber, int base, int abase ){
	stringstream os;
	string resultado = "";
	float res = 0.0;
	
	if(abase == 10){
		os << convertir_A_base_10(base,inumber);
		os >> resultado;
		return os.str();
	}
	else
		res = convertir_A_base_10(base,inumber);

		
		if(true){
			if(abase >= 10){ // swap number to char
		
		
				while(res >= abase){
					if( static_cast<int>(res) % abase >= 10)
						resultado += returnAlphaNumber( static_cast<int>(res) % abase );
				
					else
						resultado += to_string( static_cast<int>(res) % abase );
					
					res /= abase;
				} // end while
			
				///////////////////////////////////////////////////////////
				if( static_cast<int>(res) >= 10)
					resultado += returnAlphaNumber( static_cast<int>(res) );
				else
					resultado += to_string(static_cast<int>(res));
				////////////////////////////////////////////////////////////
			}
		
		
			else{
				while(res >= abase){
					resultado += to_string( static_cast<int>(res) %abase);
					res /= abase;
				}
				resultado += to_string( static_cast<int>(res));
	
			}
			reverse( resultado.begin(), resultado.end() ); 
		}
		return resultado;
}


