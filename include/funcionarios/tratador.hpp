#pragma once

#include "pessoa.hpp"

enum Uniforme {
    Verde,
    Azul,
    Vermelho
};

class Tratador : public Pessoa {
    public:
        Tratador(string nome, string telefone, string email,
                Uniforme uniforme);

        ~Tratador();
        Uniforme getUniforme() const;

        ostream& printOutDados(ostream& o) const;

    private:
        Uniforme uniforme;

};