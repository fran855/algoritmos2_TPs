#include <iostream>
#include "lectura.h"
#include "escritor.h"

Lectura::Lectura (string titulo, unsigned int minutos, unsigned short int anio, Escritor* autor) {
    this -> titulo = titulo;
    this -> minutos = minutos;
    this -> anio = anio;
    this -> autor = autor;
}

Lectura::~Lectura(){}

int Lectura::comparar(Lectura& lectura){
    int resultado;
    if (this -> anio < lectura.obtener_anio())
        resultado = -1;
    else if (this -> anio == lectura.obtener_anio())
        resultado = 0;
    else
        resultado = 1;
    return resultado;
};

int Lectura::comparar(Lectura * lectura, char m){
    int resultado;
    if (this -> minutos < lectura -> obtener_minutos())
        resultado = -1;
    else if (this -> minutos == lectura -> obtener_minutos())
        resultado = 0;
    else
        resultado = 1;
    return resultado;
};


string Lectura::obtener_titulo() {
    return this -> titulo;
}

unsigned int Lectura::obtener_minutos() {
    return this -> minutos;
}

unsigned short int Lectura::obtener_anio() {
    return this-> anio;
}

Escritor* Lectura::obtener_autor() {
    return this -> autor;
}


/* void Lectura::operator=(Lectura lectura2){
  this -> titulo = lectura2. titulo;
  this -> minutos = lectura2.minutos;
  this -> anio = lectura2.anio;
  this -> autor = lectura2.autor;
} */