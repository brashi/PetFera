#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;

/** 
 * @brief Classe base dos funcionarios
 * @details Serve para dar base às classes de funcionarios, definindo
 * seus atributos comuns. Sendo elas os funcionários do PetShop
 * disponíveis a cadastro: Veterinario e Tratador.
 */
class Pessoa {
    public:
        Pessoa() {};
        Pessoa(string nome, string telefone, string email);
        virtual ~Pessoa();

        string getNome() const;
        string getTelefone() const;
        string getEmail() const;

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

        /**
         * @brief Sobrecarga do operador de extração.
         * @param cout dado pela operação.
         * @param Pessoa também dado na operação.
         * @return cout usado na impressão em stream.
         */
        friend ostream& operator<< (ostream& o, Pessoa& pessoa);

    protected:
        string nome;
        string telefone;
        string email;
};