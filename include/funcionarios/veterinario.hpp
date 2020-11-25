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
        Veterinario(string nome, string telefone, string email,
                string CRMV);

        ~Veterinario();
        string getCRMV() const;

        ostream& printOutDados(ostream& o) const;

    private:
        string CRMV;

};