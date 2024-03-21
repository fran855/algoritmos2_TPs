#include <iostream>
#include "funciones.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 3) {
        cout << "¡Hola, Sid! Necesito mas datos. Proba " << argv[0] << " <texto> <busqueda>" << endl;
        return 1;
    }

    size_t i, j, n_pedido, n_usado;
    size_t *coincidencias = NULL;
    char *texto, *palabra;
    bool flag;

    texto = argv[1];
    palabra = argv[2];
    n_usado = 0;
    n_pedido = 0;

    flag = dimensionar_vector(&coincidencias, &n_pedido, 10);
    if (!flag) {
        return 1;
    }

    bool comparador;

    for (i = 0, j = 0; texto[i] != '\0'; i++) {
        comparador = comparar_caracteres(texto, i, palabra, j);

        if ((comparador == false) && (palabra[j] != '\0')) {
            j = 0;

        } else if ((comparador == true) && (palabra[j] != '\0')) {
            j++;
        } else { //como texto[i] != '\0' solo queda la opcion texto[i] != palabra[j] && palabra[j] == '\0' (hubo coincidencia)
            if (n_pedido == n_usado) {
                flag = dimensionar_vector(&coincidencias, &n_pedido, 5);
                if (!flag) {
                    delete[] coincidencias;
                    return 1;
                }
            }

            coincidencias[n_usado] = i - j;
            n_usado++;
            j = 0;
            i--;
        }
    }

    if (j != 0){ //hubo coincidencia en la ultima posicion de texto
        coincidencias[n_usado] = i - j;
        n_usado++;
    }

    imprimir_resultados(coincidencias, n_usado, palabra);

    flag = dimensionar_vector(&coincidencias, &n_pedido, n_pedido - n_usado);
    if(!flag)
        return 1;

    delete [] coincidencias;

    return 0;
}
