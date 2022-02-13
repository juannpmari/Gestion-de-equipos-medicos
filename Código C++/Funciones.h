#pragma once
#include <iostream>
#include <string>
#include "cListaT.h"
#include "Equipo.h"
#include "ECG.h"
#include "MDA.h"
#include "RSP.h"
#include "Tecnico.h"
#include <ctime>
#include "Tecnico.h"
#include "Gerente.h"
#define N 10

using namespace std;

void MenuTecnico() {
	cout << "--Menu Tecnico--" << endl;
	cout << "1-Dar de alta un equipo" << endl; //LISTO
	cout << "2-Ver verificaciones pendientes propias" << endl;
	cout << "3-Ver todas las verificaciones pendientes" << endl;
	cout << "4-Ver verificaciones realizadas propias" << endl;
	cout << "5-Iniciar Verificacion de equipo" << endl; // CASI LISTO
	cout << "6-Finalizar Verificacion de equipo" << endl; //CASI
	cout << "7-Avisar falla en equipo" << endl; //PROBAR
	cout << "8- Buscar por tipo" << endl;
	cout << "9- Ver equipos fuera de su lugar normal" << endl;
	cout << "10- Rastrear Equipo" << endl;
	cout << "11- Buscar por codigo" << endl;
	cout << "12-Cerrar Sesión" << endl; 
	cout << "13-Salir" << endl;
	
}

void MenuGerente() {
	cout << "--Menu Gerente--" << endl;
	cout << "1-Dar de alta un equipo" << endl; //LISTO
	cout << "2-Dar de alta un empleado" << endl; //LISTO
	cout << "3-Dar de baja un empleado" << endl; //LISTO
	cout << "4-Ver todas las verificaciones realizadas" << endl;//listo
	cout << "5-Asignar verificacion de equipo" << endl;
	cout << "6-Avisar falla en equipo" << endl;
	cout << "7- Rastrear Equipo" << endl;
	cout << "8- Buscar por codigo" << endl;
	cout << "9- Buscar por tipo" << endl;
	cout << "10-Cargar Saldo" << endl;
	cout << "11-Listar equipos a verificar" << endl;
	cout << "12-Listar Empleados" << endl;
	cout << "13-Cerrar Sesión" << endl;
	cout << "14-Salir" << endl;	}

void AgregarEquipo(cListaT<Equipo> *equipos) {
	string tipo,desc,estado="En uso",ln,la;

	cout << "Tipo de Equipo: " << endl;
	cin >> tipo;
	cout << "Descripicion: " << endl;
	cin >> desc;
	cout << "Lugar Normal: " << endl;
	cin >> ln;
	cout << "Lugar Actual" << endl;
	cin >> la;
	
	try 
	{
	if (tipo == "ECG") {
		Equipo *ecg = new ECG(desc,la, ln);
		equipos->AgregarItem(ecg);
	}
	if (tipo == "RSP") {
		Equipo *rsp = new RSP( desc, la, ln);
		equipos->AgregarItem(rsp);
	}
	if (tipo == "MDA") {
		Equipo *mda = new MDA(desc, la, ln);
		equipos->AgregarItem(mda);
	}
	if (tipo != "ECG"&&tipo != "MDA"&&tipo != "RSP")
		throw new exception("Codigo invalido");
	}
	catch (exception *ex){
		cout << ex->what() << endl;
		
		}
}


void AgregarTecnico(cListaT<Tecnico> *tecnicos,Gerente *gerente) {
	string nombre, apellido, clave, dni; 
	/*<Equipo> *ListaPendientes=new cListaT<Equipo>(N);
	cListaT<Mantenimiento> *ListaTerminados=new cListaT<Mantenimiento>(N);*/
	int aux = 0;
	cout << "Nombre: " << endl;
	cin >> nombre;		
	cout << "Apellido: " << endl;
	cin >> apellido;
	do{
		aux = 0;
		cout << "DNI: " << endl;
		cin >> dni;
		if (dni == gerente->getClave()) {
			cout << "No puede ser el DNI del gerente" << endl;
			aux = 1;
		}
		try {
			stoi(dni);
			if (dni.length() != 8)
				throw new exception;
		}
		catch (...) {
			cout << "DNI invalido" << endl;
			aux = 1;
		}

		} while (aux != 0);
		cout << "Clave: " << endl;
		cin >> clave;
		

		try
		{
			Tecnico *tec = new Tecnico(nombre, apellido, clave, dni);
			tecnicos->AgregarItem(tec);
		}
		catch (exception *ex) {
			cout << ex->what() << endl;
		}
}

void BajaTecnico(cListaT<Tecnico> *tecnicos){
	string dni;
	int aux;
	Tecnico *tec;
	cout << "Ingrese el DNI del empleado: " << endl;
	cin >> dni;
	try {
		tec=tecnicos->BuscarItem(dni);
		aux=1;
		if(tec==NULL)
			throw new exception("DNI no encontrado");
	}
	catch (exception *ex){
		cout<<ex->what()<<endl;
		aux=0;
	} 
	if(aux!=0){
	tecnicos->Quitar(dni);
	cout<<"Empleado dado de baja correctamente"<<endl;
	}
	
}

void IniciarVerificacion(cListaT<Equipo> *equipos) {
	string codigo; int aux = 1;
	try{
	cout << "Ingrese el codigo del equipo: " << endl;
	cin >> codigo;
	
		if (equipos->BuscarItem(codigo) == NULL)
			throw new exception("Codigo Incorrecto");
	}
	catch (exception *ex) {
		cout << ex->what() << endl;
		aux = 0;
	}
if (aux != 0) {
	if ((equipos->BuscarItem(codigo))->getEstado() == "En uso")
		(equipos->BuscarItem(codigo))->Verificar();
	if ((equipos->BuscarItem(codigo))->getEstado() == "Fuera de servicio")
		cout << "Reparando equipo" << endl;
	if (equipos->BuscarItem(codigo)->getEstado() == "En uso" || equipos->BuscarItem(codigo)->getEstado() == "Fuera de servicio") {
		(equipos->BuscarItem(codigo))->setEstado("En mantenimiento");
		(equipos->BuscarItem(codigo))->setLugarActual("En el taller");

	} //POLIMORFISMO
	else
		cout << "El equipo ya esta en mantenimiento" << endl;
}
}

void FinalizarVerificacion(cListaT<Equipo> *equipos,cListaT<Tecnico> *tecnicos,string dni) {
	string codigo;
	float costo;
	int aux=1;
	cout << "Ingrese el codigo del equipo: " << endl;
	cin >> codigo; 
	try {
		if (equipos->BuscarItem(codigo) == NULL)
				throw new exception("Codigo Incorrecto");
		else{
			if (equipos->BuscarItem(codigo)->getEstado()!="En mantenimiento"){
				aux=0;
				throw new exception("el equipo no esta en mantenimiento");
				}
			else
			aux=1;
		}
	}
	catch (exception *ex) {
			cout << ex->what() << endl;
			aux = 0;
		}
	 
	if (aux != 0) {
		Equipo *equipo = equipos->BuscarItem(codigo);
		costo=CuentaCorriente::setSaldo();
		equipo->setEstado("En uso");
		equipo->setLugarActual(equipo->getLugarNormal());

		time_t now = time(0);
		tm*time = localtime(&now);
		Fecha *fechactual = new Fecha(time->tm_mday, ++time->tm_mon, 1900 + time->tm_year);


		Mantenimiento *mant = new Mantenimiento(tecnicos->BuscarItem(dni), equipo, *fechactual, costo);
		(tecnicos->BuscarItem(dni))->setListaTerminados(mant);
		equipo->setCalendario(fechactual);

		tecnicos->BuscarItem(dni)->EliminarPendiente(codigo);
	}
}

void AvisarFalla(cListaT<Equipo> *equipos) {
	string codigo;
	int aux = 0;
	cout << "Ingrese el codigo del equipo: " << endl;
	cin >> codigo;
	try {
		Equipo *eq = equipos->BuscarItem(codigo);
		if (eq == NULL)
			throw new exception("Codigo Invalido");
	}
	catch (exception *ex) {
		cout << ex->what() << endl;
		aux = 1;
	}
	if(aux!=1)
	(equipos->BuscarItem(codigo))->setEstado("Fuera de servicio");
}

int LogIn(cListaT<Tecnico> *ListaTecnicos, Gerente *gerente,string &dni) {
	int ingreso = 0;
	string DNI, clave;
	while (ingreso == 0) {
		cout << "Log-In" << endl;
		cout << "Ingrese su DNI" << endl;
		cin >> DNI;
		cout << "Ingrese su contraseña" << endl;
		cin >> clave;
		Empleado *verif = ListaTecnicos->BuscarItem(DNI);
		if (verif != NULL&&verif->getClave() == DNI&&verif->getPass()==clave) {
			cout << "Ingreso Autorizado" << endl;
			cout << "Ingresando como Técnico" << endl;
			ingreso = 1;
			dni=DNI;
		}
		if (gerente->getClave() == DNI&&gerente->getPass()==clave) {
			cout << "Ingreso Autorizado" << endl;
			cout << "Ingresando como Gerente" << endl;
			ingreso = 2;
			
		}
		if (ingreso == 0)
			cout << "El DNI o la contraseña son inválidos" << endl;
	}
	return ingreso;
}

ostream &operator<< (ostream &stream, Equipo &equipo)
{
	 stream<< "Codigo Equipo: "<<equipo.Codigo <<endl<<
		 "Descripcion: "<<equipo.Descripcion <<endl<< "Estado: "<<equipo.Estado <<endl<<
		 "Lugar Actual: "<< equipo.LugarActual << endl;
	 return stream;
}

ostream &operator<< (ostream &stream,Empleado  &empleado)
{
	stream << "Nombre: " << empleado.Nombre << endl <<
		"Apellido: " << empleado.Apellido << endl << "DNI: " << empleado.DNI << endl;
	return stream;
}

ostream &operator<< (ostream &stream, Mantenimiento  &mant)
{	
	stream << *mant.empleado;
	stream << *mant.equipo;
	stream << mant.fecha;
	stream << "Codigo Mantenimiento: " << mant.codigo << endl <<
		"Costo: " << mant.costo << endl;
	return stream;
}

ostream &operator<< (ostream &stream, Fecha  &fecha)
{
	stream << "Dia: " << fecha.Dia << endl <<
		"Mes: " << fecha.Mes << endl <<
		"Año: "<<fecha.Año<<endl;
	return stream;
}

ostream &operator<< (ostream &stream, Calendario  &calendario)
{	
	stream << "Verificar entre " << calendario.FechaMinima <<
		"y " << calendario.FechaMaxima << endl;
	return stream;
}

void AsignarVerificacion(cListaT<Tecnico> *tecnicos,cListaT<Equipo> *equipos) {
	string dni,codigo;
	int aux=0;
	cout << "Ingrese el codigo del equipo: " << endl;
	cin>>codigo;
	
	try {
		Equipo *eq=equipos->BuscarItem(codigo);
		if (eq == NULL)
			throw new exception("Codigo Invalido");
		cout<<"Ingrese el DNI del empleado: "<<endl;
		cin>>dni;
		Tecnico *tec = tecnicos->BuscarItem(dni);
		if (tec == NULL)
			throw new exception("DNI Invalido");
	}
	catch (exception *ex) {
		cout << ex->what() << endl;
		aux = 1;
	}
	if(aux==0)
		try {
		tecnicos->BuscarItem(dni)->setListaPendientes(equipos->BuscarItem(codigo));
	}
	catch (exception *ex) {
		cout << ex->what() << endl;
	}
}

void VerVerifPendientes(cListaT<Equipo> *equipos) {
	cout << "Equipos pendientes: " << endl<<endl;
	for (int i = 0; i < equipos->getCA(); i++) {
		if(typeid(*(*equipos)[i])==typeid(MDA)&& (*equipos)[i]->getEstado()=="Fuera de servicio"){
			cout << "Codigo: " << endl;
			cout << (*equipos)[i]->getClave() << endl;
			cout << "Estado: " << endl;
			cout << (*equipos)[i]->getEstado() << endl;
			cout << "Verificar lo antes posible" << endl<<endl;
		}
	}
	for (int i = 0; i < equipos->getCA(); i++) {
		if (typeid(MDA)==typeid(*equipos->getItem(i))&& equipos->getItem(i)->getEstado() != "Fuera de servicio") {
			cout << "Codigo :" << endl;
			cout << (*equipos)[i]->getClave() << endl;
			cout << "Estado: " << endl;
			cout << (*equipos)[i]->getEstado() << endl;
			if((*equipos)[i]->getEstado() == "En uso")
			cout << *(*equipos)[i]->getCalendario() << endl;
		}
	}
	for (int i = 0; i < equipos->getCA(); i++) {
		if (typeid(*equipos->getItem(i)) == typeid(RSP) && equipos->getItem(i)->getEstado() == "Fuera de servicio") {
			cout << "Codigo :" << endl;
			cout << equipos->getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << equipos->getItem(i)->getEstado() << endl;
			cout << "Verificar lo antes posible" << endl<<endl;
		}
	}
	for (int i = 0; i < equipos->getCA(); i++) {
		if (typeid(*equipos->getItem(i)) == typeid(RSP) && equipos->getItem(i)->getEstado() != "Fuera de servicio") {
			cout << "Codigo :" << endl;
			cout << equipos->getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << equipos->getItem(i)->getEstado() << endl;
			if (equipos->getItem(i)->getEstado() == "En uso")
			cout << *equipos->getItem(i)->getCalendario() << endl;
		}
	}
	for (int i = 0; i < equipos->getCA(); i++) {
		if (typeid(*equipos->getItem(i)) == typeid(ECG) && equipos->getItem(i)->getEstado() == "Fuera de servicio") {
			cout << "Codigo :" << endl;
			cout << equipos->getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << equipos->getItem(i)->getEstado() << endl<<endl;
			cout << "Verificar lo antes posible" << endl<<endl;
		}
	}
	for (int i = 0; i < equipos->getCA(); i++) {
		if (typeid(*equipos->getItem(i)) == typeid(ECG) && equipos->getItem(i)->getEstado() != "Fuera de servicio") {
			cout << "Codigo :" << endl;
			cout << equipos->getItem(i)->getClave() << endl;
			cout << "Estado: " << endl;
			cout << equipos->getItem(i)->getEstado() << endl<<endl;
			if (equipos->getItem(i)->getEstado() == "En uso")
			cout << *equipos->getItem(i)->getCalendario() << endl;
		}
	}
}

void ListarVerificacionesTerminadas(cListaT<Tecnico> *tecnicos) {
	for (int i = 0; i < tecnicos->getCA(); i++) {
		tecnicos->getItem(i)->VerListaTerminados();
	}
}

void Rastrear(cListaT<Equipo> *equipos) {
	string codigo, ubicacion;
	cout << "Ingrese el codigo a buscar" << endl;
	cin >> codigo;
	try {
		if (equipos->BuscarItem(codigo) == NULL)
			throw new exception;
		ubicacion = equipos->BuscarItem(codigo)->getLugarActual();
		cout << "El equipo se encuentra en: " << ubicacion << endl;
	}
	catch (...) {
		cout << "Codigo Invalido" << endl;
	}
}
void BuscarPorCodigo(cListaT<Equipo> *equipos) {
	string codigo;
	cout << "Ingrese el codigo: " << endl;
	cin >> codigo;
	try{
		if(equipos->BuscarItem(codigo)==NULL)
		throw new exception;
	cout << *equipos->BuscarItem(codigo) << endl;
	}
	catch (...) {
		cout << "Codigo invalido" << endl;
	}
}

void BuscarPorTipo(cListaT<Equipo> *equipos) {
	string tipo;
	int acum = 0;
	cout << "Ingrese el tipo de equipo: " << endl;
	cin >> tipo;
	if(tipo.length()==3){
	for (int i = 0; i < equipos->getCA();i++){
		acum = 0;
		for (int k = 0; k < 3;k++){
			if ((*equipos)[i]->getClave()[k] == tipo[k])
				acum++;
		}
	if(acum==3)
	cout << *(*equipos)[i] << endl;
		
	}
}
	if (tipo.length() != 3 || acum != 3)
		cout << "Tipo invalido" << endl;
}

void EquiposFueraLugar(cListaT<Equipo> *equipos) {
	for (int i = 0; i < equipos->getCA(); i++) {
		if ((*equipos)[i]->getLugarActual() != (*equipos)[i]->getLugarNormal())
			cout << *(*equipos)[i] << endl;
	}
}

void CargarSaldo() {
	CuentaCorriente::CargarSaldo();
}



void MantenimientosdelDia(cListaT <Tecnico>* tecnicos) {
	time_t now = time(0);
	tm*time = localtime(&now);
	Fecha *fechactual = new Fecha(time->tm_mday, ++time->tm_mon, 1900 + time->tm_year);
	float acum = 0;
	for (int i = 0; i < tecnicos->getCA(); i++) {
		for (int k = 0; k < (*tecnicos)[i]->ListaTerminados.getCA(); k++) {
			if (*(*tecnicos)[i]->ListaTerminados[k]->getFecha()==*fechactual)
				cout << *(*tecnicos)[i]->ListaTerminados[k] << endl;
			acum += (*tecnicos)[i]->ListaTerminados[k]->getCosto();
		}
	}
	cout << "Costo total del dia: " <<acum<< endl;

};

void ListarEmpleados(cListaT<Tecnico>* tecnicos) {
	cout << "Lista de Tecnicos" << endl << endl;
	for (int i = 0; i < tecnicos->getCA(); i++)
		cout << *(*tecnicos)[i] << endl<<endl;
	
}
