#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "lectura.h"
#include "nodo_puntero.h"
#include "lista.h"

using namespace std;

template <class Tipo> class Cola {
  // Atributos
private:
  Nodo_puntero<Tipo>* primero;
  Nodo_puntero<Tipo>* ultimo;

  // Metodos
public:
  // Constructor
  // PRE: -
  // POS: Construye una Cola vacía
  Cola();

  // Alta
  // PRE: elemento es un puntero valido
  // POS: agrega el elemento al final de la Cola
  void alta(Tipo* elemento);

  // Baja
  // PRE: la Pila no puede estar vacía -> necesito otro método
  // POS: quita el elemento del principio de la Cola [y  podría, por costumbre,
  // devolverlo]
  void baja();

  // Consulta
  // PRE: la Pila no puede estar vacía
  // POS: muestra los datos del elemento al principio de la Cola (pero no modifica)
  void consulta();

  // Vacía
  // PRE: -
  // POS: devuelve true si la Cola está vacía, false de lo contrario
  bool vacia();  

  // Toma una lista y arma una cola ordenada
  // PRE: lista debe ser un puntero valido a una lista
  // POS: -
  void encolar(Lista<Tipo>* lista);

  // Destructor
  ~Cola();
};

// Constructor
template <class Tipo>
Cola<Tipo>::Cola(){
  primero = nullptr;
  ultimo = nullptr;
}

// Alta
template <class Tipo>
void Cola<Tipo>::alta(Tipo* elemento){
	Nodo_puntero<Tipo>* nuevo = new Nodo_puntero<Tipo>(elemento);
	if (primero)
    ultimo -> cambiar_siguiente(nuevo);
  else 
    primero = nuevo;
  ultimo = nuevo;
}

// Baja
template <class Tipo>
void Cola<Tipo>::baja(){
  Nodo_puntero<Tipo>* borrar = primero;
  primero = primero -> obtener_siguiente();
  if (ultimo -> obtener_siguiente()){
    ultimo = ultimo -> obtener_siguiente();
  };
  delete borrar;
  
}

// Consulta
template <class Tipo>
void Cola<Tipo>::consulta(){
  primero -> obtener_dato() -> mostrar();
}

// Vacia
template <class Tipo>
bool Cola<Tipo>::vacia(){
  return primero == nullptr;
}

// Destructor
template <class Tipo>
Cola<Tipo>::~Cola(){
  while(!vacia())
    baja();
}

// Voy a recorrer la lista y armar la cola
template <class Tipo>  
void Cola<Tipo>::encolar(Lista<Tipo>* lista){
  Nodo<Tipo>* minimo = nullptr;
  unsigned int minutos_anterior = 0;

  for (int i = 0; i < lista -> obtener_cantidad(); i++){
    minimo = lista -> encontrar_minimo(minimo, minutos_anterior);
    alta(minimo -> obtener_dato('p'));
    minutos_anterior = ((minimo -> obtener_dato()).obtener_minutos());
  }
  
};

#endif