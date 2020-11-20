#include "tratador.hpp"

Tratador::Tratador(string nome, string telefone, string email,
                    Uniforme uniforme):
                    Pessoa(nome, telefone, email),
                    uniforme(uniforme){}

Tratador::~Tratador(){}