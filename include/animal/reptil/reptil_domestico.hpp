#pragma once

#include "reptil.hpp"
#include "domestico.hpp"

#include <string>
#include <iostream>

using std::string;

/**
 * @brief Implementação de animal com Classe e Categoria.
 * @details As classes finais que de fato são usadas para instanciamento
 * e administração dos Animais devem ter esta assinatura.
 * Possuindo um tipo que o classifique e o cateogorize.
 * Sendo a classe do mesmo feita por herança multipla. 
 * Aqui temos uma definição para um Reptil do tipo Domestico.
 */
class ReptilDomestico : public Reptil, public Domestico {
    public:
        ReptilDomestico() {};

        ReptilDomestico(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado, Pele pele);

        ~ReptilDomestico();
};