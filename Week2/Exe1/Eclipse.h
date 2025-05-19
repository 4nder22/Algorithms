#ifndef ECLIPSE_H
#define ECLIPSE_H

#include <iostream>
#include <string>

using namespace std;

class Eclipse
{
private:
	string tipoEclipse;
	string fecha;
	int hora;
	char sismos;
	char lluvias;
	string visibilidad;

public:

	//constructor por defecto
	Eclipse() {}
	//constructor con parametros
	Eclipse(string tipoEclipce, string fecha, int hora, char sismos, char lluvias, string visibilidad);
	~Eclipse() {}

	//getters y setters
	string getTipoEclipse();
	string getFecha();
	int    getHora();
	char   getSismos();
	char   getLluvias();
	string getVisibilidad();

	void setTipoEclipse(string tipoEclipce);
	void setFecha(string fecha);
	void setHora(int hora);
	void setSismos(char sismos);
	void setLluvias(char lluvias);
	void setVisibilidad(string visibilidad);

	//otros metodos
	void mostrarEclipse();
};

Eclipse::Eclipse(string tipoEclipce, string fecha, int hora, char sismos, char lluvias, string visibilidad){

}

//implematacion de los metodos getters
string Eclipse::getTipoEclipse() {
	return tipoEclipse;
}
string Eclipse::getFecha() {
	return fecha;
}
int    Eclipse::getHora() {
	return hora;
}
char   Eclipse::getSismos(){
	return sismos;
}
char   Eclipse::getLluvias() {
	return lluvias;
}
string Eclipse::getVisibilidad() {
	return visibilidad;
}

//implemantacion de los metodos setters
void Eclipse::setTipoEclipse(string tipoEclipse) {
	this->tipoEclipse = tipoEclipse;
}
void Eclipse::setFecha(string fecha) {
	this->fecha = fecha;
}
void Eclipse::setHora(int hora) {
	this->hora = hora;
}
void Eclipse::setSismos(char sismos) {
	this->sismos = sismos;
}
void Eclipse::setLluvias(char lluvias) {
	this->lluvias = lluvias;
}
void Eclipse::setVisibilidad(string visibilidad) {
	this->visibilidad = visibilidad;
}

//implematacion de los otros metodos
void Eclipse::mostrarEclipse() {
	cout << "Tipo de Eclipse" << tipoEclipse << endl;
	cout << "Fecha" << fecha << endl;
	cout << "Hora" << hora << endl;
	cout << "Sismos" << (sismos == 'S' ? "Si" : "No") << endl;
	cout << "Lluvias" << (lluvias == 'S' ? "Si" : "No") << endl;
	cout << "Visibilidad" << visibilidad << endl;
}


#endif // !ECLIPSE_H
