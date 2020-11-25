#pragma once

#include <iostream>

class Mamifero {
    public:
        Mamifero(bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

    protected:
        bool gestacao;
};