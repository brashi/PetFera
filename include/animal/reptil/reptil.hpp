#pragma once

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
class Reptil {
    public:
        Reptil();
        Reptil(Pele pele);
        virtual ~Reptil();

        Pele getPele() const;

    protected:
        Pele pele;
};