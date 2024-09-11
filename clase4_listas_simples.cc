#include <iostream>

// Struct de la informacion que se guardara en la lista
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

// Declaración de funciones
void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void Imprimir();
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);

int main()
{
    InsertarInicio(5);
    InsertarInicio(3);
    InsertarInicio(100);
    InsertarFinal(200);
    Imprimir();
    std::cout << "------------------" << "\n";
    EliminarInicio();
    EliminarFinal();
    Imprimir();

    // std::cout<<lista->elemento << " - " << lista;
    // std::cout<<lista->siguiente->siguiente->elemento << " - " << lista->siguiente->siguiente->siguiente;

    return 0;
}

// Insertar nodo al inicio de la lista
void InsertarInicio(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Variable auxiliar almacena el nodo actual
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al inicio
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}

// Insertar nodo al final de la lista
void InsertarFinal(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al final
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}

void InsertarIntermedio(int n, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexion del nuevoNodo con el resto de nodos de la lista
    nuevoNodo->siguiente = temporal->siguiente;
    // asignar el nuevoNodo a la lista
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio()
{
    struct Nodo *temporal = lista;
    // Si en la lista se encuentran elementos
    if (lista != nullptr)
    {
        // Borra el elemento
        lista = temporal->siguiente;
        // Libera la memoria
        delete temporal;
    }
    else if (temporal->siguiente == nullptr)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        // Si el nodo no es el ultimo
        if (temporal->siguiente != nullptr)
        {
            // Se realiza la iteraciones hasta encontra el ultimo nodo que apunte a nullptr
            while (temporal->siguiente != nullptr)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            // Almacena el penultimo nodo sera quien apunte nullptr
            temporal2->siguiente = nullptr;
            // Se libera la memoria del nodo ultimo
            delete temporal;
            temporal = nullptr;
        }
        else // Si unicamente se encontraba un nodo en la lista
        {
            delete lista;
            lista = nullptr;
        }
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
        while (temporal != nullptr)
        {
            std::cout << "Lista " << temporal->datos.elemento << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}