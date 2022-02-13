///////////////////////////////////////////////////////////
//  RSP.cpp
//  Implementation of the Class RSP
//  Created on:      02-jun-2018 12:51:22 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#include "RSP.h"
#include <ctime>

RSP::RSP(string desc, string la, string ln) :
	Equipo(desc,la,ln, "RSP" + to_string(cont)) {
		cont++;
		Dimensiones.Largo = 1;
		Dimensiones.Alto = 2;
		Dimensiones.Ancho = 1;
		Dimensiones.Peso = 20;
		time_t now = time(0);
		tm*time = localtime(&now);
		Fecha *fechactual = new Fecha(time->tm_mday, ++time->tm_mon, 1900 + time->tm_year);
		Fecha *proxverif = fechactual->AgregarMeses(Calendario::FrecuenciaMedia);
		calendario = new Calendario(proxverif->AgregarDias(5), proxverif->DescontarDias(5));

}



RSP::~RSP(){

}


int RSP::cont = 1;





bool RSP::Verificar(){
	cout << "Controlando que el flujo de salida sea igual al configurado" << endl;
	cout << "Verificando alarmas de alta y baja presion" << endl;
	cout << "Verificando alarma de taponamiento" << endl;
	return false;
}