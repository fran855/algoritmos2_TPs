#include "parser_lecturas.h"
using namespace std;

Parser_lectura::Parser_lectura(char** argv) {
  archivo_lectura.open(argv[2]);
}

Escritor* Parser_lectura::obtener_autor(Lista<Escritor>* lista_escritores){
  getline(archivo_lectura, auxiliar);
  auxiliar.replace (0,  1, " ");
  int id = stoi(auxiliar);
  return lista_escritores -> consulta(id);
}

Escritor* Parser_lectura::obtener_autor(Lista<Escritor>* lista_escritores, string auxiliar){
  auxiliar.replace (0,  1, " ");
  int id = stoi(auxiliar);
  return lista_escritores -> consulta(id);
}

char* Parser_lectura::obtener_tema(string tema){
  char * copia = new char[tema.size() + 1];
  copy(tema.begin(), tema.end(), copia);
  copia[tema.size()] = '\0';
  return copia;
}

void Parser_lectura:: procesar_datos(Lista<Escritor>* lista_escritores, Lista<Lectura>* lista_lecturas){
  int contador = 0;
  Lectura* nueva_lectura;
  while(!archivo_lectura.eof()){
    getline(archivo_lectura, tipo_lectura);
    getline(archivo_lectura, titulo);    //titulo
    getline(archivo_lectura, auxiliar);  //minutos
    minutos = stoi(auxiliar);
    getline(archivo_lectura, auxiliar);  //anio
    anio = stoi(auxiliar);

    if (tipo_lectura == "C"){
      getline(archivo_lectura, libro);
      autor = obtener_autor(lista_escritores);
      nueva_lectura = new Cuento(titulo, minutos, anio, libro, autor);
      lista_lecturas -> alta(nueva_lectura, ++contador);
    }
    else if (tipo_lectura == "N"){
      getline(archivo_lectura, auxiliar);
      genero = string_to_genero(auxiliar);
      
      if (genero == HISTORICA){
        getline(archivo_lectura, auxiliar);
        tema = obtener_tema(auxiliar);
        autor = obtener_autor(lista_escritores);
        nueva_lectura = new Novela_historica(titulo, minutos, anio, tema, autor);
        lista_lecturas -> alta(nueva_lectura, ++contador);
      }else{
        autor = obtener_autor(lista_escritores);
        nueva_lectura = new Novela(titulo, minutos, anio, genero, autor);
        lista_lecturas -> alta(nueva_lectura, ++contador);
      }
    }
    else if (tipo_lectura == "P") {
      getline(archivo_lectura, auxiliar);
      versos = stoi(auxiliar);
      autor = obtener_autor(lista_escritores);
      nueva_lectura = new Poema(titulo, minutos, anio, versos, autor);
      lista_lecturas -> alta(nueva_lectura, ++contador);
    }
  
    getline(archivo_lectura, auxiliar); //saca el separador
  }
}

/*
Lista<Lectura> Parser_lectura:: listar_lecturas(Lista<Escritor>* lista_escritores){
  Lista<Lectura> lista_lecturas;
  int contador = 0;
  
  while(!archivo_lectura.eof()){
    lista_lecturas.alta(procesar_datos(lista_escritores), ++contador);
    getline(archivo_lectura, auxiliar);
  }
  return lista_lecturas;
}
*/