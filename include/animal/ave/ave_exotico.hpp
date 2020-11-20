#pragma once

#include "../exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class Ave : public Exotico {
    public:
        Ave();
        Ave(bool voa);
        virtual ~Ave();

        bool getVoa() const;

    protected:
        bool voa;
};