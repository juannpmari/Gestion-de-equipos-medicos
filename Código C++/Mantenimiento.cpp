#include "Mantenimiento.h"



Mantenimiento::Mantenimiento(Empleado *emp, Equipo *eq, Fecha fe, float cos)
{
	empleado = emp;
	equipo = eq;
	fecha = fe;
	cont++;
	codigo=to_string(cont);
	costo = cos;
}


Mantenimiento::~Mantenimiento()
{
}

int Mantenimiento::cont = 0;