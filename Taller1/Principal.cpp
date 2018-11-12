#include "stdafx.h"
#include "Principal.h"
#include "ListClient.h"
#include "ListEvent.h"
#include "ListAdmin.h"
#include "String.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

ListEvent le = ListEvent(100);
ListAdmin la = ListAdmin(100);
ListClient lc = ListClient(100);


Principal::Principal()
{

	LecturaDeArchivos();
	Menu();


}


Principal::~Principal()
{
}

void Principal::LecturaDeArchivos()
{
#pragma region Clientes
	//Variables aux

	std::ifstream archivoClientes;
	archivoClientes.open("Clientes.txt", ifstream::in);

	string linea;
	string C_nombre;
	string C_apellido;
	string C_id;
	string C_ciudad;
	string C_numero;

	if (archivoClientes.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoClientes, linea)) {
			//crear cliente
			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, C_nombre, ';');
			cout << C_nombre << endl; //Imprimir nombre
			

			getline(ss, C_apellido, ';');
			cout << C_apellido << endl; //Imprimir apellido
			

			getline(ss, C_id, ';');
			cout << C_id << endl; //Imprimir id
			


			getline(ss, C_ciudad, ';');
			cout << C_ciudad << endl; //Imprimir ciudad
			

			getline(ss, C_numero, ';');
			cout << C_numero << endl; //Imprimir numero
			
			Client*clienteNuevo = new Client(C_nombre, C_apellido, C_id, C_ciudad, std::stoi(C_numero));
			cout << "***************************************************" << endl;
			cout << "LISTA DE EVENTOS" << endl;
			
			//ciclo de eventos
			string* ls;

			while (!ss.eof()) {
				string evento;
				getline(ss, evento, ';');
				clienteNuevo->AgregarEvento(evento);
				cout << evento << endl; //Imprimir linea
			}
			lc.AgregarCliente(clienteNuevo);
			//falta agregar a lista
			cout << "***************************************************" << endl;

		}


		
	}

#pragma endregion Clientes

#pragma region Administradores

	//Variables aux

	
	string A_nombre;
	string A_apellido;
	string A_id;
	string A_ciudad;
	string A_monto;


	std::ifstream archivoAdmin;
	archivoAdmin.open("Administradores.txt", ifstream::in);
	

	if (archivoAdmin.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoAdmin, linea)) {
			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, A_nombre, ';');
			cout << A_nombre << endl; //Imprimir nombre

			getline(ss, A_apellido, ';');
			cout << A_apellido << endl; //Imprimir apellido

			getline(ss, A_id, ';');
			cout << A_id << endl; //Imprimir id

			getline(ss, A_ciudad, ';');
			cout << A_ciudad << endl; //Imprimir ciudad

			getline(ss, A_monto, ';');
			cout << A_monto << endl; //Imprimir monto
			
			Admin *nuevoAdmin =new Admin(A_nombre, A_apellido, A_id, A_ciudad, std::stoi(A_monto));
			cout << "***************************************************" << endl;
			//ciclo de eventos
			cout << "LISTA DE EVENTOS" << endl;
			while (!ss.eof()) {
				string evento;
				getline(ss, evento, ';');
				cout << evento << endl; //Imprimir linea
				cout << la.GetCantidad() << endl;
				nuevoAdmin->AgregarEvento(evento);
				cout << la.GetCantidad() << endl;
			}
		
			

			la.AgregarAdmin(nuevoAdmin);
			cout << "***************************************************" << endl;

		}


		
	}
#pragma endregion Administradores

#pragma region Eventos

	std::ifstream archivoEventos;
	archivoEventos.open("Eventos.txt", ifstream::in);
	
	

	if (archivoEventos.is_open()) {
		cout << "***************************************************" << endl;
		while (getline(archivoEventos, linea)) {

			string E_nombre;
			string E_ciudad;
			string E_idCliente;
			string E_idAdmin;
			string E_id;
			string E_tipo;
			string E_estado;

			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, E_nombre, ',');
			getline(ss, E_ciudad, ',');
			getline(ss, E_idCliente, ',');
			getline(ss, E_idAdmin, ',');
			getline(ss, E_id, ',');
			getline(ss, E_tipo, ',');
			getline(ss, E_estado, ',');
			

			if (E_estado.compare("Realizado") == 0) {
				string cantEsp;
				string cantAsis;

				getline(ss, cantEsp, ',');
				getline(ss, cantAsis, ',');
				


				Event *eventoNuevo = new Event(E_nombre, E_ciudad, E_idCliente, E_idAdmin, E_id, E_tipo, E_estado, std::stoi(cantEsp),std::stoi(cantAsis));
				le.AgregarEvento(eventoNuevo);
			}
			else {
				string cantEsp;
				getline(ss, cantEsp , ',');
				cout << cantEsp << endl; //Imprimir cantidad de personas esperadas del evento.
				Event *eventoNuevo = new Event(E_nombre, E_ciudad, E_idCliente, E_idAdmin, E_id, E_tipo, E_estado, std::stoi(cantEsp),0);
				le.AgregarEvento(eventoNuevo);
			}

			
			//Falta agregar eventoNuevo a lista le.
			
			//Creamos el evento y se añade a la lista

			
			cout << "***************************************************" << endl;
			cout << "***************************************************" << endl;

		}
	}

#pragma endregion Eventos
}

void Principal::Menu()
{
	
	
	bool menu = true;
	cout << "Bienvenido a GenEvent" << endl;
	string opcion;
	string pause;
	while (menu) {
		cout << "A continuacion se mostrara un menu para que interactue" << endl;
		cout << "Menu principal:" << endl;
		cout << "1)Agregar" << endl;
		cout << "2)Administrar Evento" << endl;
		cout << "3)Buscar" << endl;
		cout << "4)Cerrar el programa" << endl;
		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);

		switch (opcionVerificada) {
		case 1:
			MenuAgregar();
			break;
		case 2:
			MenuAdministrar();
			break;
		case 3:
			MenuBuscar();
			break;
		case 4:
			cout << "Gracias por usar el programa" << endl;
			ArchivoSalida();
			Despedidos();
			getline(cin, pause);
			menu = false;
			break;
		}
	}
}

void Principal::MenuAgregar()
{
	bool menu = true;
	cout << "Selecciono Agregar datos" << endl;
	string opcion;
	while (menu) {
		cout << "A continuacion se mostraron diferentes opciones que podran elegir" << endl;
		cout << "Menu Agregar:" << endl;
		cout << "1)Agregar Evento" << endl;
		cout << "2)Agregar Administrador" << endl;
		cout << "3)Agregar Cliente" << endl;
		cout << "4)volver" << endl;
		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);
		//recordar delete() despues
		
		
		string* variableEventos = new string[10];


		switch (opcionVerificada) {
		case 1:
			//HalloweenNight, Antofagasta, C5, A20, E7, Cultural, Realizado, 3000, 2800
			AgregarEvento();
			continue;

		case 2:
			AgregarAdmin();
			continue;

		case 3:
			
			AgregarCliente();
			continue;


		case 4:
			cout << "Se regresara al menu principal" << endl;
			menu = false;
			Menu();
			break;
		}
	}
}

void Principal::MenuAdministrar()
{
	cout << "Selecciono Menu Administras" << endl;
	string opcion;
	bool menu = true;
	while (menu) {
		cout << "A continuacion se mostraron diferentes opciones que podran elegir" << endl;
		cout << "Menu Administrar evento:" << endl;
		cout << "1)Evento Realizado" << endl;
		cout << "2)Cancelar Evento" << endl;
		cout << "3)Volver" << endl;

		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);
		//recordar delete() despues

		
		switch (opcionVerificada) {
		case 1:
			RealizarEvento();
			continue;
		case 2:
			CancelarEvento();
			continue;
		case 3:
			cout << "Selecciono volver al menu principal" << endl;
			menu = false;
			Menu();
			break;
		}
	}
}

void Principal::MenuBuscar()
{
	bool menu = true;
	cout << "Selecciono Buscar" << endl;
	string opcion;
	while (menu) {
		cout << "A continuacion se le daran diferentes opciones de busqueda" << endl;
		cout << "se le pedira algunos datos para realizar la busqueda dependiendo del caso" << endl;
		cout << "Menu Buscar:" << endl;
		cout << "1)Eventos por tipo" << endl;
		cout << "2)Cliente por ciudad" << endl;
		cout << "3)Administradores" << endl;
		cout << "4)volver" << endl;
		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);
		
		
		switch (opcionVerificada) {
		case 1:
			BuscarPorEventos();
			continue;
			cout << "Se regresara al menu buscar" << endl;
		case 2:
			BuscarClientes();
			continue;

		case 3:
			DesplegarAdmins();
			continue;

		case 4:
			cout << "Se regresara al menu principal" << endl;
			menu = false;
			break;
		}
	}
}



void Principal::ReducirLista()
{
}

void Principal::ExpandirLista()
{
}

void Principal::AgregarEvento() {

	string nombre;
	string ciudad;
	string id;
	string tipoEvento;
	string cantidad;
	cout << "Ingrese nombre" << endl;
	getline(cin, nombre);
	cout << "Ingrese ciudad" << endl;
	getline(cin, ciudad);
	cout << "Ingrese la id del cliente" << endl;
	getline(cin, id);
	cout << "Ingrese el tipo de evento" << endl;
	getline(cin, tipoEvento);
	id[0] = toupper(id[0]);
	

	//algoritmo para pasar string a mayusculas
	for (int i = 0; i < tipoEvento.length(); i++) {
		tipoEvento[i] = tolower(tipoEvento[i]);
	}
	tipoEvento[0] = toupper(tipoEvento[0]); //hace mayuscula la primera letra 

	cout << "Ingrese la cantidad de personas esperadas" << endl;
	getline(cin, cantidad);
	//algoritmo para pasar string a mayusculas
	for (int i = 0; i < ciudad.length(); i++) {
		ciudad[i] = tolower(ciudad[i]);
	}
	ciudad[0] = toupper(ciudad[0]); //hace mayuscula la primera letra 

	
	//Comparo si existe admin en la ciudad y si el tipo de evento es valido.
	if (la.BuscarAdmin(ciudad) != "" && (tipoEvento == "Social" || tipoEvento == "Cultural" || tipoEvento == "Deportivo")&& lc.VerificarCliente(id) ==true) {
		//Se crea el evento
		cout << "EVENTO CREADO" << endl;
		cout << "**************************" << endl;

		try {
			int cantVer = std::stoi(cantidad);
			Event*eventoNuevo = new Event(nombre, ciudad, id, la.BuscarAdmin(ciudad), "E" + std::to_string(le.GetCantidad() + 1), tipoEvento, "PorRealizar", cantVer, 0);
			le.AgregarEvento(eventoNuevo);
		}
			catch(const std::exception) {
				cout << "cantidad invalida, evento no fue creado" << endl;
				

			}






		
	}
	else {
		//Se cancela la creacion de evento

		if (la.BuscarAdmin(ciudad) == "") {
			cout <<"Admin no encontrado en esa ciudad, se requiere agregar un admin\n para crear el evento en dicha ciudad (Registre nuevo admin mediante el menu)" << endl;
			cout << "**************************" << endl;
		}
		 if (!(tipoEvento == "Social" || tipoEvento == "Cultural" || tipoEvento == "Deportivo")) {
			cout << "Tipo evento invalido, Ingrese uno correcto (social, cultural, Deportivo)" << endl;
			cout << "**************************" << endl;
		}
		if (lc.VerificarCliente(id) == false) {
			cout << "id de Cliente invalido, no fue encontrado un \ncliente dentro del sistema con tal id." << endl;
			cout << "**************************" << endl;
		}
		cout << "*****************************************************************************" << endl;
	}
	cout << "Se regresara al menu agregar" << endl;
	cout << "**************************" << endl;
}
void Principal::AgregarCliente() {

	string nombre;
	string apellido;
	string ciudad;
	string numero;
	
	cout << "Ingresar Nombre" << endl;
	getline(cin, nombre);
	cout << "Ingrese Apellido" << endl;
	getline(cin, apellido);
	cout << "Ingresar Ciudad" << endl;
	getline(cin, ciudad);
	cout << "Ingresar el numero telefonico" << endl;
	getline(cin, numero);


	//algoritmo para pasar string a mayusculas
	for (int i = 0; i < ciudad.length(); i++) {
		ciudad[i] = tolower(ciudad[i]);
	}
	ciudad[0] = toupper(ciudad[0]); //hace mayuscula la primera letra 


	try {
		int numeroVer = std::stoi(numero);
		
		Client*clienteNuevo = new Client(nombre, apellido, "C" + std::to_string(lc.GetCantidad() + 1), ciudad, numeroVer);
		lc.AgregarCliente(clienteNuevo);
		cout << "Se regresara al menu agregar" << endl;
	}
	catch (const std::exception) {
		cout << "Numero invalido, regrsando a menu" << endl;
		
	}
	
}


void Principal::AgregarAdmin() {
	string nombre;
	string apellido;
	string ciudad;
	cout << "Ingresar Nombre" << endl;
	getline(cin, nombre);
	cout << "Ingrese Apellido" << endl;
	getline(cin, apellido);
	cout << "Ingresar ciudad" << endl;
	getline(cin, ciudad);
	
	Admin*nuevoAdmin = new Admin(nombre, apellido, "A" + to_string(la.GetCantidad()+1), ciudad, 7000);
	la.AgregarAdmin(nuevoAdmin);
	cout << "Se regresara al menu agregar" << endl;

}

void Principal::BuscarPorEventos()
{
	string variable;
	cout << "Selecciono buscar Eventos por tipo" << endl;
	cout << "Ingrese el tipo de evento a buscar (o ingrese 'todos' para desplegar todos los eventos)" << endl;
	while (true) {
		getline(cin, variable);

		//algoritmo para pasar string a mayusculas
		for (int i = 0; i < variable.length(); i++) {
			variable[i] = toupper(variable[i]);
		}
		
		
		//********************************************
		if (variable == "SOCIAL" || variable == "DEPORTIVO" || variable == "CULTURAL" || variable == "TODOS") {
			cout << "success" << endl;
			le.BuscarPorEventos(variable);
			break;

		}
		else {
			cout << "ingreso una opcion no valida" << endl;
			cout << "se volvera a pedir el tipo asegurese de que es valido" << endl;
		}
	}
}
void Principal::BuscarClientes()
{
	string variable;
	cout << "Selecciono buscar Cliente por ciudad" << endl;
	cout << "Ingrese la ciudad que desea buscar  (o ingrese 'todos' para desplegar todas las ciudades)" << endl;
	getline(cin, variable);
	//algoritmo para pasar string a mayusculas
	for (int i = 0; i < variable.length(); i++) {
		variable[i] = tolower(variable[i]);
	}
	variable[0] = toupper(variable[0]);
	//********************************************
	lc.BuscarCliente(variable);
	cout << "Se regresara al menu buscar" << endl;
}
void Principal::DesplegarAdmins() {
	cout << "Selecciono buscar administradores" << endl;
	la.DesplegarAdmins();
	cout << "Se regresara al menu buscar" << endl;
}

void Principal::RealizarEvento()
{
	string variableID;
	string variable_cantidad;
	cout << "Porfavor ingrese la id del eveto" << endl;
	getline(cin, variableID);
	cout << "Porfavor ingrese la cantidad de personas que asistieron" << endl;
	getline(cin, variable_cantidad);
	int utilidad = le.EventoRealizado(variableID, std::stoi(variable_cantidad));
	utilidad = la.Utilidades(variableID, utilidad);
	if (utilidad < 0) {
		//despedir
	}
}
void Principal::CancelarEvento()
{
	string variableID;
	cout << "Porfavor ingrese la id del eveto que quiera cancelar" << endl;
	getline(cin, variableID);
	int utilidad = le.EventoCancelado(variableID);
	utilidad = la.Utilidades(variableID, utilidad);
	if (utilidad < 0) {
		//despedir
	}
}

void Principal::Despedidos()
{
	

	ofstream myfile("Despedidos.txt");
	if (myfile.is_open())
	{//Algoritmo que verifica si el admin es despedido dependiendo de su monto
		for (int i = 0; i < la.GetCantidad(); i++) {
			if (la.GetLista()[i]->GetMonto() < 0) {
				myfile << la.GetLista()[i]->Getnombre() << ";" << la.GetLista()[i]->GetApellido() << ";" << la.GetLista()[i]->GetAdminID() << ";" << la.GetLista()[i]->GetCiudad() << ";" << la.GetLista()[i]->GetMonto() << "\n" << std::endl;
				//falta eliminar admin.
			}

		}
		myfile.close();
	}
}
void Principal::ArchivoSalida()
{
	std::ofstream ArchivoClientes("Clientes.txt");
	if (ArchivoClientes.is_open())
	{
		string eventos = "";
		
		

		for (int i = 0; i < lc.GetCantidad(); i++) {
			for (int v = 0; v < lc.GetLista()[i]->GetCantEventos(); v++) {
				eventos = eventos + ";" + lc.GetLista()[i]->getEvento(v);
					
			}


			ArchivoClientes << lc.GetLista()[i]->GetNombre() << ";" << lc.GetLista()[i]->GetApellido() << ";" << lc.GetLista()[i]->GetClienteID() << ";" << lc.GetLista()[i]->GetCiudad() << ";" << lc.GetLista()[i]->GetnTelefono() << ";"<< eventos <<  endl;
			eventos = "";
		}
		ArchivoClientes.close();

	}

		std::ofstream ArchivoAdmins("Administradores.txt");
		
		if (ArchivoAdmins.is_open())
		{
			string eventos = "";

			for (int i = 0; i < la.GetCantidad(); i++) {

				for (int v = 0; v < la.GetLista()[i]->GetCantEventos(); v++) {

					string eventos = eventos + ";" + la.GetLista()[i]->getEvento(v);
					
				}

				ArchivoAdmins << la.GetLista()[i]->Getnombre() << ";" << la.GetLista()[i]->GetApellido() << ";" << la.GetLista()[i]->GetAdminID() << ";" << la.GetLista()[i]->GetCiudad() << ";" << la.GetLista()[i]->GetMonto() << ";"<< eventos << std::endl;
				eventos = "";
				
			}
			ArchivoAdmins.close();

		}

		std::ofstream ArchivoEventos("Eventos.txt");
		if (ArchivoEventos.is_open())
		{//Algoritmo que verifica si el admin es despedido dependiendo de su monto
			for (int i = 0; i < le.GetCantidad(); i++) {
				if (le.GetLista()[i]->GetTipo() == "Realizado") {
					ArchivoEventos << le.GetLista()[i]->Getnombre() << ";" << le.GetLista()[i]->Getciudad() << ";" << le.GetLista()[i]->GetClienteID() << ";" << le.GetLista()[i]->GetAdminID() << ";" << le.GetLista()[i]->GetnEventoID() << ";" << le.GetLista()[i]->GetTipo() << ";" << le.GetLista()[i]->GetEstado() << ";" << le.GetLista()[i]->GetCantEsperado() << ";" << le.GetLista()[i]->GetCantAsistente() <<endl;
				}
				else {
					ArchivoEventos << le.GetLista()[i]->Getnombre() << ";" << le.GetLista()[i]->Getciudad() << ";" << le.GetLista()[i]->GetClienteID() << ";" << le.GetLista()[i]->GetAdminID() << ";" << le.GetLista()[i]->GetnEventoID() << ";" << le.GetLista()[i]->GetTipo() << ";" << le.GetLista()[i]->GetEstado() << ";" << le.GetLista()[i]->GetCantEsperado() <<endl;
				}
			}
			ArchivoEventos.close();

		}

}


