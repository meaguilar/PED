#include <iostream>

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};
// Variable global
struct Nodo *pila = nullptr;

// Declarando funciones
void Insertar(int);
void Imprimir();
void Eliminar();
bool Vacia();
void UltimoElemento();

// Un nodo tiene un dato, el cual es el elemento y  otro nodo al que apunta

int main()
{
    int valor;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingrese un valor ";
        std::cin >> valor;
        Insertar(valor);
    }
    std::cout << "------------------" << std::endl;
    Imprimir();
    std::cout <<Vacia();
    UltimoElemento();

    return 0;
}

// Operacion Push
void Insertar(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // almacenar el valor ingresado por el usuario
    nuevoNodo->elemento = n;
    // Ingresando el nuevo nodo a la pila
    nuevoNodo->siguiente = pila;
    // Asignando que el valor ingresado esta en la cima de la pila
    pila = nuevoNodo;
}

// Operación Pop
void Eliminar()
{
    if (pila != nullptr)
    {
        struct Nodo *temporal = pila;
        // Asignación del nuevo valor que esta en la cima de la pila
        pila = temporal->siguiente;
        delete temporal;
    }
}

// Imprimir la pila
void Imprimir()
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la pila " << temporal->elemento << "dir. memoria del nodo" << temporal << " Dir memoria nodo sig " << temporal->siguiente << std::endl;

        temporal = temporal->siguiente;
    }
}

// Operacion Pila vacia
bool Vacia()
{
    // Si devuelve 1 la pila esta vacia
    // Si devuelve 0 la pila no esta vacia
    if (pila == nullptr)
    {
       return 1;
    }else{
        return 0;
    }
    
}

// Operación Top
void UltimoElemento()
{
    // Imprimir el ultimo elemento que se ingreso a la pila o el elemento  que esta en la cima de la pila
    std::cout<<pila->elemento;
}