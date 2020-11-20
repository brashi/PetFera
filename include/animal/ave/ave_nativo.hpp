#pragma once

#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class Ave : public Nativo {
    public:
        Ave();
        Ave(bool voa);
        virtual ~Ave();

        bool getVoa() const;

    protected:
        bool voa;
};