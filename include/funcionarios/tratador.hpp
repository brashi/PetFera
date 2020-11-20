#pragma once

#include "pessoa.hpp"

using std::string;

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

    private:
        Uniforme uniforme;

};