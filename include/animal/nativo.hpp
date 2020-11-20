#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using namespace std;
class Nativo : public Animal {
    public:
        Nativo();
        Nativo(string regiao);
        virtual ~Nativo();

        string getRegiao() const;

    protected:
        string regiao;
};