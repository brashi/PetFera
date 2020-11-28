#pragma once

#include "animal.hpp"

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
class Anfibio : public Animal {
    public:
        Anfibio() {};
        /** 
         * @brief construtor de Anfibio
         * provendo os atributos
         * do tipo do Animal
         */
        Anfibio(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool cauda, bool pata);
        /**
         * @brief Destrutor virtual
         * @details Determinado virtual devido
         * a ser utilizada para heranças
         * de forma geral.
         */
        virtual ~Anfibio();

        /**
         * @brief getter de bool
         * @return bool cauda da instância.
         */
        bool getCauda() const;

        int setCauda();

        /**
         * @brief getter de bool
         * @return bool pata da instância.
         */
        bool getPata() const;

        bool setPata();
    protected:
        /** @brief determina se o anfibio tem ou não cauda */
        bool cauda;
        /** @brief determina se o anfibio tem ou não pata */
        bool pata;
};