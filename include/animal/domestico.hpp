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
class Domestico : public Animal {
    public:
        Domestico() {};
        Domestico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado);
        virtual ~Domestico();

        /**
         * @brief Um Domestico pode ser adestrado ou não.
         */
        bool getAdestrado() const;
    protected:
        bool adestrado;
};