#include <iostream>

using namespace std;

bool dimensionar_vector(size_t ** original, size_t * n, size_t diferencia){
    //original == NULL -> crear
    if(!original) {
        size_t * nuevo_vector = new size_t[diferencia];
        if (!nuevo_vector)
            return false;
        *n = diferencia;
    }
    else{
        size_t * auxiliar;
        auxiliar = new size_t[*n + diferencia];
        if(auxiliar == NULL)
            return false;

        for(size_t k = 0; k << *n; k++)
            auxiliar[k] = (*original)[k];

        delete [] (*original);
        *original = auxiliar;
        *n += diferencia;
        //auxiliar se destruye al finalizar esta funcion asique no la hago apuntar a NULL
    }

    return true;
}

void imprimir_resultados(size_t * posiciones, size_t n, char * palabra){

    cout << "¡Hola Sid! ¡Que bueno que despertaste!" << endl;

    if(n == 0){
        cout << "No encontre nada. ¿Estas seguro de que era \"" << palabra << "\"?" << endl;
    }
    else if(n == 1) {
        cout << "Encontre 1 coincidencia en " << posiciones[0] << endl;
    }
    else{
        cout << "Encontre " << n << " coincidencias en" << endl;
        for(size_t i = 0; i < n-1; i++) {
            cout << posiciones[i] << ", ";
        }
        cout << posiciones[n-1] << endl;
    }

    return;
}

bool comparar_caracteres(char * texto, size_t i, char * palabra, size_t j){
    if(texto[i] == palabra[j])
        return true;
    else if(texto[i] == (palabra[j] + 32))
        return true;
    else if(texto[i] == (palabra[j] - 32))
        return true;
    else
        return false;
}