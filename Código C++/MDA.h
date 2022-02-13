///////////////////////////////////////////////////////////
//  MDA.h
//  Implementation of the Class MDA
//  Created on:      02-jun-2018 12:51:21 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#pragma once

#include "Equipo.h"

class MDA : public Equipo
{

public:
	MDA( string desc, string la, string ln);
	virtual ~MDA();
	Dimension Dimensiones;
	bool Verificar();
	 void setCalendario(Fecha *fechactual) {
		 Fecha *fecha = fechactual->AgregarMeses(Calendario::FrecuenciaAlta);
			 (this->calendario)->FechaMaxima = *fecha->AgregarDias(5);
			 (this->calendario)->FechaMinima = *fecha->DescontarDias(5);
	};
	 Calendario *getCalendario() { return calendario; };

private:
	Calendario *calendario;
	static int cont;

};
