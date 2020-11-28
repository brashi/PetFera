#pragma once

#include "animal.hpp"

#include <string>
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
class Mamifero : public Animal {
    public:
        Mamifero() {};
        
        Mamifero(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool gestacao);
        virtual ~Mamifero();

        bool getGestacao() const;

        bool setGestacao();
    protected:
        bool gestacao;
};