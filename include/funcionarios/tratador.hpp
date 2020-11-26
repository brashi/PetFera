#pragma once

#include "pessoa.hpp"

/** 
 * @brief Enum usado para categorizar o nível de segurança do Tratador. 
 * @details A cor do uniforme indica a quais Classes de animais o profissional pode trabalhar:
 * - Verde
 *    Permite-o trabalhar com animais do tipo Anfibio e Ave.
 * - Azul
 *    Permite-o trabalhar com Reptil e Mamifero, além dos vistos no nível anterior.
 * - Vermelho
 *    O unico que pode trabalhar com animais Perigosos, além de trabalhar com todos as Classes.
 */
enum Uniforme {
    /** @brief Anfibios e Aves. */
    Verde,
    /** @brief Anfibios, Aves, Mamiferos e Repteis. */
    Azul,
    /** @brief Todos anteriores e Animais com Perigo associado. */
    Vermelho
};

/**
 * @brief Implementação dos tratadores.
 * @details A critério das necessidades do PetShop... A classe deve prover as informações básicas
 * categorizadas em Pessoa. Tão quanto as classificações em relação a segurança no que diz respeito
 * a quais animais o tratador pode se responsabilizar, sendo definida pelo seu Uniforme.
 */
class Tratador : public Pessoa {
    public:
        Tratador() {};
        /**
         * @brief Construtor de Tratador
         * @details Herda o mesmo construtor em Pessoa,
         * com a adição de seus atributos própios.
         * @param Pessoa() igual construtor de Pessoa
         * @param Uniforme do funcionario, tipo Enum
         */
        Tratador(string nome, string telefone, string email,
                Uniforme uniforme);

        ~Tratador();

        /**
         * @brief getter de Enum
         * @return tipo Enum explicitando
         * o uniforme do tratador em questão.
         */
        Uniforme getUniforme() const;

        /**
         * @brief Implementação da stream de dados.
         * @details Retorna um stream de saida std::cout
         * com as informações da instância específica,
         * feito para a classe Tratador.
         */
        ostream& printOutDados(ostream& o) const;

    private:
        /** @brief Uniforme do funcionário, definindo seu nível de segurança. */
        Uniforme uniforme;

};