#include "parser_escritores.h"
#include "parser_lecturas.h"
#include <fstream>
#include <iostream>
#include "escritor.h"
#include "lista.h"
#include "cola.h"

int main(int argc, char * argv[]){
  
  Lista<Escritor>* lista_escritores = new Lista<Escritor>;
	Lista<Lectura>* lista_lecturas = new Lista<Lectura>;

  Parser_escritores parser_escritores(lista_escritores, argv);
	parser_escritores.parsear();

  Parser_lectura parser_lecturas(argv);
  parser_lecturas.procesar_datos(lista_escritores, lista_lecturas);

  Cola <Lectura> cola;
  cola.encolar(lista_lecturas);
  cola.mostrar();
  /* cola.primero->obtener_dato()->mostrar();
  cola.primero->obtener_siguiente()->obtener_dato()->mostrar();
  cola.primero->obtener_siguiente()->obtener_siguiente()->obtener_dato()->mostrar();
  cola.primero->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_dato()->mostrar();
  cola.primero->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_dato()->mostrar();
  cola.primero->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_dato()->mostrar();
  cola.primero->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_siguiente()->obtener_dato()->mostrar();
 */
//  delete lista_escritores;
//  delete lista_lecturas;

  return 0;
}