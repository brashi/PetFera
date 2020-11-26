#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Umas das definições de categoria para Animal.
 * @details Herdando animal, as classes de categoria fazem o intermédio
 * entre a classificação do animal e as características de um animal da
 * mesma categoria.
 */
class Exotico : public Animal {
    public:
        Exotico() {};
        Exotico(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local);
        virtual ~Exotico();

        /**
         * @brief Um Exotico ter uma string de sua origem.
         */
        string getLocal() const;

    protected:
        string local;
};