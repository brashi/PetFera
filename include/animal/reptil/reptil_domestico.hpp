#pragma once

#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

enum Pele {
    Escama,
    Placa,
    Carapaca
};

class Reptil : public Domestico {
    public:
        Reptil();
        Reptil(Pele pele);
        virtual ~Reptil();

        Pele getPele() const;

    protected:
        Pele pele;
};