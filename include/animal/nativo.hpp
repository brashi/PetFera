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
class Nativo {
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
        Nativo(string regiao, string licenca);
        /**
         * @brief Destrutor virtual
         * @details O destrutor deve ser virtual
         * pois terá herdeiros, sendo necessário
         * a definição do metodo
         */
        virtual ~Nativo() = 0;

        /**
         * @brief Um Nativo tem a string com sua região do país.
         */
        string getRegiao() const;

        void setRegiao(string s);

        bool setRegiao();
        
        /**
         * @brief Um Nativo tem uma licença de transporte gerada pelo IBAMA.
         */
        string getLicenca() const;

        void setLicenca(string s);

        bool setLicenca();

    protected:
        /** @brief região brasileira de origem do animal */
        string regiao;
        /** @brief Numero de licensa do IBAMA para transporte */
        string licenca;
};