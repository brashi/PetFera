#pragma once

#include <string>
#include <iostream>

using std::string;

class Mamifero {
    public:
        Mamifero(string gestacao);
        virtual ~Mamifero();

        string getGestacao() const;

    protected:
        string gestacao;
};