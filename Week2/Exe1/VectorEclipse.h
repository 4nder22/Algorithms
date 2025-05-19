#ifndef VECTOR_ECLIPCE_H
#define VECTOR_ECLIPCE_H

#include <iostream>
#include <string>
#include "Eclipse.h"

using namespace std;

class VectorEclipse
{
private:
	int numeroEclipses;
	Eclipse** eclipses;
public:
	VectorEclipse();
	~VectorEclipse();

	//registrar eclipces
	void registrarEclipse(Eclipse* eclipse);
	//modificar datos
	void modificarEclipse(int indice, Eclipse* nuevoEclipse);
	//eliminar dato
	void eliminarEclipse(int indice);

	int getNumeroEclipses();
	Eclipse* obtenerDatosEclipse(int indice);
};

//implemtacion de metodos
VectorEclipse::VectorEclipse() {
	numeroEclipses = 0;
	eclipses = nullptr;
}

//liberar memoria
VectorEclipse::~VectorEclipse() {
	if (eclipses!=nullptr)
	{
		for (int i = 0; i < numeroEclipses; i++)
		{
			delete eclipses[i];
		}
		delete[] eclipses;
	}
}

void VectorEclipse::registrarEclipse(Eclipse* eclipse) {

	Eclipse** temp = new Eclipse* [numeroEclipses + 1];
	for (int i = 0; i < numeroEclipses; i++)
	{
		temp[i] = eclipses[i];
	}

	temp[numeroEclipses] = eclipse;
	numeroEclipses++;
	delete[] eclipses;
	eclipses = temp;
}

void VectorEclipse::modificarEclipse(int indice, Eclipse* nuevoEclipse) {
	if (indice < 0 || indice >= numeroEclipses)
	{
		cout << "Indice fuera del rango!" << endl; 
		return;
	}
	delete eclipses[indice];
	eclipses[indice] = nuevoEclipse;
}

void VectorEclipse::eliminarEclipse(int indice) {
	if (indice < 0 || indice >= numeroEclipses)
	{
		cout << "Indice fuera del rango!" << endl;
		return;
	}
	delete eclipses[indice];
	Eclipse** temp = new Eclipse * [numeroEclipses - 1];
	int j = 0;
	for (int i = 0; i < numeroEclipses; i++)
	{
		if (i!=indice)
		{
			temp[j++] = eclipses[i];

		}
	}

	delete[] eclipses;
	eclipses = temp;
	numeroEclipses--;

}

int VectorEclipse::getNumeroEclipses() {
	return numeroEclipses;
}

Eclipse* VectorEclipse::obtenerDatosEclipse(int indice) {
	if (indice < 0 || indice >= numeroEclipses)
	{
		cout << "Indice fuera del rango!" << endl;
		return nullptr;
	}

	return eclipses[indice];
}

#endif // !VECTOR_ECLIPCE_H
