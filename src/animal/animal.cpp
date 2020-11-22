#include "animal.hpp"
#include "ave.hpp"

Animal::Animal(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso):
                nome(nome), especie(especie), veterinario(veterinario), tratador(tratador),
                perigoso(perigoso){}

Animal::~Animal(){}

string Animal::getNome() const {
    return this->nome;
}

string Animal::getEspecie() const {
    return this->especie;
}

Veterinario Animal::getVeterinario() const {
    return this->veterinario;
}

Tratador Animal::getTratador() const {
    return this->tratador;
}

bool Animal::getPerigoso() const {
    return this->perigoso;
}
ostream& Animal::printOutDados(ostream& o, Animal* animal) const {
    o << "Testando Print de animais genericos" << endl;
    if(Ave* teste = dynamic_cast< Ave* >(animal)) {
        o << "Tipo: Ave" << endl;
    } else {
        o << "Nao é ave" << endl;
    }

    return o;
}

ostream& operator<< (ostream& o, Animal& animal) {
    return animal.printOutDados(o, &animal);
}