#pragma once

#include "animal.hpp"

#include "ave_domestica.hpp"
#include "ave_nativa.hpp"
#include "ave_exotica.hpp"

#include "anfibio_domestico.hpp"
#include "anfibio_nativo.hpp"
#include "anfibio_exotico.hpp"

#include "reptil_domestico.hpp"
#include "reptil_nativo.hpp"
#include "reptil_exotico.hpp"

#include "mamifero_domestico.hpp"
#include "mamifero_nativo.hpp"
#include "mamifero_exotico.hpp"

#include "veterinario.hpp"
#include "tratador.hpp"

#include <functional>
#include <string>
#include <memory>
#include <map>

using std::shared_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;

/**
 * @brief Mapeador de animais.
 * @details A classe serve para
 * conter um tipo map capaz de retornar
 * um método de criação de um respectivo animal.
 * A função guarda o mapa que funciona recebendo
 * um parâmetro em string descrevendo qual animal
 * deve ser instânciando. Então, seu retorno
 * é justamente uma referência para o tipo
 * específicado, utilizando funções Lambda
 * e std::function.
 */
class MapeadorAnimal {
    public:
        /**
         * @brief Construtor do mapa.
         * @details A sua importância é devido
         * a necessidade de declarar cada caso para o seu mapa.
         * Definindo os parâmetros e suas respostas em base a
         * qual animal deve ser instânciado.
         */
        MapeadorAnimal();

        /**
         * @brief Mapa de animais.
         * @details Seu funcionamento ocorre pela junção de
         * std::map e funções Lambda, no caso std::function.
         * A sua utilidade em instanciar classes economiza código,
         * evitando repetições do mesmo segmento e possibilitando o
         * instânciamento de tipos derivados de Animal com apenas
         * uma opção. Para o seu uso deve informar o tipo específico
         * como string e os dados do animal, utilizando o struct DadosAnimal.
         * @param DadosAnimal
         * @return Instancia para a classe desejada.
         */
        std::map<string, std::function<shared_ptr<Animal> ()>> aMap;
};


/**
 * @brief Classe de filtragem.
 * @details Serve para organizar um tipo map capaz
 * de filtrar instâncias de Animal. Retornando seu
 * tipo em questão caso válido.
 */
class FiltroAnimal {
    public:
        /**
         * @brief Construtor do filtro.
         * @details Inicializa os parâmetros de seu map, definindo
         * suas opções e retornos. Sendo necessário para o uso do mesmo.@
         */
        FiltroAnimal();

        /**
         * @brief Mapa para filtragem.
         * @details Serve como uma forma de filtrar instâncias do
         * tipo Animal. Podendo ser usado para definir se a instância
         * pertence a uma classificação ou categoria específica.
         * @param Animal a ser analisado.
         * @return Referência a Animal, é nullptr caso seja
         * ínvalido com o parâmetro dado.
         */
        std::map<char, std::function<shared_ptr<Animal> (shared_ptr<Animal> animal)>> filtro;

};