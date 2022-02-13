///////////////////////////////////////////////////////////
//  CuentaCorriente.h
//  Implementation of the Class CuentaCorriente
//  Created on:      02-jun-2018 12:51:15 a.m.
//  Original author: Alumno
///////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>
using namespace std;
class CuentaCorriente
{

public:
	CuentaCorriente();
	virtual ~CuentaCorriente();

	static int getSaldo();
	static void ImprimirInfo();
	static float setSaldo();
	static void CargarSaldo();

private:
	static int Numero;
	static int Saldo;

};
