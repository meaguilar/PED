#include <iostream>

int main()
{

  float ahorro_mes[3][2];
  float ahorro_total = 0;
  float mes = 0, cant_ahorro = 0;

  std::cout << "Ingresar la informacion para el ahorro \n";

  for (int i = 0; i < 3; i++)
  {
    std::cout << "Ingresa el mes ";
    std::cin >> mes;
    std::cout << "Ingresa el ahorro ";
    std::cin >> cant_ahorro;

    ahorro_mes[i][0] = mes;
    ahorro_mes[i][1] = cant_ahorro;
    ahorro_total += ahorro_mes[i][1];
    std::cout << "Mes " << ahorro_mes[i][0] << " cantidad ahorro $" << ahorro_mes[i][1] << '\n';

  }

  std::cout<<"Ahorro total $" << ahorro_total;



  return 0;
}