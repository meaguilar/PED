#include <iostream>

int BusquedaBinaria(int [], int, int, int);


int main(int argc, char *argv[])
{
    int arreglo[] = {1, 40, 100, 80, 25};
    int valor = 40;
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int result = BusquedaBinaria(arreglo, 0, n - 1, valor);

    return 0;
}

int BusquedaBinaria(int arreglo[], int menor, int mayor, int valor)
{
    // Menor y mayor representan a los indices
    while (menor <= mayor)
    {
        int medio = menor + (mayor - menor) / 2;
    
        if (arreglo[medio] == valor)
        {
            return medio;
        }

        if (arreglo[medio] < valor)
        {
            menor = mayor + 1;
        }
        else
        {
            mayor = menor - 1;
        }
    }

    return -1;
}
