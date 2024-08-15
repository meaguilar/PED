#include <iostream>

int main(int argc, char *argv[])
{

    float alcancia[12]; 
    float total_ahorro = 0;

    for (int i = 0; i < 12; i++)
    {
        std::cout<<"Ingresar la cantidad ahorrar $" <<'\n';
        std::cin>>alcancia[i];
        total_ahorro += alcancia[i];
    }

    std::cout<<"Su total de ahorro $" << total_ahorro;
    

    
    return 0;
}