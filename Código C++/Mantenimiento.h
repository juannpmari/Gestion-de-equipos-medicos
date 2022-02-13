#pragma once
#include "Equipo.h"
#include "CuentaCorriente.h"
#include "Empleado.h"
#include "Fecha.h"
using namespace std;
class Mantenimiento
{
	Empleado *empleado;
	Equipo *equipo;
	Fecha fecha;
	float costo;
	string codigo;
	static int cont;
	friend ostream &operator<< (ostream &stream, Mantenimiento  &mant);
public:
	Mantenimiento(Empleado *emp, Equipo *eq, Fecha fe, float cos);
	string getClave() { return codigo; };
	Fecha *getFecha() { return &fecha; };
	float getCosto() { return costo; };
	~Mantenimiento();
};

