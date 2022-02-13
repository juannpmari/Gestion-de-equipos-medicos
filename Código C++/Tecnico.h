///////////////////////////////////////////////////////////
//  Tecnico.h
//  Implementation of the Class Tecnico
//  Created on:      02-jun-2018 12:51:22 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#pragma once
#include "Empleado.h"
#include "Mantenimiento.h"
#include "cListaT.h"
#define N 10
class Tecnico : public Empleado
{
	friend void BajaTecnico(cListaT<Tecnico> *tecnicos);
	friend void FinalizarVerificacion(cListaT<Equipo> *equipos, cListaT<Tecnico> *tecnicos, string dni);
	friend void MantenimientosdelDia(cListaT <Tecnico>* tecnicos);
public:
	Tecnico(string Nombre, string Apellido, string Clave, string DNI);
	virtual ~Tecnico();
	bool Verificar(string codigo);
	string getClave() { return Empleado::getClave(); };
	string getPass() { return Empleado::getPass(); };

	void setListaTerminados(Mantenimiento *mant) { ListaTerminados.AgregarItem(mant); };
	void setListaPendientes(Equipo *equipo) {
		try{
			ListaPendientes.AgregarItem(equipo);
		}
		catch (exception *ex) {
			throw ex;
		}
	};
	void VerListaTerminados();
	void VerPendientesPropios();
	void EliminarPendiente(string codigo) { ListaPendientes.Quitar(codigo);};
private:
	cListaT<Equipo> ListaPendientes;
	cListaT<Mantenimiento> ListaTerminados;

};
