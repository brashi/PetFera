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
        /** 
         * @brief construtor de Anfibio
         * provendo os atributos
         * do tipo do Animal
         */
        Anfibio(bool cauda, bool pata);
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

        /**
         * @brief getter de bool
         * @return bool pata da instância.
         */
        bool getPata() const;

    protected:
        /** @brief determina se o anfibio tem ou não cauda */
        bool cauda;
        /** @brief determina se o anfibio tem ou não pata */
        bool pata;
};