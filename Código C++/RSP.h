///////////////////////////////////////////////////////////
//  RSP.h
//  Implementation of the Class RSP
//  Created on:      02-jun-2018 12:51:22 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#pragma once
#include "Equipo.h"

class RSP : public Equipo
{

public:
	RSP(string desc,  string la, string ln);
	virtual ~RSP();
	Dimension Dimensiones;
	bool Verificar();
	void setCalendario(Fecha *fechactual) {
		Fecha *fecha = fechactual->AgregarMeses(Calendario::FrecuenciaMedia);
		(this->calendario)->FechaMaxima = *fecha->AgregarDias(5);
		(this->calendario)->FechaMinima = *fecha->DescontarDias(5);
	};
	 Calendario *getCalendario() { return calendario; };

private:
	Calendario *calendario;
	static int cont;

};
