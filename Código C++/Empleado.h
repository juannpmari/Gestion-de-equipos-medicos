///////////////////////////////////////////////////////////
//  Empleado.h
//  Implementation of the Class Empleado
//  Created on:      02-jun-2018 12:51:17 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <string>
using namespace std;
class Empleado
{
	friend ostream &operator<< (ostream &stream, Empleado  &empleado);

public:
	Empleado(string Nombre,string Apellido, string Clave,string DNI);
	Empleado();
	virtual ~Empleado();
	string getClave(){return DNI;};
	string getPass() { return Clave; };

protected:
	string Apellido;
	string Clave;
	string DNI;
	string Nombre;

};
