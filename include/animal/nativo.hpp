#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

class Nativo : public Animal {
    public:
        Nativo(string regiao);
        virtual ~Nativo();

        string getRegiao() const;

    protected:
        string regiao;
};