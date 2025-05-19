#ifndef CONTROLADOR_ECLIPSE_H
#define CONTROLADOR_ECLIPSE_H

#include <iostream>
#include <string>
#include "VectorEclipse.h"

using namespace std;

class Controlador
{
private:
	VectorEclipse* vectorEclipses;
public:
	Controlador();
	~Controlador();

	void registrarDatos();
	void modificarDatos();
	void eliminarDatos();

	void reporteTodosEclipses();
	void reporteElipsesEuropa();
	void reporteElipsesSismos();
	void reporteElipsesNoche();
	bool existenEclipses();

};

Controlador::Controlador(){
	VectorEclipse* vectorEclipses = new VectorEclipse();

}

Controlador::~Controlador(){
	delete[] vectorEclipses;
}

void Controlador::registrarDatos() {

	string tipoEclipse;
	string fecha;
	int hora;
	char sismos;
	char lluvias;
	string visibilidad;
	cout << "Ingrese el tipo de eclipse (Solar o Lunar): ";
	cin.ignore();
	getline(cin, tipoEclipse);
	cout << "\nIngrese la fecha (dd/mm/aa): ";
	getline(cin, fecha);

	do
	{
		cout << "\nIngrese la hora: ";
		cin >> hora;
	} while (hora < 100 || hora>2400);

	do
	{
		cout << "Hubo sismos?: ";
		cin >> sismos;
		sismos = toupper(sismos);

		if (sismos != 'S' && sismos != 'N') {
			cout << "Respuesta invalida. Ingrese 'S' o 'N'.\n";
		}
	} while (sismos != 'S' && sismos != 'N');

	do
	{
		cout << "Hubo lluvias?: ";
		cin >> lluvias;
		lluvias = toupper(lluvias);

		if (lluvias != 'S' && lluvias != 'N') {
			cout << "Respuesta invalida. Ingrese 'S' o 'N'.\n";
		}
	} while (lluvias != 'S' && lluvias != 'N');

	cout << "Continente con mayor visibilidad: ";
	cin.ignore();
	getline(cin, visibilidad);

	Eclipse* eclipse = new Eclipse(tipoEclipse, fecha, hora, sismos, lluvias, visibilidad);
	vectorEclipses->registrarEclipse(eclipse);
}
void Controlador::modificarDatos() {
	string tipoEclipse;
	string fecha;
	int hora;
	char sismos;
	char lluvias;
	string visibilidad;

	int opcion, indice;
	cout << "Ingrese el indice del eclipse a modificar: "; cin >> indice;
	if (indice < 0 || indice >= vectorEclipses->getNumeroEclipses())
	{
		cout << "\nIndice fuera de rango!" << endl; 
		return;
	}

	Eclipse* eclipse = vectorEclipses->obtenerDatosEclipse(indice);

	do
	{
		cout << "Seleccione el atributo a modificar:" << endl;
		cout << "1. Tipo de Eclipse" << endl;
		cout << "2. Fecha" << endl;
		cout << "3. Hora" << endl;
		cout << "4. Sismos" << endl;
		cout << "5. Lluvias" << endl;
		cout << "6. Visibilidad" << endl;
		cout << "0. Terminar modificaciones" << endl;
		cout << "Ingresar Opcion: "; cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "Ingrese el nuevo tipo de eclipse: ";
			cin.ignore();
			getline(cin, tipoEclipse);
			eclipse->setTipoEclipse(tipoEclipse);
			system("pause>0");
			break;
		case 2:
			system("cls");
			cout << "Ingrese la nueva fecha: ";
			cin.ignore();
			getline(cin, fecha);
			eclipse->setFecha(fecha);
			system("pause>0");
			break;
		case 3:
			system("cls");
			do
			{
				cout << "Ingrese la nueva hora: "; cin >> hora;
			} while (hora < 100 || hora > 2400);
			eclipse->setHora(hora);
			system("pause>0");
			break;
		case 4:
			system("cls");
			do
			{
				cout << "Hubo Sismos?: "; cin >> sismos;
				sismos = toupper(sismos);
			} while (sismos != 'S' && sismos != 'N');
			eclipse->setSismos(sismos);
			system("pause>0");
			break;
		case 5:
			system("cls");
			do
			{
				cout << "Hubo Lluvias?: "; cin >> lluvias;
				lluvias = toupper(lluvias);
			} while (lluvias != 'S' && lluvias != 'N');
			eclipse->setLluvias(lluvias);
			system("pause>0");
			break;
		case 6:
			system("cls");
			cout << "Ingrese el nuevo continente de mayor visibilidad: ";
			cin.ignore();
			getline(cin, visibilidad);
			eclipse->setVisibilidad(visibilidad);
			system("pause>0");
			break;
		case 0:
			break;
		}
		system("cls");
	} while (opcion != 0);
	cout << "SE MODIFICO CON EXITO LOS DATOS DEL ECLIPSE!!" << endl;
}
void Controlador::eliminarDatos(){
	int indice;
	cout << "Ingrese el indice del eclipse a eliminar: "; cin >> indice;
	if (indice < 0 || indice >= vectorEclipses->getNumeroEclipses())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	vectorEclipses->eliminarEclipse(indice);
	cout << "\nSE ELIMINO CON EXITO LOS DATOS DEL ECLIPSE!!" << endl;
}
void Controlador::reporteTodosEclipses() {
	cout << "\t\tREPORTE DE TODOS LOS ECLIPSES\n\n";
	for (int i = 0; i < vectorEclipses->getNumeroEclipses(); i++)
	{
		vectorEclipses->obtenerDatosEclipse(i)->mostrarEclipse();
		cout << endl;
	}
}
void Controlador::reporteElipsesEuropa() {
	bool found = false;
	for (int i = 0; i < vectorEclipses->getNumeroEclipses(); i++)
	{
		if (vectorEclipses->obtenerDatosEclipse(i)->getVisibilidad() == "Europa")
		{
			if (!found)
			{
				cout << "\t\tECLIPSES VISIBLES EN EUROPA\n\n";
				found = true;
			}
			vectorEclipses->obtenerDatosEclipse(i)->mostrarEclipse();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY ECLIPSES QUE SON VISIBLES EN EUROPA" << endl;
	}
}
void Controlador::reporteElipsesSismos() {
	bool found = false;
	for (int i = 0; i < vectorEclipses->getNumeroEclipses(); i++)
	{
		if (vectorEclipses->obtenerDatosEclipse(i)->getSismos() == 'S')
		{
			if (!found)
			{
				cout << "\t\tECLIPSES QUE OCASIONARON SISMOS\n\n";
				found = true;
			}
			vectorEclipses->obtenerDatosEclipse(i)->mostrarEclipse();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY ECLIPSES QUE OCASIONARON SISMOS" << endl;
	}
}
void Controlador::reporteElipsesNoche() {
	bool found = false;
	for (int i = 0; i < vectorEclipses->getNumeroEclipses(); i++)
	{
		int hora = vectorEclipses->obtenerDatosEclipse(i)->getHora();
		if ((hora >= 1800 || hora < 600) && vectorEclipses->obtenerDatosEclipse(i)->getTipoEclipse() == "Lunar")
		{
			if (!found)
			{
				cout << "\t\tECLIPSES QUE SE PRODUJERON EN LA NOCHE\n\n";
				found = true;
			}
			vectorEclipses->obtenerDatosEclipse(i)->mostrarEclipse();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY ECLIPSES QUE SE PRODUJERON EN LA NOCHE" << endl;
	}
}
bool Controlador::existenEclipses() {
	return vectorEclipses->getNumeroEclipses() > 0;
}



#endif // !CONTROLADOR_ECLIPSE_H
