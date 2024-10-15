#include <iostream>

struct Nodo
{ 
    char raiz;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Nodo *Crear(char n);
// Se pasa un puntero y por referencia ya que se modificara el valor
struct Nodo *Insertar(struct Nodo *ABB, char n);
void Inorden(struct Nodo *ABB);
void Preorden(struct Nodo *ABB);
void Postorden(struct Nodo *ABB);
struct Nodo *BuscarMenor(struct Nodo *ABB);
void Buscar(struct Nodo *&ABB, char n, struct Nodo *&padre);
void Borrar(Nodo *&ABB, char n);

int main()
{
    struct Nodo *ABB = nullptr;

    char raiz;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Ingresa un valor";
        std::cin >> raiz;
        ABB = Insertar(ABB, raiz);
    }
    std::cout << " Recorrido Inorden ";
    Inorden(ABB);
    std::cout << " Recorrido Preorden ";
    Preorden(ABB);
    std::cout << " Recorrido Postorden ";
    Postorden(ABB);
    // NodoEliminar(arbol,1);

    return 0;
}

// Crear Nodo
struct Nodo *Crear(char n)
{
    // Reservar la memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Asignar el valor que el usuario ingresa
    nuevoNodo->raiz = n;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    // nuevoNodo->izquierdo = nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

// Insertar
struct Nodo *Insertar(struct Nodo *ABB, char n)
{
    // Si arbol esta vacio se crea el arbol a partir del primer valor ingresado
    if (ABB == nullptr)
        return Crear(n);
    // si el valor ingresado es menor se inserta en el subarbol de la izquierda
    if (n < ABB->raiz)
        ABB->izquierdo = Insertar(ABB->izquierdo, n);
    else
        // si el valor ingresado es mayor se inserta en el subarbol de la derecha
        ABB->derecho = Insertar(ABB->derecho, n);
    return ABB;
}

// Recorrer
// Inorden: Hijo izquierdo — raíz — hijo derecho.
void Inorden(struct Nodo *ABB)
{
    if (ABB == nullptr)
    {
        return;
    }
    else
    {
        Inorden(ABB->izquierdo);
        // Raiz
        std::cout << ABB->raiz << "-";
        Inorden(ABB->derecho);
    }
}

// Preorden: Raíz — hijo izquierdo — hijo derecho.
void Preorden(struct Nodo *ABB)
{
    if (ABB == nullptr)
    {
        return;
    }
    else
    {
        // Raiz
        std::cout << ABB->raiz << "-";
        Preorden(ABB->izquierdo);
        Preorden(ABB->derecho);
    }
}

// PostOrden:Hijo izquierdo– hijo derecho — raíz
void Postorden(struct Nodo *ABB)
{
    if (ABB == nullptr)
    {
        return;
    }
    else
    {
        Postorden(ABB->izquierdo);
        Postorden(ABB->derecho);
        // Raiz
        std::cout << ABB->raiz << "-";
    }
}

void Buscar(struct Nodo *&ABB, char n, struct Nodo *&padre)
{
    while (ABB != nullptr && ABB->raiz != n)
    {
        padre = ABB;
        if (n < ABB->raiz)
            ABB = ABB->izquierdo;
        else
            ABB = ABB->derecho;
    }
}
// Encontrar el menor
struct Nodo *BuscarMenor(struct Nodo *ABB)
{
    while (ABB->izquierdo != nullptr)
    {
        ABB = ABB->izquierdo;
    }
    return ABB;
}

// Borrar el nodo
void Borrar(Nodo *&ABB, char n)
{
    struct Nodo *padre = nullptr;
    struct Nodo *aux = ABB;
    Buscar(aux, n, padre);
    // Si el arbol no tiene nodos
    if (aux == nullptr)
    {
        return;
    }

    // Borrar un nodo hoja (sin hijos en izq y der)
    if (aux->izquierdo == nullptr && aux->derecho == nullptr)
    {
        // Si el valor a borrar es igual a la raiz se borra todo el arbol
        if (aux == ABB)
        {
            ABB = nullptr;
        }
        // Si el valor a borrar es diferente de la raiz
        else
        {
            if (padre->izquierdo == aux)
            {
                padre->izquierdo = nullptr;
            }
            else
            {
                padre->derecho = nullptr;
            }
        }

        // Liberar la memoria
        delete aux;
    }

    // Borrar nodo con 2 hijos (hijos en der e izq)
    else if (aux->izquierdo && aux->derecho)
    {
        // Se busca en el subarbol derecho el nodo menor
        struct Nodo *sucesor = BuscarMenor(aux->derecho);
        char val = sucesor->raiz;
        Borrar(ABB, sucesor->raiz);   
        aux->raiz = val;
    }
    else
    {
        // Borrar nodo con  un solo hijo (izq o der)
        struct Nodo *hijo;
        // Evalua si el hijo es nodo izquierdo o derecho
        if (aux->izquierdo)
        {
            hijo = aux->izquierdo;
        }
        else
        {
            hijo = aux->derecho;
        }
        if (aux != ABB)
        {
            if (aux == padre->izquierdo)
                padre->izquierdo = hijo;
            else
                padre->derecho = hijo;
        }
        else
        {
            ABB = hijo;
        }

        delete aux;
    }
}