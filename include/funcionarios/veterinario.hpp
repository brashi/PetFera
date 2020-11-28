#pragma once

#include "pessoa.hpp"


/**
 * @brief Implementação dos veterinarios.
 * @details A implementação para cadastro e admnistração envolve
 * veterinarios credenciados e certificados pelo CRMV.
 * Do mesmo, herdam Pessoa com qual divide atributos básicos comum
 * a Tratador.
 */
class Veterinario : public Pessoa {
    public:
        Veterinario() {};
        /**
         * @brief Construtor de Veterinario
         * @details Se baseia no construtor
         * de Pessoa, com a adição de suas características
         * em especial.
         * @param Pessoa() igual construtor de Pessoa
         * @param CRMV tipo string
         */
        Veterinario(string nome, string telefone, string email,
                string CRMV);

        ~Veterinario();

        /**
         * @brief getter de string
         * @return código CRMV do Veterinario em questão,
         * em forma de String.
         */
        string getCRMV() const;

        bool setCRMV();

        void setCRMV(string s);

        /**
         * @brief Implementação da stream de dados.
         * @details Retorna um stream de saida std::cout
         * com as informações da instância específica,
         * feito para a classe Veterinario.
         */
        ostream& printOutDados(ostream& o) const;

    private:
        /** @brief Número de cadastro no orgão conforme a legislação. */
        string CRMV;

};