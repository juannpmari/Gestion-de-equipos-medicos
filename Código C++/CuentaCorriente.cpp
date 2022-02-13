///////////////////////////////////////////////////////////
//  CuentaCorriente.cpp
//  Implementation of the Class CuentaCorriente
//  Created on:      02-jun-2018 12:51:15 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#include "CuentaCorriente.h"


CuentaCorriente::CuentaCorriente(){

}



CuentaCorriente::~CuentaCorriente(){

}


int CuentaCorriente::Numero=123456789;
int CuentaCorriente::Saldo=8000;





int CuentaCorriente::getSaldo(){

	return 0;
}


void CuentaCorriente::ImprimirInfo(){

}

float CuentaCorriente::setSaldo()
{
	float valor;
	/*int aux = 0;
	string verif;
	do{
	try {
		cout << "Ingrese el costo en dolares: " << endl;
		cin >> verif;
		valor = stoi(verif);
		if (valor < 0) {
			throw new exception("Valor invalido");
		
			
		}
		if (valor >= 0) {
			aux=0;
			Saldo -= valor;
			if (Saldo < 0)
				cout << "Advertencia: Saldo negativo" << endl;
			cout << "Costo: " << valor << endl;
			cout << "Saldo restante: " << Saldo << endl;
		}

	}
	catch (exception *ex) {
		cout << ex->what() << endl;
		aux = 1;
	}
	catch (...) { 
		cout << "Monto Invalido" << endl;
		aux = 1; }
	} while (aux != 0);
	Este codigo se usa si se quiere pedir el costo del mantenimiento al usuario
	*/
	valor = rand() % 990 + 10;
	Saldo -= valor;
	if (Saldo < 0)
	cout << "Advertencia: Saldo negativo" << endl;
	cout << "Costo: " << valor << endl;
	cout << "Saldo restante: " << Saldo << endl;
	
	return valor;
}

void CuentaCorriente::CargarSaldo()
{
	int aux = 0;
	int valor;
	string verif;
	do{
	try {
		cout << "Ingrese el monto a cargar" << endl;
		cin >> verif;
		valor = stoi(verif);
		if (valor < 0) {
			throw new exception("Valor invalido");
			
		}
		else{
		Saldo += valor;
		cout << "Saldo nuevo: " << Saldo << endl;
		aux = 0;
		}
	}
	catch (exception *ex) {
		cout << ex->what() << endl;
		aux = 1;
	}
	catch (...) {
		cout << "Monto Invalido" << endl;
		aux = 1; }
	} while (aux != 0);
}
