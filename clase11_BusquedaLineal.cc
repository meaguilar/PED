#include <iostream>

int BusquedaLineal(int[], int, int);

int main(int argc, char *argv[])
{
    int arreglo[] = {1, 40, 100, 80, 25};
    int valor = 40;
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    std::cout << BusquedaLineal(arreglo, tamano, valor);
    return 0;
}

int BusquedaLineal(int arreglo[], int tamano, int valor)
{
    for (int i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            return i;
        }
    }
    return -1;
}