#pragma once

#include "anfibio.hpp"
#include "exotico.hpp"

#include <string>
#include <iostream>

using std::string;


/**
 * @brief Implementação de animal com Classe e Categoria.
 * @details As classes finais que de fato são usadas para instanciamento
 * e administração dos Animais devem ter esta assinatura.
 * Possuindo um tipo que o classifique e o cateogorize.
 * Sendo a classe do mesmo feita por herança multipla. 
 * Aqui temos uma definição para um Anfibio do tipo Exotico.
 */
class AnfibioExotico : public Anfibio, public Exotico {
    public:
        /** 
         * @brief construtor herdado
         * @details sua implementação
         * é parte da herança entre Anfibio
         * e Exotico.
         * @param Exotico()
         * @param Anfibio()
         */
        AnfibioExotico(string nome, string especie, string ameacadoPor, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local, bool cauda, bool pata);

        ~AnfibioExotico();
};