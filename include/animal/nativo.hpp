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
class Nativo : public Animal {
    public:
        Nativo() {};
        Nativo(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao);
        virtual ~Nativo();

        /**
         * @brief Um Nativo tem a string com sua região do país.
         */
        string getRegiao() const;

    protected:
        string regiao;
};