#include <iostream>
#include <set>

// https://cplusplus.com/reference/set/

int main(int argc, char *argv[])
{
    std::set<int> my_set;

    // Ingresar un elemento al set
    my_set.insert(15);
    my_set.insert(1);
    my_set.insert(5);
    my_set.insert(105);

    // Borrar todos los elementos
    my_set.clear();

    /// Borrar un elemento en especifico
    my_set.erase(15);

    // Verificar la existencia de un elemento
    my_set.count(105);

    // Imprimir elementos del set
    for (int i : my_set)
    {
        std::cout << i << '\n';
    }

    return 0;
}