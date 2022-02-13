///////////////////////////////////////////////////////////
//  Equipo.cpp
//  Implementation of the Class Equipo
//  Created on:      02-jun-2018 12:51:18 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#include "Equipo.h"
#include <ctime>

Equipo::Equipo(string desc,string la, string ln,string codigo):Codigo(codigo){
	
	Descripcion = desc;
	Estado="En uso";
	LugarActual=la;
	LugarNormal=ln;
	time_t now = time(0);
	tm*time = localtime(&now);
	Fecha *fechactual=new Fecha(time->tm_mday,++time->tm_mon,1900+time->tm_year);
	
	ultimaverif = fechactual;

}



Equipo::~Equipo(){

}

Equipo::Equipo()
{
}


string Equipo::getClave()const{

	return Codigo;
}


string Equipo::getEstado(){

	return  Estado;
}


string Equipo::Rastrear(string Codigo){

	return  NULL;
}


bool Equipo::Verificar(){

	return false;
}

/*void Equipo::ImprimirCalendario()
{
	(calendario->getFechaMaxima()).imprimir();

}*/
