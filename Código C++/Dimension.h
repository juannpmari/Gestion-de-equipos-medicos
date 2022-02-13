///////////////////////////////////////////////////////////
//  Dimension.h
//  Implementation of the Class Dimension
//  Created on:      02-jun-2018 12:51:15 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////
#pragma once

class Dimension
{
	friend class ECG;
	friend class MDA;
	friend class RSP;
public:
	Dimension(float alto,float ancho,float largo,float peso);
	Dimension();
	virtual ~Dimension();

private:
	float Alto;
	float Ancho;
	float Largo;
	float Peso;

};
