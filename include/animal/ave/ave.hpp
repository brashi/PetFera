#pragma once

#include <string>
#include <iostream>

using std::string;

class Ave {
    public:
        Ave() {};
        Ave(bool voa);
        virtual ~Ave();

        bool getVoa() const;

    protected:
        bool voa;
};