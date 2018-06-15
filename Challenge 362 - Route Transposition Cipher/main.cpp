#include <string>
#include <iostream>
#include "cipher.h"

int main()
{
    std::string text = "ANDRES SOS UN GIL, NO TE HAGAS EL PIOLA";
    int rows = 5;
    int colums = 10;

    RouteCipher cipher(text, colums, rows);
    std::string s1 = cipher.Cipher(CLOCKWISE_LEFT);
    std::string s2 = cipher.Cipher(CLOCKWISE_RIGHT);
    std::string s3 = cipher.Cipher(COUNTERCLOCKWISE_LEFT);
    std::string s4 = cipher.Cipher(COUNTERCLOCKWISE_RIGHT);

    std::cout << "---> CLOCKWISE LEFT:\n";
    std::cout << s1 << "\n";
    std::cout << "---> CLOCKWISE RIGHT:\n";
    std::cout << s2 << "\n";
    std::cout << "---> COUNTER CLOCKWISE LEFT:\n";
    std::cout << s3 << "\n";
    std::cout << "---> COUNTER CLOCKWISE RIGHT:\n";
    std::cout << s4 << "\n";

    return 0;
}