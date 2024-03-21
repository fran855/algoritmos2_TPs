#ifndef PARSER_LECTURAS_H
#define PARSER_LECTURAS_H

#include "lectura.h"
#include "lista.h"
#include "escritor.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"
#include <fstream>
#include <string>


class Parser_lectura {

public:
    //Constructor
    //PRE:
    //POS:
    Parser_lectura(char** argv);
    
    //Procesar datos
    //PRE:
    //POS:
    void procesar_datos(Lista<Escritor>* lista_escritores, Lista<Lectura>* lista_lecturas);

    //Destructor
    //PRE:
    //POS:
    ~Parser_lectura(){};

/*
    //Lista
    //PRE:
    //POS:
    Lista<Lectura> listar_lecturas(Lista<Escritor>* lista_escritores);
*/
private:
    ifstream archivo_lectura;
    string tipo_lectura;
    string auxiliar;

    //Lectura generico
    
    string titulo;
    unsigned int minutos;
    unsigned short int anio;
    Escritor* autor;
    Escritor* obtener_autor(Lista<Escritor>* lista_escritores);
    Escritor* obtener_autor(Lista<Escritor>* lista_escritores, string auxiliar);


    //Especificos
    char* tema;
    string libro;
    unsigned int versos;
    genero_t genero;

    char* obtener_tema(string tema);
};

#endif