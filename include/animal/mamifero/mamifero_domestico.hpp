#pragma once

#include "mamifero.hpp"
#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class MamiferoDomestico : public Mamifero, public Domestico {
};