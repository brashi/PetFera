#pragma once

#include "mamifero.hpp"
#include "../exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class MamiferoExotico : public Mamifero, public Exotico {
};