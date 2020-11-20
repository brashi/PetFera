#pragma once

#include "../exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class Mamifero : public Exotico {
    public:
        Mamifero();
        Mamifero(bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

    protected:
        bool gestacao;
};