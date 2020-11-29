#pragma once

#include "tratador.hpp"
#include "veterinario.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::string;
using std::vector;
using std::dynamic_pointer_cast;


using std::shared_ptr;
using std::make_shared;

/**
 * @brief Implementação base para o cadastro de animais.
 * @details O cadastro de um animal passa pela base Animal. Exigindo
 * uma série de informações comuns a todos os animais, tais como
 * nome, especie, seu Veterinario e Tratador.
 */
class Animal {
    public:
        Animal() {};
        /**
         * @brief Construtor da classe base Animal
         * @details O construtor faz a base para a criação
         * de dados presentes em qualquer animal. Serve como
         * base para os construtores de suas herdeiras.
         * @param nome como string
         * @param especie como string
         * @param ameaça como string, se esta ameaçado por extinção
         * @param Veterinario como tipo Veterinario
         * @param Tratador como tipo Tratador
         * @param perigoso como bool
         */
        Animal(string nome, string especie, string ameacadoPor, Veterinario veterinario,
            Tratador tratador, bool perigoso);
        /** 
         * @brief destrutor padrão para base
         * @details deve ser virtual por questões
         * de polimorfismo entre as classes herdeiras.
         */
        virtual ~Animal();

        /** 
         * @brief getter de string
         * @return nome do Animal como
         * uma string
         */
        string getNome() const;
        /**
         * @brief getter de string
         * @return especie do Animal
         * como uma string
         */
        string getEspecie() const;
        /**
         * @brief getter de string
         * @return a situação de preservação
         * do Animal. Declarando se o mesmo
         * se encontra ameaçado por algum
         * fator especifico dado por uma string.
         */
        string getAmeacadoPor() const;
        /**
         * @brief getter de tipo Veterinario
         * @return Veterinario responsável
         * pelo animal em questão.
         */
        Veterinario getVeterinario() const;
        /**
         * @brief getter de tipo Tratador
         * @return Tratador responsável
         * pelo animal em questão.
         */
        Tratador getTratador() const;
        /**
         * @brief getter de bool
         * @return bool de verdadeiro
         * ou falso se o animal apresenta
         * algum perigo ao manejo.
         */
        bool getPerigoso() const;

        //Setters
        
        void setNome(string s);

        bool setNome();

        void setEspecie(string s);

        bool setEspecie();

        void setAmeacadoPor(string s);

        bool setAmeacadoPor();

        void setPerigoso(bool b);

        bool setPerigoso();

        void setVeterinario(Veterinario veterinario);

        void setTratador(Tratador tratador);

        /**
         * @details getter de string
         * @details com base em casts para
         * o uma classe especifica. Define
         * uma string com a categoria do animal.
         * @param Animal em questão.
         * @return String com a categoria do animal.
         */
        string getClassificacao(shared_ptr<Animal> animal) const;
        /**
         * @details getter de string
         * @details com base em casts para
         * o uma classe especifica. Define
         * uma string com a classificação do animal.
         * @param Animal em questão.
         * @return String com a classificação do animal.
         */
        string getClasse(shared_ptr<Animal> animal) const;

        string setClassificacao();
        
        string setClasse();

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
        ostream& printOutDados(ostream& o, shared_ptr<Animal> animal) const;

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
        friend ostream& operator<< (ostream& o, shared_ptr<Animal> animal);
    protected:
        /** String declarando o nome do Animal */
        string nome;
        /** String declarando sua espécie */
        string especie;
        /** @brief Declara se o animal é ameaçado por alguma causa. Possui valor "nada" caso contrário */
        string ameacadoPor;
        /** @brief O Veterinario responsável pelo animal em questão */
        Veterinario veterinario;
        /** @brief A classe do animal pode indicar a necessidade de um Tratador com Uniforme específico */
        Tratador tratador;
        /** @brief Declara se o animal apresenta perigo ao manejo */
        bool perigoso;
};