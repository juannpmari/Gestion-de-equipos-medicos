///////////////////////////////////////////////////////////
//  ECG.h
//  Implementation of the Class ECG
//  Created on:      02-jun-2018 12:51:16 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#pragma once

#include "Equipo.h"


class ECG : public Equipo
{

public:
	ECG(string desc, string la, string ln);
	virtual ~ECG();
	ECG();
	bool Verificar();
	void setCalendario(Fecha *fechactual) {
		Fecha *fecha=fechactual->AgregarMeses(Calendario::FrecuenciaBaja);
		(this->calendario)->FechaMaxima = *fecha->AgregarDias(5);
		(this->calendario)->FechaMinima = *fecha->DescontarDias(5);
	};
	Calendario *getCalendario() { return calendario; };
private:
	static int cont;
	Calendario *calendario;
	Dimension Dimensiones;
};
