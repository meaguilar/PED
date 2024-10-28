#include <iostream>
#include <unordered_map>

struct Diccionario
{
    char letra_inicial;
    std::string palabra;
    std::string sinonimos[2];

    bool operator==(const Diccionario &i) const
    {
        return (palabra == i.palabra);
    }
};

// https://www.geeksforgeeks.org/implement-custom-hash-functions-for-user-defined-types-in-std-unordered_map/?ref=header_outind
struct FuncionHash
{
    size_t operator()(const Diccionario &i) const
    {
        return std::hash<std::string>()(i.palabra);
    }
};

int main(int argc, char *argv[])
{
    //std::unordered_map<char, Diccionario> umap;
    std::unordered_map<Diccionario, char, FuncionHash> umap;

    struct Diccionario d1, d2;
    struct FuncionHash hash1, hash2;

    d1 = {'A', "Arcilla", {"Lodo", "Barro"}};
    d2 = {'A', "Alegria", {"Felicidad", "uuuuhh"}};

    umap.insert({d1,'A'});
    umap.insert({d2,'A'});

    size_t clave1 = hash1(d1);
    size_t clave2 = hash1(d2);
    std::cout << "Clave donde esta almacenado el valor: " << clave1 << " \n";
    std::cout << "Clave donde esta almacenado el valor: " << clave2 << " \n";

    for (const auto &i : umap)
    {
        std::cout << "Clave: " << i.first.palabra << ", Valor: " << i.second<< "\n";
        std::cout<< "Sinonimos: "<<i.first.sinonimos[0] << " - " <<i.first.sinonimos[1]<< "\n";

    }

    return 0;
}