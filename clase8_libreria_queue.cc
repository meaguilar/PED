#include <iostream>
#include <queue>

// https://cplusplus.com/reference/queue/

int main()
{
    // Declaracion de la cola
    std::queue<int> cola;

    // Metodos
    // Obtener el numero de elementos
    std::cout << cola.size();

    // Returna  1 o 0 si esta vacia o no
    std::cout << cola.empty();
    // Agregar al final de la cola
    cola.push(4);
    cola.push(45);
    // Eliminar el primer elemento
    cola.pop();

    // Obtener el elemento del frente
    std::cout << cola.front();

    // Obtener el elemento del final
    std::cout << cola.back();

    return 0;
}