#include <iostream>
#include "escritor.h"

/* Escritor::Escritor(){
    this -> id = 0;
    this -> nombre_apellido = "ANONIMO";
    this -> nacionalidad = "¿?";
    this -> anio_nacimiento = -1;
    this -> anio_fallecimiento = -1; 
} */

Escritor::Escritor(int id, string nombre_apellido, string nacionalidad, short int anio_nacimiento, short int anio_fallecimiento){
    this -> id = id;
    this -> nombre_apellido = nombre_apellido;
    this -> nacionalidad = nacionalidad;
    this -> anio_nacimiento = anio_nacimiento;
    this -> anio_fallecimiento = anio_fallecimiento;
}

void Escritor::mostrar(){
    cout << "ID: " << id << endl;
    cout << "Nombre y apellido: "<< nombre_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Año de nacimiento: " << anio_nacimiento << endl;
    cout << "Año de fallecimiento: " << anio_fallecimiento << endl;
}

int Escritor::obtener_id(){
    return id;
}

string Escritor::obtener_nombre_apellido(){
    return nombre_apellido;
}

string Escritor::obtener_nacionalidad(){
    return nacionalidad;
}

short int Escritor::obtener_anio_nacimiento(){
    return anio_nacimiento;
}

short int Escritor::obtener_anio_fallecimiento(){
    return anio_fallecimiento;
}

void Escritor::cambiar_fallecimiento(short int nuevo_anio){
    anio_fallecimiento = nuevo_anio;
}

/* Escritor* Escritor::obtener_direccion(){
    return this;
} */

Escritor::~Escritor(){
}

void Escritor::operator=(Escritor escritor2){
	this -> id = escritor2.id;
	this -> nombre_apellido = escritor2.nombre_apellido;
    this -> nacionalidad = escritor2.nacionalidad;
	this -> anio_nacimiento = escritor2.anio_nacimiento;
	this -> anio_fallecimiento = escritor2.anio_fallecimiento;
}