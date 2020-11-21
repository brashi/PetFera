#include <iostream>
#include "pessoa.hpp"

int main() {

    std::cout << "Oi," << std::endl;
    Pessoa *pepe = new Pessoa("Funcionario De testes", "(84) 9999-6666", "func1@petfera.com.br");

    std::cout << pepe->getNome() << std::endl;
    std::cout << pepe->getTelefone() << std::endl;
    std::cout << pepe->getEmail() << std::endl;


    return 0;
}