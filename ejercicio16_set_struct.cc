#include <iostream>
#include <set>

struct Persona
{
    int id;
    std::string nombre;
    int edad;
    // https://www.geeksforgeeks.org/sort-user-defined-types-using-std-sort/?ref=header_outind
    bool operator<(const Persona &p) const
    {
        return edad < p.edad;
    }
};

// https://www.geeksforgeeks.org/operator-overloading-cpp-print-contents-vector-map-pair/?ref=header_outind
std::ostream &operator<<(std::ostream &os, const Persona &p);

// https://cplusplus.com/reference/set/

int main(int argc, char *argv[])
{
    std::set<int> my_set;
    std::set<Persona> set_persona;

    //Declarando objeto p1
    struct Persona p1;

    //Inicializando  el objeto p1
    p1.id = 12;
    p1.nombre = "Karla";
    p1.edad = 15;

    //Declarando e inicializando el objeto p2
    struct Persona p2 = {13, "Frederick", 40};

    // Ingresar un elemento al set
    set_persona.insert(p1);

    // Borrar todos los elementos
    // my_set.clear();

    /// Borrar un elemento en especifico
    // set_persona.erase(p1);

    // Verificar la existencia de un elemento
    my_set.count(p1.id);

    // Imprimir elementos del set
    for (auto i : set_persona)
    {
        std::cout << i << '\n';
    }

    return 0;
}

std::ostream &operator<<(std::ostream &os, const Persona &p)
{
    os << "Nombre: " << p.nombre << " id: " << p.id;
    return os;
}