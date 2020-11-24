#pragma once

#include "petshop.hpp"

#include <functional>
#include <string>
#include <map>

class MapeadorMenu {
    public:
        MapeadorMenu();
        std::map<char, std::function<bool (Petshop* petshop)>> escolhas;
};