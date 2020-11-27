#pragma once

#include "anfibio.hpp"
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
 * Aqui temos uma definição para um Anfibio do tipo Nativo.
 */
class AnfibioNativo : public Anfibio, public Nativo {
    public:
        AnfibioNativo() {};
        /** 
         * @brief construtor herdado
         * @details sua implementação
         * é parte da herança entre Anfibio
         * e Nativo.
         * @param Nativo()
         * @param Anfibio()
         */
        AnfibioNativo(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, string licenca, bool cauda, bool pata);

        ~AnfibioNativo();
};