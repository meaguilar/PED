#include <iostream>

struct InfoAcademica {
    float notas[3];
};

struct Alumno
{
    int codigo;
    std::string nombre_completo;
    struct InfoAcademica academica; 
};


int main(int argc, char *argv[])
{
    struct Alumno estudiante[3];

//  Solicitud de los datos
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingresa el codigo";
        std::cin >> estudiante[i].codigo;
        std::cout << "Ingresa el nombre ";
        std::cin >> estudiante[i].nombre_completo;

        for (int j = 0; j < 3; j++)
        {
            std::cout << "Ingresa la nota ";
            std::cin >> estudiante[i].academica.notas[j];
        }
    }

// Imprimir los datos 
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Codigo "<<estudiante[i].codigo << '\n';
        std::cout << "Nombre completo " << estudiante[i].nombre_completo << '\n';

        for (int j = 0; j < 3; j++)
        {
            std::cout << "Nota: " << estudiante[i].academica.notas[j]<<'\n';
        }
    }

    return 0;
}