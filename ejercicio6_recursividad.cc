#include <iostream>

int Factorial(int);
int Suma(int);
void Conteo(int);
int Fibonacci(int);

int main(int argc, char *argv[])
{
    std::cout << Fibonacci(15);
    return 0;
}

int Factorial(int x)
{

    // caso base
    if (x == 1)
    {
        return 1;
    }
    else
    {

        return x * Factorial(x - 1);
    }
}

int Suma(int y)
{
    // caso base
    if (y == 1)
    {
        return y;
    }
    else
    {
        return y + Suma(y - 1);
    }
}

void Conteo(int c)
{
    // Caso base
    if (c < 1)
    {
        return;
    }
    else
    {
        std::cout << c;
        Conteo(c - 1);
    }
}

int Fibonacci(int n)
{
    // Caso base
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}