#pragma once

#include "mamifero.hpp"
#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class MamiferoNativo : public Mamifero, public Nativo {
};