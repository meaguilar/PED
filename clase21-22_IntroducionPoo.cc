#include <iostream>

class Persona
{
private:
    std::string nombre;
    int fecha_nacimiento;
    int edad;
    std::string profesion;
public:
    int CalcularEdad(int);
};

int Persona::CalcularEdad(int fecha_nacimiento)
{
    int edad = 0;
    edad = 2024 - fecha_nacimiento;
    return edad;
}

int main(int argc, char *argv[])
{
    Persona p1, p2, p3, p4, p5;
    p1.nombre = "Karen";
    p1.fecha_nacimiento = 2000;
    p1.profesion = "Estudiante";
    p1.edad = p1.CalcularEdad(p1.fecha_nacimiento);

    std::cout << p1.nombre << p1.edad;
    return 0;
}