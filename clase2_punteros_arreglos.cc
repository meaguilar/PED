#include <iostream>

int main()
{
    //Aritmética de punteros asignación, comparación, resta y suma

    // Arreglos y punteros
    //  Declaración de punteros
    int arreglo[] = {1, 2, 4};
    // Direccion de memoria
    std::cout << arreglo << '\n';
    // Todo array es un puntero
    int *ptr = arreglo;
    // Direccion de memoria
    std::cout << ptr << '\n';
    // Accediendo a la posición con punteros
    std::cout << *(ptr + 0) << '\n';
    std::cout << *(ptr + 1) << '\n';
    std::cout << *(ptr + 2) << '\n';

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Elemento del arreglo " << *(ptr + i) << " Direccion " << (ptr + i) << '\n';
    }

    int *ptr1 = &arreglo[0];
    int *ptr2 = &arreglo[2];

    // Resta - Distancia entre punteros
    std::cout << "Distancia entre punteros ptr2 - ptr0 " << *(ptr + 2) - *(ptr + 1) << '\n';
    std::cout << "Distancia entre punteros ptr2 - ptr0 " << ptr2 - ptr1 << '\n';
    std::cout << "Distancia entre valores ptr2 - ptr0 " << *ptr2 - *ptr1 << '\n';
    // Comparación
    std::cout << "ptr0 > ptr2: " << (*(ptr + 0) > *(ptr + 1)) << '\n';
    std::cout << "ptr0 == ptr0: " << (*(ptr + 0) == *(ptr + 0)) << '\n';
    std::cout << "ptr0 < ptr1: " << (*(ptr + 0) < *(ptr + 1)) << '\n';

    return 0;
}