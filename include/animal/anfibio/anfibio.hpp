#pragma once

#include <string>
#include <iostream>

using std::string;

class Anfibio {
    public:
        Anfibio(bool cauda, bool pata);
        virtual ~Anfibio();

        bool getCauda() const;
        bool getPata() const;

    protected:
        bool cauda;
        bool pata;
};