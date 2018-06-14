#include <string>
#include <iostream>
#include "cipher.h"

int main()
{
    std::string text = "HOLA MUNDO";
    int rows = 3;
    int colums = 5;

    RouteCipher cipher(text, colums, rows);
    std::string s1 = cipher.Cipher();
    std::string s2 = cipher.Cipher(CLOCKWISE_RIGHT);

    std::cout << "---> CLOCKWISE LEFT:\n";
    std::cout << s1 << "\n";
    std::cout << "---> CLOCKWISE RIGHT:\n";
    std::cout << s2 << "\n";

    return 0;
}