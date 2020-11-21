#pragma once

#include <string>
#include <iostream>

using std::string;

class Mamifero {
    public:
        Mamifero(bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

    protected:
        bool gestacao;
};