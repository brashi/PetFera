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
        Tratador(string nome, string telefone, string email,
                Uniforme uniforme);

        ~Tratador();
        Uniforme getUniforme() const;

        ostream& printOutDados(ostream& o) const;

    private:
        Uniforme uniforme;

};