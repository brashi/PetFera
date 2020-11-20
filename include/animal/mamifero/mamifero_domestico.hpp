#pragma once

#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class Mamifero : public Domestico {
    public:
        Mamifero();
        Mamifero(bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

    protected:
        bool gestacao;
};