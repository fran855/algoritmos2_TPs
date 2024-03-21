#ifndef PARSER_ESCRITORES_H_INCLUDED
#define PARSER_ESCRITORES_H_INCLUDED

#include <fstream>
#include <string>
#include "escritor.h"
#include "lista.h"

using namespace std;

class Parser_escritores{
private:
    string entrada;
    Lista<Escritor> * lista_escritores;
    int id;
    string nombre_apellido;
    string nacionalidad;
    short int anio_nacimiento;
    short int anio_fallecimiento;

public:
    Parser_escritores(Lista<Escritor> * lista, char ** argv);
    ~Parser_escritores();
    void parsear();

private:
    void generar_anonimo();

};


#endif