#pragma once

#include "../exotico.hpp"

#include <string>
#include <iostream>

using std::string;

enum Pele {
    Escama,
    Placa,
    Carapaca
};

class Reptil : public Exotico {
    public:
        Reptil();
        Reptil(Pele pele);
        virtual ~Reptil();

        Pele getPele() const;

    protected:
        Pele pele;
};