#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "lista.h"
#include "genero.h"

using namespace std;

const string MSJ_CABECERA_MENU = "Bienvenido al club de lectura de Sid!\nIngresa a continuacion la opcion deseada:\n1. Agregar una lectura a la lista.\n2. Quitar una lectura de la lista.\n3. Agregar un escritor.\n4. Cambiar fecha de fallecimiento de un autor.\n5. Listar los escritores.\n6. Mostrar una lectura random!\n7. Mostrar todas las lecturas.\n8. Mostrar lecturas en un periodo de anios.\n9. Mostrar lecturas segun autor.\n10. Mostrar novelas segun genero.\n11. Generar una cola de lectura segun tiempo aproximado de lectura (menor a mayor).\n12. Salir del club de lectura.";
const string MSJ_INGRESAR_TIPO_LECTURA = "Ingrese N (Novela), C (Cuento) o P (Poeta):";
const string MSJ_INGRESAR_TITULO = "Ingrese el titulo de la obra:";
const string MSJ_INGRESAR_MINUTOS = "Ingrese los minutos estimados de lectura";
const string MSJ_INGRESAR_ANIO = "Ingrese el anio de publicacion de la obra:";
const string MSJ_INRGESAR_INFO_LECTURA = "Ingrese la informacion correspondiente segun\nSi es novela, va el género\nSi es novela histórica, va el tema\nSi es cuento, va el título del libro en donde está publicado\nSi es un poema, va la cantidad de versos";
const string MSJ_INRGESAR_REFERENCIA_AUTOR = "Ingrese la referencia al autor correspondiente:";
const string MSJ_TEMA_LECTURA = "Ingrese el tema de la lectura:";
const string MSJ_BAJA_LISTA = "Ingrese la posicion en la lista de la lectura que quiere quitar:";
const string MSJ_ESCRITOR_FALLECIMIENTO = "Inrgese el nuemero de referencia al autor cuyo fallecimiento quiere actualizar:";
const string MSJ_ANIO_FALLECIMIENTO = "Inrgese el anio actualizado de fallecimiento:";
const string MSJ_INTERVALO_ANIOS = "Ingrese el intervalo de anios deseado:";
const string MSJ_LISTAR_LECTURAS_ESCRITOR = "Ingrese el ID del escritor para ver sus obras:";
const string MSJ_INGRESAR_GENERO = "Ingrese el genero de las obras que quiere buscar:";
const string MSJ_MOSTRAR_COLA = "Se muestra el siguiente elemento de la cola:";
const string MSJ_HA_LEIDO = "¿Ha sido leida la obra? Ingresar 1 (verdadero) o 0 (falso)";
 
enum Opciones_menu {
    NUEVA_LECTURA,
    QUITAR_LECTURA,
    QUITAR_ESCRITOR,
    CAMBIAR_DATO_ESCRITOR,
    LISTAR_ESCRITORES,
    LECTURA_RANDOM,
    LISTAR_LECTURAS_TODAS,
    LISTAR_LECTURAS_ANIOS,
    LISTAR_LECTURAS_ESCRITOR,
    LISTAR_NOVELAS_GENERO,
    CREAR_COLA,
    SALIR
};

template <class Tipo>
class Menu {
private:
    int eleccion;

public:
    // Constructor por defecto
    Menu(){};

    // Destructor por defecto
    ~Menu(){};

    // Ejecuta el menu para que el usuario pueda ingresar la accion por realizar
    void ejecutar_menu(Lista<Tipo>& lista_1, Lista<Tipo>& lista_2);

    void nueva_lectura(Lista<Lectura>& lista_lecturas, Lista<Escritor>& lista_escritores);

    void quitar_lectura();

    void quitar_escritor();

    void cambiar_dato_escritor();

    void listar_escritores();

    void listar_escritores();

    void mostrar_lectura_random(Lista<Lectura>& lista_lecturas);

    void listar_lecturas_todas();

    void listar_lecturas_anios();

    void listar_lecturas_escritor();

    void listar_novelas_genero();

    void crear_cola();

};

template <class Tipo>
void Menu<Tipo>::ejecutar_menu(Lista<Tipo>& lista_lecturas, Lista<Tipo>& lista_escritores){
    srand((unsigned) time(0));
    do {
        cout << MSJ_CABECERA_MENU << endl;
        cin >> eleccion;

        switch (eleccion) {

        case NUEVA_LECTURA:
            nueva_lectura();
            break;

        case QUITAR_LECTURA:
            quitar_lectura();
            break;

        case QUITAR_ESCRITOR:
            quitar_escritor();
            break;

        case CAMBIAR_DATO_ESCRITOR:
            cambiar_dato_escritor();
            break;

        case LISTAR_ESCRITORES:
            listar_escritores();
            break;

        case LECTURA_RANDOM:
            mostrar_lectura_random();
            break;

        case LISTAR_LECTURAS_TODAS:
            listar_lecturas_todas();
            break;

        case LISTAR_LECTURAS_ANIOS:
            listar_lecturas_anios();
            break;

        case LISTAR_LECTURAS_ESCRITOR:
            listar_lecturas_escritor();
            break;

        case LISTAR_NOVELAS_GENERO:
            listar_novelas_genero();
            break;

        case CREAR_COLA:
            crear_cola();
            break;

        case SALIR:
            return;
        
        default: 
            break;
        }

    } while (eleccion != SALIR);
};

template <class Tipo>
void Menu<Tipo>::nueva_lectura(Lista<Lectura>& lista_lecturas, Lista<Escritor>& lista_escritores){
    string tipo_lectura;
    string titulo;
    string auxiliar;
    unsigned int minutos;
    unsigned short int anio; 
    Escritor* autor;

    //Especificos
    char* tema;
    string libro;
    unsigned int versos;
    genero_t genero;

    cout << MSJ_INGRESAR_TIPO_LECTURA << endl;
    getline(cin, tipo_lectura);
    
    cout << MSJ_INGRESAR_TITULO << endl;
    getline(cin, titulo);
    
    cout << MSJ_INGRESAR_MINUTOS << endl;
    getline(cin, auxiliar);
    minutos = stoi(auxiliar);

    cout << MSJ_INGRESAR_ANIO << endl;
    getline(cin, auxiliar);  //anio
    anio = stoi(auxiliar);

    cout << MSJ_INRGESAR_INFO_LECTURA << endl;
    if (tipo_lectura == "C"){
      getline(cin, libro);
      autor = obtener_autor(lista_escritores);
      nueva_lectura = new Cuento(titulo, minutos, anio, libro, autor);
      lista_lecturas -> alta(nueva_lectura, ++contador); // Aca tendria que darse de alta ordenado
    }
    else if (tipo_lectura == "N"){
      getline(cin, auxiliar);
      genero = string_to_genero(auxiliar);
      
      if (genero == HISTORICA){
        cout << MSJ_TEMA_LECTURA << endl;
        getline(cin, auxiliar);
        tema = obtener_tema(auxiliar);
        cout << MSJ_INRGESAR_REFERENCIA_AUTOR << endl;
        getline(cin, auxiliar);
        autor = obtener_autor(lista_escritores, auxiliar);
        nueva_lectura = new Novela_historica(titulo, minutos, anio, tema, autor);
        lista_lecturas -> alta(nueva_lectura, ++contador); // Aca tendria que darse de alta ordenado
      }else{
        cout << MSJ_INRGESAR_REFERENCIA_AUTOR << endl;
        getline(cin, auxiliar);
        autor = obtener_autor(lista_escritores, auxiliar);
        nueva_lectura = new Novela(titulo, minutos, anio, genero, autor);
        lista_lecturas -> alta(nueva_lectura, ++contador); // Aca tendria que darse de alta ordenado
      }
    }
    else if (tipo_lectura == "P") {
      getline(cin, auxiliar);
      versos = stoi(auxiliar);
      cout << MSJ_INRGESAR_REFERENCIA_AUTOR << endl;
      getline(cin, auxiliar);
      autor = obtener_autor(lista_escritores, auxiliar);
      nueva_lectura = new Poema(titulo, minutos, anio, versos, autor);
      lista_lecturas -> alta(nueva_lectura, ++contador); // Aca tendria que darse de alta ordenado
    }
};

template <class Tipo>
void Menu<Tipo>::quitar_lectura(){
    int posicion;
    cout << MSJ_BAJA_LISTA << endl;
    cin >> posicion;
    lista_lecturas.baja(posicion);
};

template <class Tipo>
void Menu<Tipo>::quitar_escritor(){
    int posicion;
    cout << MSJ_BAJA_LISTA << endl;
    cin >> posicion;
    lista_escritores.baja(posicion);
};

template <class Tipo>
void Menu<Tipo>::cambiar_dato_escritor(){
    int anio_fallecimiento_actualizado;
    int referencia;
    cout << MSJ_ESCRITOR_FALLECIMIENTO << endl;
    cin >> referencia;
    cout << MSJ_ANIO_FALLECIMIENTO << endl;
    cin >> anio_fallecimiento_actualizado;
    lista_escritores.consulta(referencia) -> obtener_dato() -> cambiar_fallecimiento(anio_fallecimiento_actualizado);
};


template <class Tipo>
void Menu<Tipo>::listar_escritores(){
    lista_escritores.mostrar();
};

template <class Tipo>
void Menu<Tipo>::mostrar_lectura_random(Lista<Lectura>& lista_lecturas){
    lista_lecturas.consulta(rand() % (lista_lecturas.obtener_cantidad()) + 1);
};

template <class Tipo>
void Menu<Tipo>::listar_lecturas_todas(){
    lista_lecturas.mostrar();
};

template <class Tipo>
void Menu<Tipo>::listar_lecturas_anios(){
    int cota_inferior, cota_superior;
    cout << MSJ_INTERVALO_ANIOS << endl;
    cin >> cota_inferior;
    cin >> cota_superior;

    /* Implementar mostrar(cota_inferior, cota_superior) */
};

template <class Tipo>
void Menu<Tipo>::listar_lecturas_escritor(){
    int id;
    cout << MSJ_LISTAR_LECTURAS_ESCRITOR << endl;
    /* Implementar mostrar(escritor)
        podemos recorrer la lista y mostrar los que tengan
        el mismo ID de escritor */
};

template <class Tipo>
void Menu<Tipo>::listar_novelas_genero(){
    string aux;
    genero_t genero;
    cout << MSJ_INGRESAR_GENERO << endl;
    cin >> aux;
    genero.string_to_genero(aux);
    /* Implementar mostrar(genero) */
};

template <class Tipo>
void Menu<Tipo>::crear_cola(){
    bool fue_leido;
    Cola<Lectura> la_cola;
            
    la_cola.encolar(&lista_lecturas);
    cout << MSJ_MOSTRAR_COLA << endl;
    la_cola.consulta();
    cout << MSJ_HA_LEIDO << endl;
    cin >> fue_leido;

    do {
        la_cola.baja();
        cout << MSJ_MOSTRAR_COLA << endl;
        la_cola.consulta();
        cout << MSJ_HA_LEIDO << endl;
        cin >> fue_leido;
    } while (fue_leido == true);
};

#endif