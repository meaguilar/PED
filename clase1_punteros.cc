#include <iostream>

int main()
{
    int num1;
    int num2;

    int *ptr1 = &num1;
    int *ptr2 = &num2;

    num1 = 100;
    num2 = 200;
    std::cout << *ptr1 << " - " << *ptr2 << '\n'; // 100 200
    ptr1 = ptr2;                                  /// &num2
    *ptr1 = 500;                                  //&num2
    *ptr2 = 1;
    std::cout << *ptr1 << " - " << *ptr2 << '\n'; //  1 1
    std::cout << num1 << " - " << num2 << '\n';   //  100 1
    std::cout << ptr1 << " - " << ptr2 << '\n';   //&num2
    *ptr1 = 25;
    std::cout << *ptr1 << " - " << *ptr2 << '\n'; // 25 25
    *ptr2 = 15;
    *ptr2 = *ptr1;
    std::cout << *ptr1 << " - " << *ptr2 << " - " << num1 << '\n'; // 15 15 100

    return 0;
}