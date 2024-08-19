#include <iostream>

void SolicitarDatos();
void Imprimir(struct Alumno[]);
void CalcularPromedio(struct Alumno[]);

struct InfoAcademica
{
    float notas[3];
    float promedio;
};

struct Alumno
{
    int codigo;
    std::string nombre_completo;
    struct InfoAcademica academica;
} estudiante[3];

int main(int argc, char *argv[])
{
    struct Alumno estudiante[3];
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
    CalcularPromedio(estudiante);
    Imprimir(estudiante);

    return 0;
}

void Imprimir(struct Alumno a[])
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Codigo " << a[i].codigo << '\n';
        std::cout << "Nombre completo " << a[i].nombre_completo << '\n';

        for (int j = 0; j < 3; j++)
        {
            std::cout << "Nota: " << a[i].academica.notas[j] << '\n';
        }

        std::cout << "Promedio " << a[i].academica.promedio << '\n';
    }
}

void CalcularPromedio(struct Alumno a[])
{

    float nota_final[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            nota_final[i] += a[i].academica.notas[j];
        }

        a[i].academica.promedio = nota_final[i] / 3;
    }
}