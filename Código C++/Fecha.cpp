///////////////////////////////////////////////////////////
//  Fecha.cpp
//  Implementation of the Class Fecha
//  Created on:      02-jun-2018 12:51:19 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#include "Fecha.h"


Fecha::Fecha(){

}



Fecha::Fecha(int dia, int mes, int a�o)
{
	Dia = dia;
	Mes = mes;
	A�o = a�o;
}

Fecha::~Fecha(){

}





int Fecha::getA�o(){

	return A�o;
}


int Fecha::getDia(){

	return Dia;
}


int Fecha::getMes(){

	return Mes;
}

Fecha * Fecha::AgregarDias(int cant)//por ahora no funciona cant grande
{
	int aux = Dia + cant;
	if ((Mes % 2 != 0 || Mes == 8||Mes==10) && Mes != 9&&Mes!=11) {
		if(aux>31)
			return new Fecha(aux-31,++Mes,A�o);
		else return new Fecha(aux,Mes,A�o);
	}
		
	if ((Mes % 2 == 0 || Mes == 9||Mes==11) && Mes != 8 && Mes != 12) {//por ahora no funciona para cant grande
		if (aux>30)
			return new Fecha(aux - 30, ++Mes, A�o);
		else return new Fecha(aux, Mes, A�o);
	}

	if(Mes==12&&aux>31)
		return new Fecha(aux-31,1,++A�o);
	else return new Fecha(aux, Mes, A�o);
	return nullptr;
}

Fecha * Fecha::AgregarMeses(int cant)
{
	int aux = Mes + cant;
	if (aux > 12)
		return new Fecha(Dia, aux - 12, ++A�o);
		return new Fecha(Dia,aux,A�o);
	return nullptr;
}


Fecha * Fecha::DescontarDias(int cant)
{
	int aux = Dia - cant;
	if ((Mes % 2 != 0 || Mes == 8 || Mes == 10|| Mes == 12) && Mes != 9 && Mes != 11&& Mes != 1) {
		if (aux<0)
			return new Fecha(30+aux, --Mes, A�o);
		else return new Fecha(aux, Mes, A�o);
	}

	if ((Mes % 2 == 0 || Mes == 9 || Mes == 11) && Mes != 8) {//por ahora no funciona para cant grande
		if (aux<0)
			return new Fecha(31+aux, --Mes, A�o); //+ aux xq aux es negativo
		else return new Fecha(aux, Mes, A�o);
	}

	if (Mes == 1 && aux<0)
		return new Fecha(31+aux, 12, --A�o);
	else return new Fecha(aux, Mes, A�o);
	return nullptr;
	//return new Fecha(12, 5, 18);
}
