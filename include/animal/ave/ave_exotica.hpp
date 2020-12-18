#pragma once

#include "ave.hpp"
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
 * Aqui temos uma definição para uma Ave do tipo Exotico.
 */
class AveExotica : public Ave, public Exotico {
    public:
        AveExotica() {};
        /**
         * @brief Construtor de AveExotica
         * @details é totalmente baseado em suas
         * heranças Ave e Exotico.
         * @param Ave()
         * @param Exotico()
         */
        AveExotica(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario,
                shared_ptr<Tratador> tratador, bool perigoso, string local, bool voa);

        ~AveExotica();
};