#pragma once

#include "petshop.hpp"

#include <filesystem>
#include <functional>
#include <string>
#include <memory>
#include <map>

using std::shared_ptr;
using std::make_shared;
/**
 * @brief Classe mapeadora de funções para o menu.
 * @details A classe guarda um tipo map usado para
 * o mapeamento de opções do Menu do programa, sendo
 * usada na função main.
 * A sua conveniencia de juntar diversas opções e chamadas
 * de um tipo Petshop é enorme. Com ela podemos ter várias
 * opções advindas do Petshop sem fazer uma cadeia de
 * condições (com IF ou SWITCH) e podemos também sempre
 * adicionar mais retornos caso necessário.
 */
class MapeadorMenu {
    public:
        /**
         * @brief Construtor do mapeador.
         * @details A maior importância da declaração do construtor
         * é definir os parâmetros para seu map, sendo definido
         * em escolhas. Nele são construidos os parâmetros do mapa
         * para cada tipo de retorno diferente, podendo ser
         * qualquer método Public de Petshop.
         */
        MapeadorMenu();

        /**
         * @brief Mapa usado para retornar funções.
         * @details O tipo std::map pode ser acessado por um
         * tipo char e retornando uma função lambda. Neste
         * caso temos o uso do std::function<>. Que ao receber
         * uma instância de Petshop, pode retornar funções advindas
         * do mesmo, retornando a sua condição de sucesso como bool.
         * O uso deste artíficio é bem conveniente, e pode ser extendido
         * para diversas opções possíveis e qualquer uso disponível
         * em Public da classe Petshop.
         * @return Função da classe Petshop desejada.
         */ 
        std::map<char, std::function<bool (shared_ptr<Petshop> petshop)>> escolhas;
};