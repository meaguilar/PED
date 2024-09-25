#include <iostream>

// La informacion que el usuario ingresara
struct Persona
{
    std::string nombre;
    int fNac;
};

struct Nodo
{
    struct Persona inf;
    struct Nodo *siguiente;
};

// Variable global
struct Nodo *frenteCola = nullptr;
struct Nodo *finalCola = nullptr;

// Declaracion de funciones / creacion de prototipo
bool Vacia();
void Insertar(struct Persona p);
void Eliminar();
void Imprimir();
void ImprimirFrente();
void ImprimirFinal();

int main()
{
    struct Persona p;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Ingresa un nombre ";
        std::cin >> p.nombre;
        std::cout << "Ingresa la fecha de Nac";
        std::cin >> p.fNac;
        Insertar(p);
    }
    std::cout << " --------------- " << std::endl;
    Imprimir();

    return 0;
}

// Operación vacia
bool Vacia()
{
    if (frenteCola == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(struct Persona p)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Asignacion del valor que ingresa el usuario
    nuevoNodo->inf = p;
    nuevoNodo->siguiente = nullptr;
    if (frenteCola == nullptr)
    {
        frenteCola = nuevoNodo;
    }
    else
    {
        finalCola->siguiente = nuevoNodo;
    }
    // Se establece el final de la cola con el nuevo nodo agregado
    finalCola = nuevoNodo;
}

// Desencolar -- inicio de la lista
void Eliminar()
{
    if (!Vacia())
    {
        struct Nodo *temporal = frenteCola;
        if (frenteCola == finalCola)
        {
            frenteCola = nullptr;
            finalCola = nullptr;
        }
        else
        {
            frenteCola = temporal->siguiente;
        }
        delete temporal;
    }
}

// Imprimir elementos de la cola
void Imprimir()
{
    struct Nodo *temporal = frenteCola;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la cola " << temporal->inf.nombre << " - " << temporal->inf.fNac << " dir propia " << temporal << " dir nod sig " << temporal->siguiente << std::endl;
        temporal = temporal->siguiente;
    }
}

void ImprimirFrente()
{
    struct Nodo *temporal = frenteCola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento frente en la cola " << temporal->inf.nombre << std::endl;
    }
}

void ImprimirFinal()
{

    struct Nodo *temporal = finalCola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento final en la cola " << temporal->inf.nombre << std::endl;
    }
}
