#pragma once

#include "anfibio.hpp"
#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class AnfibioDomestico : public Anfibio, public Domestico {
};