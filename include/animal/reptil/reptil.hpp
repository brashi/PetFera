#pragma once

#include <string>
#include <iostream>

using std::string;

enum Pele {
    Escama,
    Placa,
    Carapaca
};

class Reptil {
    public:
        Reptil();
        Reptil(Pele pele);
        virtual ~Reptil();

        Pele getPele() const;

    protected:
        Pele pele;
};