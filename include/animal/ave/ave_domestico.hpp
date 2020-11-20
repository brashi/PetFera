#pragma once

#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class Ave : public Domestico {
    public:
        Ave();
        Ave(bool voa);
        virtual ~Ave();

        bool getVoa() const;

    protected:
        bool voa;
};