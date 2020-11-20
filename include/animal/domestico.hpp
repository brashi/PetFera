#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using namespace std;
class Domestico : public Animal {
    public:
        Domestico();
        Domestico(bool adestrado);
        virtual ~Domestico();

        bool getAdestrado() const;

    protected:
        bool adestrado;
};