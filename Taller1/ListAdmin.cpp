#include "stdafx.h"
#include "ListAdmin.h"


ListAdmin::ListAdmin()
{
}

ListAdmin::ListAdmin(int total)
{
	this->total = total;
	this->CantidadActual = 0;
	this->ListaA = new Admin*[100];
}


ListAdmin::~ListAdmin()
{
}

void ListAdmin::AgregarAdmin(Admin*nuevoAdmin)
{	
	//Falta generador de ID
	
	//Falta aumentar la lista en 1;
	this->ListaA[this->CantidadActual] = nuevoAdmin;
	this->CantidadActual ++;

	
}



string ListAdmin::BuscarAdmin(string ciudad)
{
	int menor = 99999;
	string idAdmin = "";
	for (int i = 0; i < this->CantidadActual; i++) {

		if (ListaA[i]->GetCiudad() == ciudad) {
			if (ListaA[i]->GetCantEventos() < menor) {
				menor = ListaA[i]->GetCantEventos();
				idAdmin = ListaA[i]->GetAdminID();
			}

		}
		
	}
	return idAdmin;
}


void ListAdmin::DesplegarAdmins()
{
	
	cout << "LISTADO DE ADMINISTRADORES" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < CantidadActual; i++) {

		

			cout << i + 1 << "Nombre: " << this->ListaA[i]->Getnombre() << "||" << "Apellido: " << this->ListaA[i]->GetApellido() << "||" << "Id: " << this->ListaA[i]->GetAdminID() << "||" << "Monto: " << this->ListaA[i]->GetMonto() << endl;
			//Ciclo Eventos

			//nombre,id,estado
                   

	}
}

void ListAdmin::AdminDespedido(bool)
{
}

void ListAdmin::Administradores()
{
}

void ListAdmin::AumentarCant()
{
	this->CantidadActual++;
}

void ListAdmin::DisminuirCant()
{
	this->CantidadActual--;
}

int ListAdmin::GetCantidad()
{
	return this->CantidadActual;
}

Admin** ListAdmin::GetLista()
{
	return ListaA;
}
int ListAdmin::Utilidades(string AdminID, int utilidad)
{
	int valor = 0;
	int N_Admin = -1;
	for (int i = 0; i < this->CantidadActual; i++) {
		if (this->ListaA[i]->GetAdminID() == AdminID) {
			N_Admin = i;
		}
	}
	if (N_Admin > -1) {
		valor = this->ListaA[N_Admin]->GetMonto() + utilidad;
		this->ListaA[N_Admin]->SetMonto(valor);

	}

	return valor;
}