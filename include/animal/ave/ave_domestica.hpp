#pragma once

#include "ave.hpp"
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
 * Aqui temos uma definição para uma Ave do tipo Domestico.
 */
class AveDomestica : public Ave, public Domestico {
    public:
        AveDomestica() {};
        /**
         * @brief Construtor de AveDomestica
         * @details é totalmente baseado em suas
         * heranças Ave e Domestico.
         * @param Ave()
         * @param Domestico()
         */
        AveDomestica(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario,
                shared_ptr<Tratador> tratador, bool perigoso, bool adestrado, bool voa);

        ~AveDomestica();
};