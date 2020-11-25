#pragma once

#include <iostream>

/**
 * @brief Classificação base para Mamiferos
 * @details A classe serve como base para 
 * os animais que se enquadram na Classe.
 * Tendo herdeiros com base na Categoria:
 * - Domestico
 * - Nativo
 * - Exotico
 */
class Mamifero {
    public:
        Mamifero(bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

    protected:
        bool gestacao;
};