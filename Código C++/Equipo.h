///////////////////////////////////////////////////////////
//  Equipo.h
//  Implementation of the Class Equipo
//  Created on:      02-jun-2018 12:51:18 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////
#pragma once

#include "Dimension.h"
#include "Calendario.h"
#include <iostream>
#include <string>
using namespace std;

class Equipo
{	
public:
	Equipo(string desc,string la,string ln,string codigo);
	virtual ~Equipo();
	Equipo();
	virtual Calendario* getCalendario()=0;
	string getClave()const;
	string getEstado();
	string Rastrear(string Codigo);
	virtual bool Verificar();
	Fecha *ultimaverif;
	void setEstado(string est) { Estado = est; };
	void setLugarActual(string lug) { LugarActual = lug; };
	string getLugarNormal() {return LugarNormal;};
	virtual void setCalendario(Fecha *fechactual)=0;
	friend ostream &operator<< (ostream &stream, Equipo &equipo);
	string getLugarActual() { return LugarActual; };
protected:
	const string Codigo;
	string Descripcion;
	string Estado;
	string LugarActual;
	string LugarNormal;
};
