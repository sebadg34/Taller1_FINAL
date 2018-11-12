#include "stdafx.h"
#include "Admin.h"


Admin::Admin()
{
}

Admin::Admin(string nombre, string apellido, string AdminID, string ciudad, int monto)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->AdminID = AdminID;
	this->ciudad = ciudad;
	this->monto = monto;
	this->eventos = new string[100];
	cantEventos = 0;
}



string Admin::Getnombre()
{
	return nombre;
}

string Admin::GetApellido()
{
	return apellido;
}

string Admin::GetAdminID()
{
	return AdminID;
}

string Admin::GetCiudad()
{
	return ciudad;
}

int Admin::GetCantEventos()
{
	return this->cantEventos;
}

string Admin::getEvento(int index)
{
	return eventos[index];
}

int Admin::GetMonto()
{
	return this->monto;
}

void Admin::SetMonto(int monto)
{
	this->monto = monto;
}

void Admin::AgregarEvento(string evento)
{
	eventos[cantEventos] = evento;
	this->cantEventos++;
}


string * Admin::GetEvento()
{
	return eventos;
}

Admin::~Admin()
{
}
