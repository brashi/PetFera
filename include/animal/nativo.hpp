#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Umas das definições de categoria para Animal.
 * @details Herdando animal, as classes de categoria fazem o intermédio
 * entre a classificação do animal e as características de um animal da
 * mesma categoria.
 */
class Nativo : public Animal {
    public:
        Nativo() {};
        /**
         * @brief Construtor para o tipo Nativo
         * @details Usando o construtor de sua classe
         * base Animal. Também faz a base para os
         * que o herdam, definindo os atributos própios
         * da classe.
         * @param Animal() construtor base
         * @param regiao string determinando a que região o animal pertence
         * @param licenca declarando a licença do animal (numero)
         */
        Nativo(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, string licenca);
        /**
         * @brief Destrutor virtual
         * @details O destrutor deve ser virtual
         * pois terá herdeiros, sendo necessário
         * a definição do metodo
         */
        virtual ~Nativo();

        /**
         * @brief Um Nativo tem a string com sua região do país.
         */
        string getRegiao() const;

        /**
         * @brief Um Nativo tem uma licença de transporte gerada pelo IBAMA.
         */
        string getLicenca() const;

    protected:
        /** @brief região brasileira de origem do animal */
        string regiao;
        /** @brief Numero de licensa do IBAMA para transporte */
        string licenca;
};