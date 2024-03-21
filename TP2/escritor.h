#ifndef ESCRITOR_H_INCLUDED
#define ESCRITOR_H_INCLUDED

#include <string>

using namespace std;

class Escritor{
private:
    int id;
    string nombre_apellido;
    string nacionalidad;
    short int anio_nacimiento;
    short int anio_fallecimiento;

public:
	
    void operator=(Escritor escritor2);
    
    //Escritor();

    //Constructor
    //PRE: nombre_apellido, nacionalidad strings no vacías, anio_nacimiento y anio_fallecimiento > 0 o -1 si no se conoce
    //POS: construye un objeto del tipo Escritor con los parámetros ingresados
    Escritor(int id, string nombre_apellido, string nacionalidad, short int anio_nacimiento, short int anio_fallecimiento);

    //mostrar
    //PRE: -
    //POS: muestra por pantalla los datos del escritor
    void mostrar();

    //obtener_id
    //PRE: -
    //POS: devuelve el ID del escritor
    int obtener_id();

    //obtener_nombre_apellido
    //PRE: -
    //POS: devuelve el nombre y el apellido (juntos)
    string obtener_nombre_apellido();

    //obtener_nacionalidad
    //PRE: -
    //POS: devuelve la nacionalidad
    string obtener_nacionalidad();

    //obtener_anio_nacimiento
    //PRE: -
    //POS: devuelve el año de nacimiento
    short int obtener_anio_nacimiento();

    //obtener_anio_fallecimiento
    //PRE: -
    //POS: devuelve el año de fallecimiento
    short int obtener_anio_fallecimiento();

    //cambiar_fallecimiento
    //PRE: nuevo_anio >= 0
    //POS: modifica anio_fallecimiento del escritor por nuevo_anio
    void cambiar_fallecimiento(short int nuevo_anio);

    //obtener_direccion
    //PRE:
    //POS:
    Escritor * obtener_direccion();

    //Destructor
    ~Escritor();
};

#endif