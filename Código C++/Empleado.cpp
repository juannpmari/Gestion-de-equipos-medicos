///////////////////////////////////////////////////////////
//  Empleado.cpp
//  Implementation of the Class Empleado
//  Created on:      02-jun-2018 12:51:17 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "Empleado.h"


Empleado::Empleado(){

}



Empleado::Empleado(string Nombre, string Apellido, string Clave, string DNI)
{
	this->Nombre=Nombre;
	this->Apellido=Apellido;
	this->Clave=Clave;
	this->DNI=DNI;
}

Empleado::~Empleado(){

}