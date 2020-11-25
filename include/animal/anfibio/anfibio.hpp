#pragma once

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Classificação base para Anfibios
 * @details A classe serve como base para 
 * os animais que se enquadram na Classe.
 * Tendo herdeiros com base na Categoria:
 * - Domestico
 * - Nativo
 * - Exotico
 */
class Anfibio {
    public:
        Anfibio(bool cauda, bool pata);
        virtual ~Anfibio();

        bool getCauda() const;
        bool getPata() const;

    protected:
        bool cauda;
        bool pata;
};