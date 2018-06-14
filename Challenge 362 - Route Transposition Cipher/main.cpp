#include <string>
#include "cipher.h"

int main()
{
    std::string text = "HOLA MUNDO";
    int rows = 4;
    int colums = 6;

    RouteCipher cipher(text, colums, rows);
    cipher.Cipher();

    return 0;
}