#include <iostream>
#include <windows.h>

// Registrar las temperatura alta y baja, despues de cada 2 segundos

struct Temperatura
{
    float alta;
    float baja;
};

void LeerTempActual(float &);
void RegistroTemp(struct Temperatura &);

int main()
{

    // Inicializamos la estructura para que funcione bien la lógica
    struct Temperatura temp;
    temp.alta = 0;
    temp.baja = 100;
    while (true)
    {
        RegistroTemp(temp);
        std::cout << "Temperaturas: " << temp.baja << " - " << temp.alta << "\n";
        Sleep(2000);
    }

    return 0;
}

// Devolver varios valores desde el uso de referencias
void LeerTempActual(float &actual)
{
    int t = time(NULL);
    srand(t);
    actual = rand() % (48 + 1);
}

void RegistroTemp(struct Temperatura &temp)
{
    float actual = 0;
    LeerTempActual(actual);
    std::cout << " -> Lectura actual: " << actual << "\n";
    if (actual > temp.alta)
    {
        temp.alta = actual;
    }
    if (actual < temp.baja)
    {
        temp.baja = actual;
    }
}