#pragma once

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
class Ave {
    public:
        Ave() {};
        Ave(bool voa);
        virtual ~Ave();

        bool getVoa() const;

    protected:
        bool voa;
};