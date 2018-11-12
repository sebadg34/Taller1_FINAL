#include "stdafx.h"
#include "ListEvent.h"
#include "ListAdmin.h"
#include "Event.h"
ListEvent::ListEvent()
{
}

ListEvent::ListEvent(int total)
{
	this->total = total;
	this->CantidadActual = 0;
	this->ListE = new Event*[100];
}

void ListEvent::AgregarEvento(Event*eventoNuevo)
{
	
	//Llamar funcion para expandir lista.
	this->ListE[this->CantidadActual] = eventoNuevo;
	this->CantidadActual++;

}


int ListEvent:: GetCantidad() {
	return this->CantidadActual;
}

Event ** ListEvent::GetLista()
{
	return this->ListE;
}

int ListEvent::EventoRealizado(string ID, int CantAsistes)
{
	int N_Evento = -1;
	int MontoGanancia = 1;
	int MontoPerdida = 1;
	for (int i = 0; i < this->CantidadActual; i++) {
		if (this->ListE[i]->GetnEventoID() == ID) {
			if (this->ListE[i]->GetCantEsperado() >= CantAsistes) {
				N_Evento = i;
			}
			else {
				cout << "no pueden asistir más personas de las esperadas " << endl;
			}
		}

	}
	if (N_Evento > -1) {
		if (this->ListE[N_Evento]->GetTipo() == "culturales") {
			MontoGanancia = 4;
			MontoPerdida = 2;
		}
		if (this->ListE[N_Evento]->GetTipo() == "sociales") {
			MontoGanancia = 9;
			MontoPerdida = 5;
		}
		if (this->ListE[N_Evento]->GetTipo() == "deportivos") {
			MontoGanancia = 11;
			MontoPerdida = 8;
		}
		int Utilidades = (this->ListE[N_Evento]->GetCantAsistente())*MontoGanancia - (CantAsistes*MontoPerdida);
		this->ListE[N_Evento]->SetEstado("Realizado");
		return Utilidades;

	}
	return 0;
}

int ListEvent::EventoCancelado(string ID)
{
	int N_Evento = -1;
	int MontoPerdida;
	for (int i = 0; i < this->CantidadActual; i++) {
		if (this->ListE[i]->GetnEventoID() == ID) {
			N_Evento = i;
		}
	}
	if (N_Evento > -1) {
		if (this->ListE[N_Evento]->GetTipo() == "culturales") {
			MontoPerdida = 2;
		}
		if (this->ListE[N_Evento]->GetTipo() == "sociales") {
			MontoPerdida = 5;
		}
		if (this->ListE[N_Evento]->GetTipo() == "deportivos") {
			MontoPerdida = 8;
		}
		int Utilidad = MontoPerdida * (this->ListE[N_Evento]->GetCantEsperado()) * 25 / 100 * -1;
		this->ListE[N_Evento]->SetEstado("Cancelado");
		return Utilidad;
	}
	return 0;
}


void ListEvent::BuscarPorEventos(string tipo)
{
	cout << "LISTADO DE EVENTOS" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < CantidadActual;i++) {
		
		if (tipo == "TODOS") {
			cout << i + 1 << "Nombre: " << this->ListE[i]->Getnombre() << "||" << "Id: "<< this->ListE[i]->GetnEventoID() << "|| "<< "Estado: "<< this->ListE[i]->GetEstado()<< endl;

			//nombre,id,estado
		
		}
		else if (this->ListE[i]->GetTipo() == tipo) {
			cout << i + 1 << "Nombre: " << this->ListE[i]->Getnombre() << "||" << "Id: " << this->ListE[i]->GetnEventoID() << "|| " << "Estado: " << this->ListE[i]->GetEstado() << endl;
		}



	}
}

string ListEvent::BuscarEventos(string ciudad)
{
	return string();
}


void ListEvent::LecturaEvento(Event eventoNuevo)
{
}

ListEvent::~ListEvent()
{

}


