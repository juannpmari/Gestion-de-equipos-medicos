///////////////////////////////////////////////////////////
//  Calendario.h
//  Implementation of the Class Calendario
//  Created on:      02-jun-2018 12:51:14 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#pragma once

#include "Fecha.h"

class Calendario
{
	friend class Equipo;
public:
	Calendario(Fecha *fmax,Fecha *fmin);
	virtual ~Calendario();
	friend class ECG;
	friend class RSP;
	friend class MDA;
	Fecha getFechaMaxima() const{ return FechaMaxima; };
	static int getFrecAlta(){return FrecuenciaAlta;};
	static int getFrecBaja() { return FrecuenciaBaja; };
	static int getFrecMedia() { return FrecuenciaMedia; };
	friend ostream &operator<< (ostream &stream, Calendario  &calendario);
private:
	Fecha FechaMaxima;
	Fecha FechaMinima;
	static int FrecuenciaAlta;
	static int FrecuenciaBaja;
	static int FrecuenciaMedia;

};
