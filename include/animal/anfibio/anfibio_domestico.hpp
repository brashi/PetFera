#pragma once

#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class Anfibio : public Domestico {
    public:
        Anfibio();
        Anfibio(bool cauda, bool pata);
        virtual ~Anfibio();

        bool getCauda() const;
        bool getPata() const;

    protected:
        bool cauda;
        bool pata;
};