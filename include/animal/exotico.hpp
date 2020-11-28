#pragma once

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Umas das definições de categoria para Animal.
 * @details Herdando animal, as classes de categoria fazem o intermédio
 * entre a classificação do animal e as características de um animal da
 * mesma categoria.
 */
class Exotico {
    public:
        Exotico() {};
        /**
         * @brief Construtor para o tipo Exotico
         * @details Usando o construtor de sua classe
         * base Animal. Também faz a base para os
         * que o herdam, definindo os atributos própios
         * da classe.
         * @param Animal() construtor base
         * @param local string determinando origem do animal
         */
        Exotico(string local);

        /**
         * @brief Destrutor virtual
         * @details O destrutor deve ser virtual
         * pois terá herdeiros, sendo necessário
         * a definição do metodo
         */
        virtual ~Exotico();

        /**
         * @brief Um Exotico ter uma string de sua origem.
         */
        string getLocal() const;
        
        bool setLocal();
    protected:
        /** @brief String declarando o local de origem do animal */
        string local;
};