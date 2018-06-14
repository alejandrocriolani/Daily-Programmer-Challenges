#ifndef CIPHER_H
#define CIPHER_H

#include  <string>

class RouteCipher
{
    public:
        enum RouteType {
            CLOCKWISE_LEFT, CLOCKWISE_RIGHT,
            COUNTERCLOCKWISE_LEFT, COUNTERCLOCKWISE_RIGHT,
        };


        RouteCipher();
        RouteCipher(std::string text, int columns, int rows);
        std::string Cipher(RouteType routeType = CLOCKWISE_LEFT);

    private:
        std::string ClockwiseLeft();
        std::string text;
        int columns;
        int rows;
};

#endif