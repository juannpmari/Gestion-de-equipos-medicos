#pragma once
#include "Funciones.h"
#include "Fecha.h"
#include "Tecnico.h"
#include "Gerente.h"
#include "cListaT.h"
#include "ECG.h"
#include "MDA.h"
#include "RSP.h"
#define N 10
void MenuTecnico();
void MenuGerente();
void AgregarEquipo(cListaT<Equipo> *equipos);
void main() {
	//srand(time(NULL));
	cout<<"Bienvenido al Seguimiento de Equipos de la Fundación Favaloro"<<endl;
	cListaT<Tecnico> ListaTecnicos(N);
	cListaT<Equipo> ListaEquipos(N);
	Gerente *gerente = new Gerente("Ger", "Ente", "gerente", "12345678");

	ListaEquipos.AgregarItem(new ECG("ok","Hospital","Hospital"));
	ListaEquipos.AgregarItem(new ECG("Nuevo","Taller","Hospital"));
	ListaEquipos.AgregarItem(new MDA("Viejo","Fundacion","Fundacion"));
	ListaEquipos.AgregarItem(new MDA("bien", "Taller", "Hospital"));
	ListaEquipos.AgregarItem(new RSP("bueno", "Hospital", "Hospital"));
	ListaEquipos.AgregarItem(new RSP("Viejo", "Taller", "Hospital"));
	ListaTecnicos.AgregarItem(new Tecnico("Jose","Perez","1234","12341234"));
	ListaTecnicos.AgregarItem(new Tecnico("Pedro","Nose","1234","12312312"));
	ListaTecnicos.AgregarItem(new Tecnico("Lio", "Messi","1234","12354569"));
	ListaTecnicos.AgregarItem(new Tecnico("Luis","Suarez","1234","45789632"));

	time_t now = time(0);
	tm*time = localtime(&now);
	int log=0;
	do{
	string dni;
	int ingreso=LogIn(&ListaTecnicos,gerente,dni);
	if(ingreso==1){
	int OpcionTecnico=0,aux=0;
	string verif;
	while(OpcionTecnico!=13){
		do{
			MenuTecnico();
			cin >> verif;
			try{
				OpcionTecnico=stoi(verif);
				aux = 0;
			}
				catch (...) {
					cout << "Entrada invalida" << endl;
				aux = 1;
			}
		} while (aux != 0);
		log=0;
		switch (OpcionTecnico) {
		case 1: 
			AgregarEquipo(&ListaEquipos);
			break;
		case 2: 
			ListaTecnicos.BuscarItem(dni)->VerPendientesPropios();
			break;
		case 3: 
			VerVerifPendientes(&ListaEquipos);
			break;
		case 4:
			ListaTecnicos.BuscarItem(dni)->VerListaTerminados();
			break;
		case 5:
			IniciarVerificacion(&ListaEquipos);
			break;
		case 6:
			FinalizarVerificacion(&ListaEquipos,&ListaTecnicos,dni);
			break;
		case 7:
			AvisarFalla(&ListaEquipos); 
			break;
		case 8:
			BuscarPorTipo(&ListaEquipos);
			break;
		case 9:
			EquiposFueraLugar(&ListaEquipos);
			break;
		case 10:
			Rastrear(&ListaEquipos);
			break;
		case 11:
			BuscarPorCodigo(&ListaEquipos);
			break;
		case 12:
			OpcionTecnico = 13;
			log = 1;
			break;
		case 13:
			OpcionTecnico = 13;
			log = 0;
			break;
		}
	}
}

if (ingreso == 2) {
	string verif; int aux=0;
	int OpcionGerente = 0;
	while (OpcionGerente != 14) {
		do {
			MenuGerente();
			cin >> verif;
			try {
				OpcionGerente = stoi(verif);
				aux = 0;
			}
			catch (...) {
				cout << "Entrada invalida" << endl;
				aux = 1;
			}
		} while (aux != 0);
		switch (OpcionGerente) {
			case 1: AgregarEquipo(&ListaEquipos); 
				break;
			case 2: AgregarTecnico(&ListaTecnicos,gerente);
				break;
			case 3: BajaTecnico(&ListaTecnicos);
				break;
			case 4:
				ListarVerificacionesTerminadas(&ListaTecnicos);
				break;
			case 5:
				AsignarVerificacion(&ListaTecnicos, &ListaEquipos);
				break;
			case 6:
				AvisarFalla(&ListaEquipos);
				break;
			case 13:
				OpcionGerente = 14;
				log = 1;
				break;
			case 7:
				Rastrear(&ListaEquipos);
				break;
			case 14:
				OpcionGerente = 14;
				log = 0;
				break;
			case 8:
				BuscarPorCodigo(&ListaEquipos);
				break;
			case 9:
				BuscarPorTipo(&ListaEquipos);
				break;
			case 10:
				CargarSaldo();
				break;
			case 11:
				VerVerifPendientes(&ListaEquipos);
				break;
			case 12:
				ListarEmpleados(&ListaTecnicos);
				break;
			}
		}
	}

	} while (log != 0);

	if (time->tm_hour >= 20) {
	cout << "Equipos fuera de su lugar normal" << endl<<endl;
	EquiposFueraLugar(&ListaEquipos);
	cout << "Mantenimientos del dia" << endl<<endl;
	MantenimientosdelDia(&ListaTecnicos);
	}
	system("pause");

}
