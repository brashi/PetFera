#pragma once

#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class Mamifero : public Nativo {
    public:
        Mamifero();
        Mamifero(bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

    protected:
        bool gestacao;
};