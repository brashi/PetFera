//Classes associadas
#include "petshop.hpp"
#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"

#include <iomanip>
#include <iostream>

using std::cout;
using std::cin;

Petshop::Petshop() {}

Petshop::~Petshop() {
    for(auto& vet : this->veterinarios) {
        delete vet;
    }

    for(auto& tratador : this->tratadores) {
        delete tratador;
    }

    for(auto& animal : this->animais) {
        delete animal;
    }
}

bool Petshop::adicionarVeterinario(Veterinario* vetAdd) {
    this->veterinarios.push_back(vetAdd);
    return true;
}

bool Petshop::adicionarTratador(Tratador* tratAdd) {
    this->tratadores.push_back(tratAdd);
    return true;
}

bool Petshop::adicionarAnimal(Animal* animalAdd) {
    this->animais.push_back(animalAdd);
    return true;
}

// Criação
bool Petshop::criarVeterinario() {
}

bool Petshop::criarTratador() {

}

bool Petshop::criarAnimal() {

}

// Leitura
vector<Animal*> Petshop::getAnimais() const {
}

vector<Veterinario*> Petshop::getVeterinarios() const {
}

vector<Tratador*> Petshop::getTratadores() const {
}

// Atualização
void Petshop::atualizarVeterinario() {

}

void Petshop::atualizarTratador() {

}

void Petshop::atualizarAnimal() {
    
}

// Remoção
void Petshop::excluirVeterinario() {
    string nome;
    cout << "Nome do Vet.: ";
    cin >> nome;

    char opcao;
    Veterinario* vet = this->findVeterinario(nome);
    if(vet != nullptr) {
        cout << "Registro encontrado !" << endl;
        cout << *vet; //Usar método de listagem unica.
        cout << "Deseja realmente remove-lo dos registros ?" << endl;
        cout << endl << "\t Aperte \"S\" caso queira prosseguir ";
        cin >> opcao;

        if(opcao == 'S' || opcao == 's') {
            if(this->excluirVeterinario(vet)) {
                cout << "Sucesso, registro removido." << endl;
            } else {
                cout << "Houve algum erro na remoção do registro." << endl;
                cout << "Voltando ao menu..." << endl;
            }

        } else {
            cout << "Operação cancelada !!" << endl;
            cout << "Voltando ao menu..." << endl;
        }
        
        
    } else {
        cout << "Entrada não encontrada nos registros." << endl;
    }
}

void Petshop::excluirTratador() {
    string nome;
    cout << "Nome do Tratador: ";
    cin >> nome;

    char opcao;
    Tratador* tratador = this->findTratador(nome);
    if(tratador != nullptr) {
        cout << "Registro encontrado !" << endl;
        cout << *tratador; //Usar método de listagem unica.
        cout << "Deseja realmente remove-lo dos registros ?" << endl;
        cout << endl << "\t Aperte \"S\" caso queira prosseguir ";
        cin >> opcao;

        if(opcao == 'S' || opcao == 's') {
            if(this->excluirTratador(tratador)) {
                cout << "Sucesso, registro removido." << endl;
            } else {
                cout << "Houve algum erro na remoção do registro." << endl;
                cout << "Voltando ao menu..." << endl;
            }

        } else {
            cout << "Operação cancelada !!" << endl;
            cout << "Voltando ao menu..." << endl;
        }
        
        
    } else {
        cout << "Entrada não encontrada nos registros." << endl;
    }
}

void Petshop::excluirAnimal() {
    string nome, especie;
    cout << "Nome do animal: ";
    cin >> nome;
    cout << "Especie do animal: ";
    cin >> especie;

    char opcao;
    Animal* animal = this->findAnimal(nome, especie);
    if(animal != nullptr) {
        cout << "Registro encontrado !" << endl;
        cout << *animal; //Usar método de listagem unica.
        cout << "Deseja realmente remove-lo dos registros ?" << endl;
        cout << endl << "\t Aperte \"S\" caso queira prosseguir ";
        cin >> opcao;

        if(opcao == 'S' || opcao == 's') {
            if(this->excluirAnimal(animal)) {
                cout << "Sucesso, registro removido." << endl;
            } else {
                cout << "Houve algum erro na remoção do registro." << endl;
                cout << "Voltando ao menu..." << endl;
            }

        } else {
            cout << "Operação cancelada !!" << endl;
            cout << "Voltando ao menu..." << endl;
        }
        
        
    } else {
        cout << "Entrada não encontrada nos registros." << endl;
    }
}

Veterinario* Petshop::excluirVeterinario(Veterinario* removido) {
    int index = 0;

    for(auto& vet : this->veterinarios) {
        if(*vet == *removido) {
            Veterinario* ptr_removido = vet;
            this->veterinarios.erase(this->veterinarios.begin() + index);
            return ptr_removido;
        }
        index++;
    }

    return nullptr;
}

Tratador* Petshop::excluirTratador(Tratador* removido) {
    int index = 0;

    for(auto& tratador : this->tratadores) {
        if(*tratador == *removido) {
            Tratador* ptr_removido = tratador;
            this->tratadores.erase(this->tratadores.begin() + index);
            return ptr_removido;
        }
        index++;
    }

    return nullptr;
}

Animal* Petshop::excluirAnimal(Animal* removido) {
    int index = 0;

    for(auto& animal : this->animais) {
        if(*animal == *removido) {
            Animal* ptr_removido = animal;
            this->animais.erase(this->animais.begin() + index);
            return ptr_removido;
        }
        index++;
    }

    return nullptr;
}

Veterinario* Petshop::findVeterinario(string nome) {
    for(auto& vet : this->veterinarios) {
        if(vet->getNome() == nome) {
            return vet;
        }
    }
    return nullptr;

}

Tratador* Petshop::findTratador(string nome) {
    for(auto& trata : this->tratadores) {
        if(trata->getNome() == nome) {
            return trata;
        }
    }
    return nullptr;
    
}

Animal* Petshop::findAnimal(string nome, string especie) {
    for(auto& animal : this->animais) {
        if(animal->getNome() == nome && animal->getEspecie() == especie) {
            return animal;
        }
    }
    return nullptr;
    
}