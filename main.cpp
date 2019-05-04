#include <iostream>
#include <windows.h>
#include "header\\Zfraction.hpp"

int main(int argc, char **argv)
{
    Fraction fraction1(3, 5), fraction2(3, 10);

    std::cout << fraction1 << std::endl;
    std::cout << fraction2 << std::endl;

    std::cout << fraction1 + fraction2 << std::endl;
    std::cout << fraction1 - fraction2 << std::endl;
    std::cout << fraction1 * fraction2 << std::endl;
    std::cout << fraction1 / fraction2 << std::endl;

    std::cout << fraction1 << std::endl;
    std::cout << fraction2 << std::endl;

    if (fraction1 != fraction2)
    {
        printf("Non ils ne sont pas egaux\n");
    }
    else
        printf("Ils sont egaux \n");

    if (fraction1 > fraction2)
    {
        printf("fraction1 superieur a fraction2\n");
    }
    else
    {
        printf("fraction1 inferieur a fraction2\n");
    }

    system("pause");
    return 0;
}