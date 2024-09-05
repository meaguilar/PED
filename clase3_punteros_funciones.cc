#include <iostream>

int incrementoPorValor(int);
int incrementoPuntero(int *);
int incrementoReferencia(int &);

int suma(int, int);

int main()
{
    int i = 100;
    std::cout << i << '\n';                       // 100
    std::cout << incrementoPorValor(i) << '\n';   // 102
    std::cout << i << '\n';                       // 100
    std::cout << incrementoPuntero(&i) << '\n';   // 103
    std::cout << i << '\n';                       // 103
    std::cout << incrementoReferencia(i) << '\n'; // 108
    std::cout << i << '\n';                       // 108

    return 0;
}

int incrementoPorValor(int i)
{

    return i += 2;
}

int incrementoPuntero(int *i)
{

    return *i += 3;
}

int incrementoReferencia(int &x)
{
    return x += 5;
}
