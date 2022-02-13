///////////////////////////////////////////////////////////
//  MDA.cpp
//  Implementation of the Class MDA
//  Created on:      02-jun-2018 12:51:21 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#include "MDA.h"
#include <ctime>

MDA::MDA(string desc,string la, string ln) :
	Equipo(desc,la, ln, "MDA" + to_string(cont)) {
	cont++;
	Dimensiones.Largo = 2;
	Dimensiones.Alto = 1;
	Dimensiones.Ancho = 1;
	Dimensiones.Peso = 10;
	time_t now = time(0);
	tm*time = localtime(&now);
	Fecha *fechactual = new Fecha(time->tm_mday, ++time->tm_mon, 1900 + time->tm_year);
	Fecha *proxverif = fechactual->AgregarMeses(Calendario::FrecuenciaAlta);
	calendario = new Calendario(proxverif->AgregarDias(5), proxverif->DescontarDias(5));

}



MDA::~MDA(){

}


int MDA::cont = 1;





bool MDA::Verificar(){
	cout << "Controlando volumenes de flujo de los gases frente a los fijados " << endl;
	cout << "Controlando alarmas externas de baja o alta frecuencia cardiaca y de niveld e sueño" << endl;
	return false;
}