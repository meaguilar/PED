#include <iostream>


int main()
{

    // Declarar un arreglo
    int arreglo[] = {4, 1, 65, 12, 10};

    std::cout << "Recorrido del arreglo sin ordenar " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << arreglo[i] << " pos " << i << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;

    // Almacenar la posición
    int pos = 0;
    // Almacenar el elemento de intercambio
    int aux = 0;
    // Método de inserción
    // Recorrido del arreglo
    for (int i = 0; i < 5; i++)
    {
        // Posición actual
        pos = i; // 0
        // Valor del arreglo
        aux = arreglo[i]; // 4
        // Comparación con el número de la izquierda
        while ((pos > 0) && (arreglo[pos - 1] > aux))
        {
            // Cambio con el número de la izquierda
            arreglo[pos] = arreglo[pos - 1];
            // Iteraciones hacia atras
            pos--;
        }
        // Refrescar cada iteración
        arreglo[pos] = aux;
    }

    // Imprimir resultados
    std::cout << " -------------------- " << std::endl;
    std::cout << " Datos ordenados " << std::endl;
    for (int i = 0; i < 5; i++)
    {

        std::cout << " Valor " << arreglo[i] << ", pos " << i << std::endl;
    }

    return 0;
}