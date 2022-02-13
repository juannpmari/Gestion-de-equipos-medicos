///////////////////////////////////////////////////////////
//  Fecha.h
//  Implementation of the Class Fecha
//  Created on:      02-jun-2018 12:51:19 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <string>
using namespace std;
class Fecha
{
	friend ostream &operator<< (ostream &stream, Fecha  &fecha);
public:
	Fecha(int dia,int mes,int a�o);
	virtual ~Fecha();
	Fecha();
	int getA�o();
	int getDia();
	int getMes();
	Fecha *AgregarDias(int cant);
	Fecha *AgregarMeses(int cant);
	Fecha *DescontarDias(int cant);
	bool operator==(Fecha B) {
		if (Dia == B.Dia&&Mes == B.Mes&&A�o==B.A�o) return true;
		return false;
	};
private:
	int A�o;
	int Dia;
	int Mes;

};
