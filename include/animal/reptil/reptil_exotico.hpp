#pragma once

#include "reptil.hpp"
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
 * Aqui temos uma definição para um Reptil do tipo Exotico.
 */
class ReptilExotico : public Reptil, public Exotico {
    public:
        ReptilExotico() {};

        ReptilExotico(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario,
                shared_ptr<Tratador> tratador, bool perigoso, string local, Pele pele);

        ~ReptilExotico();
};