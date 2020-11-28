#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Classificação base para Aves
 * @details A classe serve como base para 
 * os animais que se enquadram na Classe.
 * Tendo herdeiros com base na Categoria:
 * - Domestico
 * - Nativo
 * - Exotico
 */
class Ave : public Animal {
    public:
        Ave() {};
        /** 
         * @brief construtor de Ave
         * @details Serve para dar padrão
         * às classes de animais derivadas
         * dela.
         * @param voa tipo bool
         */
        Ave(string nome, string especie, string ameacadoPor, Veterinario veterinario,
            Tratador tratador, bool perigoso, bool voa);

        /**
         * @brief destrutor de Ave
         * @details Usa tipo virtual para
         * haver polimorfismo entre
         * suas classes herdeiras.
         */
        virtual ~Ave();

        /**
         * @brief getter de bool
         * @return bool determinando
         * se o animal voa ou não.
         */
        bool getVoa() const;

        void setVoa(bool b);

        bool setVoa();
    protected:
        /** @brief valor bool que determina se o animal voa */
        bool voa;
};