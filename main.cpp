/*
 * Author: vlt23
 * Creation Date: 2018/03/17
 * Last Modified: 2018/03/24
 * Cadena de caracteres cifrada con los siguientes criterios:
    * Los caracteres que no sean letras no se modifican.
    * Cada consonantes se sustituye por la siguiente consonante en el
        abecedario (la siguiente a la ‘Z’ es la ‘B’).
    * Cada secuencia de vocales consecutivas se sustituye por la misma
        secuencia de vocales pero en orden inverso.
 * License: GNU GPLv3
 *
 * TODO: ---
 * Bugs: ¿?
 */

#include <iostream>
#include "arrayqueue.h"
#include "arraystack.h"

using namespace std;

int main()
{
    string mensaje;

    ArrayQueue<char> colaEntrada;
    ArrayQueue<char> colaSalida;
    ArrayStack<char> pila;

    getline(cin, mensaje);
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        colaEntrada.push_back(mensaje[i]);
    }

    char letra;
    while (!colaEntrada.isEmpty())
    {
        letra = colaEntrada.front();
        // las vocales se apilan...
        if (letra == 'a' || letra == 'e' || letra == 'i'
                || letra == 'o' || letra == 'u'
                || letra == 'A' || letra == 'E' || letra == 'I'
                || letra == 'O' || letra == 'U')
        {
            pila.push(letra);
        }
        else
        {
            // ... para sustituir en orden inverso
            while (!pila.isEmpty())
            {
                colaSalida.push_back(pila.top());
                pila.pop();
            }
            char next = letra + 1;
            // la siguiente a la 'z' es la 'b', NO la 'a'
            if (next == 'a' || next == 'e' || next == 'i'
                    || next == 'o' || next == 'u')
            {
                next = next + 1;
            }
            colaSalida.push_back(next);
        }
        colaEntrada.pop_front();
    }
    // ultimos caracteres son vocales, sacar de la pila
    while (!pila.isEmpty())
    {
        colaSalida.push_back(pila.top());
        pila.pop();
    }

    while (!colaSalida.isEmpty())
    {
        cout << colaSalida.front();
        colaSalida.pop_front();
    }
    cout << endl;

    return 0;
}
