///////////////////////////////////////////////////////////
//  Calendario.cpp
//  Implementation of the Class Calendario
//  Created on:      02-jun-2018 12:51:14 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "Calendario.h"


Calendario::Calendario(Fecha *fmax, Fecha *fmin):FechaMaxima(*fmax),FechaMinima(*fmin){
	
}



Calendario::~Calendario(){

}


int Calendario::FrecuenciaAlta = 1;
int Calendario::FrecuenciaBaja = 12;
int Calendario::FrecuenciaMedia = 4;