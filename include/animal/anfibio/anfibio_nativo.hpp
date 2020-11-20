#pragma once

#include "anfibio.hpp"
#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class AnfibioNativo : public Anfibio, public Nativo {
};