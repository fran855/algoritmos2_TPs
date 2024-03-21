#ifndef NODO_PUNTERO_TEMPLATE_INCLUDED
#define NODO_PUNTERO_TEMPLATE_INCLUDED

template <class Tipo>

// Los nodos de la cola tienen como datos, punteros a los Nodos de la lista

class Nodo_puntero{
private:
	Tipo* dato;
	Nodo_puntero* siguiente;             

public:
	//Constructor
	//PRE: -
	//POS: construye un nodo con d como dato y siguiente en nullptr
	Nodo_puntero(Tipo* d);

	//PRE: n es un puntero válido
	//POS: cambia el puntero siguiente por n
	void cambiar_siguiente(Nodo_puntero* n);
	
	Tipo* obtener_dato();

	Nodo_puntero* obtener_siguiente();
};

template <class Tipo>
Nodo_puntero<Tipo>::Nodo_puntero(Tipo* d){
    dato = d;
    siguiente = nullptr;
}

template <class Tipo>
void Nodo_puntero<Tipo>::cambiar_siguiente(Nodo_puntero* n){
	siguiente = n;
}

template <class Tipo>
Tipo* Nodo_puntero<Tipo>::obtener_dato(){
	return dato;
}

template <class Tipo>
Nodo_puntero<Tipo>* Nodo_puntero<Tipo>::obtener_siguiente(){
	return siguiente;
}

#endif