///////////////////////////////////////////////////////////
//  ECG.cpp
//  Implementation of the Class ECG
//  Created on:      02-jun-2018 12:51:17 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////

#include "ECG.h"
#include <ctime>
#include <iomanip>
ECG::ECG(string desc, string la, string ln):
Equipo(desc,la,ln,"ECG"+to_string(cont)){

	cont++;
	Dimensiones.Largo = 1;
	Dimensiones.Alto = 0.5;
	Dimensiones.Ancho = 1;
	Dimensiones.Peso = 4;
	time_t now = time(0);
	tm*time = localtime(&now);
	Fecha *fechactual = new Fecha(time->tm_mday, ++time->tm_mon, 1900 + time->tm_year);
	Fecha *proxverif = fechactual->AgregarMeses(Calendario::FrecuenciaBaja);
	calendario = new Calendario(proxverif->AgregarDias(5),proxverif->DescontarDias(5));
}


ECG::~ECG(){

}

ECG::ECG()
{
}


int ECG::cont = 1;





bool ECG::Verificar(){
	cout << "Enchufando a circuito simulador" << endl;
	cout << "Probando correcta visualizacion de las distintas derivaciones y modos de traficacion" << endl;
	return false;
}