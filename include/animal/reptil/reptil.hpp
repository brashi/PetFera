#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

enum Pele {
    Escama,
    Placa,
    Carapaca
};

/**
 * @brief Classificação base para Repteis
 * @details A classe serve como base para 
 * os animais que se enquadram na Classe.
 * Tendo herdeiros com base na Categoria:
 * - Domestico
 * - Nativo
 * - Exotico
 */
class Reptil : public Animal {
    public:
        Reptil() {};

        Reptil(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, Pele pele);
                
        virtual ~Reptil() = 0;

        Pele getPele() const;

        void setPele(Pele p);

        bool setPele();
    protected:
        Pele pele;
};