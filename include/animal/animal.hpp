#pragma once

#include "tratador.hpp"
#include "veterinario.hpp"

#include <string>
#include <iostream>

using std::string;


/**
 * @brief Implementação base para o cadastro de animais.
 * @details O cadastro de um animal passa pela base Animal. Exigindo
 * uma série de informações comuns a todos os animais, tais como
 * nome, especie, seu Veterinario e Tratador.
 */
class Animal {
    public:
        Animal() {};
        Animal(string nome, string especie, Veterinario veterinario,
            Tratador tratador, bool perigoso);
        virtual ~Animal();

        string getNome() const;
        string getEspecie() const;
        Veterinario getVeterinario() const;
        Tratador getTratador() const;
        bool getPerigoso() const;

        string getClassificacao(Animal* animal) const;
        string getClasse(Animal* animal) const;

        /**
         * @brief Função para impressão de dados via sobrecarga.
         * @details É chamada após o uso com operador de extração "<<". Tem sua base
         * informando as características comuns a todos os animais, bem como sua Classe
         * e Categoria através de checagens prévias.
         * @param Animal Dado através da sobrecarga do operador "<<".
         * @param ostream O mesmo dado pelo operador "<<".
         * @return Stream de saída com os dados do animal. Sendo eles os atributos definidos
         * em Animal e a Classe e Categoria do animal.
         */
        ostream& printOutDados(ostream& o, Animal* animal) const;

        /**
         * @brief Sobrecarga do operador de igualdade para animais.
         * @details Pode ser usada para comparar a igualdade em animais, utilizando
         * nome e especie como parâmetro para definir igualdade.
         * @param Animal Dado pela sobrecarga do operador.
         * @return Bool confirmando (ou não) a igualdade.
         */
        bool operator==(const Animal& outro) const;

        /**
         * @brief Sobrecarga do operador de extração.
         * @details utilizada para chamar o método printOutDados(), podendo
         * ser definido nas classes derivadas. Da acesso a impressão de dados
         * do animal diretamente do stream de saída.
         * @return Stream de saída padrão com os resultados da função
         * printOutDados().
         */
        friend ostream& operator<< (ostream& o, Animal& animal);
    protected:
        string nome;
        string especie;
        Veterinario veterinario;
        /** @brief A classe do animal pode indicar a necessidade de um Tratador com Uniforme específico */
        Tratador tratador;
        bool perigoso;
};