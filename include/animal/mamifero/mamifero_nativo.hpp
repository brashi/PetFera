#pragma once

#include "mamifero.hpp"
#include "nativo.hpp"

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Implementação de animal com Classe e Categoria.
 * @details As classes finais que de fato são usadas para instanciamento
 * e administração dos Animais devem ter esta assinatura.
 * Possuindo um tipo que o classifique e o cateogorize.
 * Sendo a classe do mesmo feita por herança multipla. 
 * Aqui temos uma definição para um Mamifero do tipo Nativo.
 */
class MamiferoNativo : public Mamifero, public Nativo {
    public:
        MamiferoNativo() {};

        MamiferoNativo(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, string licenca, bool gestacao);

        ~MamiferoNativo();
};