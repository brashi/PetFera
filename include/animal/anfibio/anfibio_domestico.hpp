#pragma once

#include "anfibio.hpp"
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
 * Aqui temos uma definição para um Anfibio do tipo Domestico.
 */
class AnfibioDomestico : public Anfibio, public Domestico {
    public:
        /** 
         * @brief construtor herdado
         * @details sua implementação
         * é parte da herança entre Anfibio
         * e Domestico.
         * @param Domestico()
         * @param Anfibio()
         */
        AnfibioDomestico(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado, bool cauda, bool pata);

        ~AnfibioDomestico();
};