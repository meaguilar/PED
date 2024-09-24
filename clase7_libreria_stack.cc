#include <iostream>
#include <stack>
// https://cplusplus.com/reference/stack/stack/

void Imprimir(std::stack<char> pila);

int main()
{
    // Declaración de la pila
    std::stack<char> pila;

    // Metodos
    // Obtener el numero de elementos
    std::cout << pila.size();
    // Returna  1 o 0 si esta vacia o no
    std::cout << pila.empty();
    // Agregar
    pila.push('U');
    pila.push('C');
    pila.push('A');
  
    // Eliminar el ultimo elemento
    pila.pop();

    // Permite obtener el elemento del tope o de la cima
    pila.top();
   

    return 0;
}

