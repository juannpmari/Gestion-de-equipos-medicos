///////////////////////////////////////////////////////////
//  Tecnico.cpp
//  Implementation of the Class Tecnico
//  Created on:      02-jun-2018 12:51:23 a.m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////
 
#include "Tecnico.h"


Tecnico::Tecnico(string Nombre, string Apellido, string Clave, string DNI) : Empleado(Nombre, Apellido, Clave, DNI) {
	/*ListaPendientes = *lp;
	ListaTerminados=*lt;*/
	
	ListaPendientes=cListaT<Equipo>(N);
	ListaTerminados=cListaT<Mantenimiento>(N);
}



Tecnico::~Tecnico(){

}





bool Tecnico::Verificar(string codigo){

	return false;
}

void Tecnico::VerListaTerminados()
{
	for (int i = 0; i < ListaTerminados.getCA(); i++) {
		cout << *ListaTerminados.getItem(i) << endl;
	}
}

void Tecnico::VerPendientesPropios()
{	
	cout << "Equipos pendientes de verificar asignados" << endl;
	for (int i = 0; i < ListaPendientes.getCA(); i++) {
		if (typeid(*ListaPendientes.getItem(i)) == typeid(MDA) && ListaPendientes.getItem(i)->getEstado() == "Fuera de servicio") {
			cout << "Codigo: ";
			cout << ListaPendientes.getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << ListaPendientes.getItem(i)->getEstado() << endl;
			cout << "Verificar lo antes posible" << endl << endl;
		}
	}
	for (int i = 0; i < ListaPendientes.getCA(); i++) {
		if (typeid(*ListaPendientes.getItem(i)) == typeid(MDA) && ListaPendientes.getItem(i)->getEstado() != "Fuera de servicio") {
			cout << "Codigo: ";
			cout << ListaPendientes.getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << ListaPendientes.getItem(i)->getEstado() << endl;
			if(ListaPendientes.getItem(i)->getEstado() == "En uso")
			cout << *ListaPendientes.getItem(i)->getCalendario() << endl;
		}
	}


	for (int i = 0; i < ListaPendientes.getCA(); i++) {
		if (typeid(*ListaPendientes.getItem(i)) == typeid(RSP) && ListaPendientes.getItem(i)->getEstado() == "Fuera de servicio") {
			cout << "Codigo: ";
			cout << ListaPendientes.getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << ListaPendientes.getItem(i)->getEstado() << endl;
			cout << "Verificar lo antes posible" << endl << endl;
		}
	}
	for (int i = 0; i < ListaPendientes.getCA(); i++) {
			if (typeid(*ListaPendientes.getItem(i)) == typeid(RSP) && ListaPendientes.getItem(i)->getEstado() != "Fuera de servicio") {
				cout << "Codigo: ";
				cout << ListaPendientes.getItem(i)->getClave() << endl;
				cout << "Estado: " << endl;
				cout << ListaPendientes.getItem(i)->getEstado() << endl;
				if (ListaPendientes.getItem(i)->getEstado() == "En uso")
				cout << *ListaPendientes.getItem(i)->getCalendario() << endl;
			}
		}

		for (int i = 0; i < ListaPendientes.getCA(); i++) {
			if (typeid(*ListaPendientes.getItem(i)) == typeid(ECG) && ListaPendientes.getItem(i)->getEstado() == "Fuera de servicio") {
				cout << "Codigo: ";
				cout << ListaPendientes.getItem(i)->getClave() << endl;
				cout << "Estado: " << endl;
				cout << ListaPendientes.getItem(i)->getEstado() << endl;
				cout << "Verificar lo antes posible" << endl << endl;
			}
		}
			for (int i = 0; i < ListaPendientes.getCA(); i++) {
				if (typeid(*ListaPendientes.getItem(i)) == typeid(ECG) && ListaPendientes.getItem(i)->getEstado() != "Fuera de servicio") {
					cout << "Codigo: ";
					cout << ListaPendientes.getItem(i)->getClave() << endl;
					cout << "Estado: " << endl;
					cout << ListaPendientes.getItem(i)->getEstado() << endl;
					if (ListaPendientes.getItem(i)->getEstado() == "En uso")
					cout << *ListaPendientes.getItem(i)->getCalendario() << endl;
				}
			}
}
