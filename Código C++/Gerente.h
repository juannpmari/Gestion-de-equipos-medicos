///////////////////////////////////////////////////////////
//  Gerente.h
//  Implementation of the Class Gerente
//  Created on:      02-jun-2018 12:51:19 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#pragma once

#include "Empleado.h"

class Gerente : public Empleado
{

public:
	Gerente(string Nombre, string Apellido, string Clave, string DNI);
	virtual ~Gerente();
	bool AsignarEquipo(string dni, string codigo);
	string getPass() { return Empleado::getPass(); };
};
