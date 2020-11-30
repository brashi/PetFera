#pragma once

#include <string>
#include <iostream>
#include <memory>

using std::string;
using std::ostream;
using std::endl;

using std::shared_ptr;

/** 
 * @brief Classe base dos funcionarios
 * @details Serve para dar base às classes de funcionarios, definindo
 * seus atributos comuns. Sendo elas os funcionários do PetShop
 * disponíveis a cadastro: Veterinario e Tratador.
 */
class Pessoa {
    public:
        Pessoa() {};
        /**
         * @brief Construtor base para pessoas.
         * @details A base para os funcionários é
         * declarada por aqui, embora não seja instanciada,
         * a classe Pessoa tem sua utilidade em dar base
         * aos que herdam.
         * @param nome do funcionaro
         * @param telefone para contato
         * @param email como string
         */
        Pessoa(string nome, string telefone, string email);
        /**
         * @brief Destrutor virtual
         * @details deve ser virtual para
         * servir de ponte para a criação
         * de classes herdeiras.
         */
        virtual ~Pessoa();

        /** 
         * @brief getter de string
         * @return nome como string
         */
        string getNome() const;
        
        bool setNome();

        void setNome(string s);

        /** 
         * @brief getter de string
         * @return telefone como string
         */
        string getTelefone() const;

        bool setTelefone();

        void setTelefone(string s);

        /** 
         * @brief getter de string
         * @return Email como string
         */
        string getEmail() const;

        bool setEmail();

        void setEmail(string s);

        /** 
         * @brief Método virtual para passagem ao Cout, implementado nos herdeiros.
         * @param cout dado pela sobrecarga na classe base.
         * @return cout usado para impressão em stream.
        */
        virtual ostream& printOutDados(ostream& o) const = 0;

        /**
         * @brief Sobrecarga de igualdade.
         * @param Pessoa sendo dado pela sobrecarga do operador.
         * @return Bool definindo a igualdade.
         */
        bool operator==(const Pessoa& outro) const;
        bool operator==(const shared_ptr<Pessoa> outro) const;
        /**
         * @brief Sobrecarga do operador de extração.
         * @param cout dado pela operação.
         * @param Pessoa também dado na operação.
         * @return cout usado na impressão em stream.
         */
        friend ostream& operator<< (ostream& o, Pessoa& pessoa);
        friend ostream& operator<< (ostream& o, shared_ptr<Pessoa> pessoa);

    protected:
        /** @brief Nome do funcionaro */
        string nome;
        /** @brief Telefone para contato */
        string telefone;
        /** @brief Email em forma de string */
        string email;
};