#pragma once

#include "reptil.hpp"
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
 * Aqui temos uma definição para um Reptil do tipo Nativo.
 */
class ReptilNativo : public Reptil, public Nativo {
    public:
        ReptilNativo(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, Pele pele);

        ~ReptilNativo();
};