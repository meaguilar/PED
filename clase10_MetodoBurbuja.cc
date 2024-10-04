#include <iostream>


int main()
{

    // Declaración de un arreglo
    int arreglo[] = {4, 1, 65, 12, 10};
    // Declarar una variable que almacene el valor de intercambio
    int aux = 0;

    int longitud = sizeof(arreglo) / sizeof(int);
    /// Método de burbuja
    // Recorrer el arreglo
    for (int i = 0; i < longitud; i++)
    {
        // Comparación entre elemento actual y siguiente
        for (int j = 0; j < longitud - 1; j++)
        {
            // Comparación valor actual es mayor a valor siguiente
            if (arreglo[j] > arreglo[j + 1])
            {
                // Intercambio de los valores
                // Se almacena el valor de resultado de la comparación
                aux = arreglo[j]; // 4
                // Se almacena el valor siguiente menor en la posición actual
                arreglo[j] = arreglo[j + 1]; // posicion 0 del valor 1
                // Se almacena en la posición siguiente el valor de aux
                arreglo[j + 1] = aux; // 4
                // Resultados de cada una de las iteraciones
                std::cout << "Valor mayor " << aux << " pos. actual " << j << " nueva pos. " << j + 1 << ", valor menor " << arreglo[j] << " pos. actual " << j + 1 << " nueva pos " << j << std::endl;
            }
        }
    }

    // Imprimir resultados
    std::cout << " -------------------- " << std::endl;
    std::cout << " Datos ordenados " << std::endl;
    for (int i = 0; i < 5; i++)
    {

        std::cout <<" Valor " << arreglo[i] << ", pos " << i << std::endl;
    }

    return 0;
}
