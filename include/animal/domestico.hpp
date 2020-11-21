#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

class Domestico : public Animal {
    public:
        Domestico(bool adestrado);
        virtual ~Domestico();

        bool getAdestrado() const;

    protected:
        bool adestrado;
};