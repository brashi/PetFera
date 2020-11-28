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
class Domestico {
    public:
        Domestico() {};
        /**
         * @brief Construtor para tipo Domestico
         * @details Usa o construtor da classe base Animal
         * como parte. Apenas adicionando suas características
         * própias.
         * @param Animal() construtor de Animal
         * @param adestrado tipo bool
         */
        Domestico(bool adestrado);

        /**
         * @brief Destrutor virtual
         * @details O destrutor deve ser virtual
         * pois terá herdeiros, sendo necessário
         * a definição do metodo
         */
        virtual ~Domestico();

        /**
         * @brief Um Domestico pode ser adestrado ou não.
         * @return valor bool
         */
        bool getAdestrado() const;
        
        void setAdestrado(bool b);

        bool setAdestrado();
    protected:
        /** @brief Bool determinando se o animal é adestrado ou não */
        bool adestrado;
};