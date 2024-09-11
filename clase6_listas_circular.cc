#include <iostream>

struct Datos
{
    int elemento;
};

struct Nodo 
{
    struct Datos datos;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);
void Imprimir();

int main()
{
    InsertarInicio(45);
    InsertarInicio(4);
    InsertarFinal(15);
    Imprimir();
    std::cout << "------------------------------" << '\n';

    return 0;
}

void InsertarInicio(int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        // Circularidad
        lista->siguiente = lista;
        temporal = lista;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
        // Circularidad
        temporal->siguiente = lista;
    }
}

void InsertarFinal(int n)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    }
    else
    {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista;
        temporal = nuevoNodo;
    }
}

void InsertarIntermedio(int n, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = lista->siguiente;
        delete lista;
        lista = temporal->siguiente;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista Vacia";
    }
}
void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
        }

        temporal2->siguiente = lista;
        delete temporal;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarIntermedio(int posicion)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexion del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal->siguiente;
    delete temporal;
    temporal = nullptr;
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        do
        {
            std::cout << "Lista " << temporal->datos.elemento << " Direccion " << temporal << " Dir siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        } while (temporal != lista);
    }
    else
    {
        std::cout << "Lista vacia";
    }
}
