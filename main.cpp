#include<iostream>
#include"cambio_de_base.h"

using namespace std;



int main(){

	 string inumber;
	 int base,abase;
	 
	 cout << "Numero a convertir?: "; cin >> inumber;
	 cout << "Escrito en base: "; cin >> base;
	 cout << "Convertirlo este numero a base ?: "; cin >>abase;
	 if( inumber[0] == '-' || base <= 0 || abase <= 0)
	 	cout << "error con las bases o numero(-)" << endl;
	 else
	 	cout << convertir_base_N(inumber, base, abase) << endl;

	return 0;

}

