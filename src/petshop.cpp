//Classes associadas
#include "petshop.hpp"
#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"

#include "ave_domestica.hpp"
#include "ave_nativa.hpp"

#include <map>
#include <functional>
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
void Petshop::criarVeterinario() {
    Veterinario *vet = new Veterinario("placeholder", "placeholder", "Placeholder", "placeholder");
    this->adicionarVeterinario(vet);
}

void Petshop::criarTratador() {
    Tratador *trt = new Tratador("placeholder", "placeholder", "Placeholder", Azul);
    this->adicionarTratador(trt);
}

void Petshop::criarAnimal() { //FAZER EXCECAO CASO NAO TENHA VET, OU TRATADOR.
    string nome, especie;
    Veterinario vet;
    Tratador trata;
    string regiao, local, gestacao;
    bool cauda, pata, perigo;
    Pele pele;
    char opcao;
    string classe;
    string categoria;
    string animalControle;


    cout << "Nome do animal: ";
    cin >> nome;
    cout << "Especie: ";
    cin >> especie;
    
    cout << "Digite o número do veterinario responsável: " << endl << endl;
    this->listarVeterinarios();
    cout << endl;
    int num;
    cin >> num;

    vet = *this->veterinarios[num];

    cout << "Digite o número do tratador responsável: " << endl << endl;
    this->listarVeterinarios();
    cout << endl;
    num;
    cin >> num;

    trata = *this->tratadores[num];

    cout << "É perigoso ? \t S/N : ";
    cin >> opcao;
    if(opcao == 'S' || opcao == 's') {
        perigo = true;
    } else {
        perigo = false;
    }

    cout << "O animal pertence a que classe?..." << endl;
    cout << "A - ave" << endl;
    cout << "F - anfibio" << endl;
    cout << "R - reptil" << endl;
    cout << "M - mamifero" << endl;
    cin >> opcao;

    switch(toupper(opcao)) {
        case 'A': classe = "ave";
        break;

        case 'F': classe = "anf";
        break;

        case 'R': classe = "rep";
        break;

        case 'M': classe = "mam";
        break;
    }

    cout << "A que categoria o animal pertence?..." << endl;
    cout << "D - domestico" << endl;
    cout << "E - exotico" << endl;
    cout << "N - nativo" << endl;
    cin >> opcao;

    switch(opcao) {
        case 'D': categoria = "D";
        break;

        case 'E' : categoria = "E";
        break;

        case 'N' : categoria = "N";
        break;
    }

    DadosAnimal dadosNovoAnimal = (DadosAnimal) {
        .nome = nome,
        .especie = especie,
        .veterinario = vet,
        .tratador = trata,
        .perigoso = perigo,
        .regiao = regiao,
        .local = local,
        .adestrado = true, //bote valor dps
        .voa = true,
        .cauda = cauda,
        .pata = pata,
        .gestacao = gestacao,
        .pele = pele,
    };

    animalControle = classe + categoria;
    
    if(this->adicionarAnimal(mapa.aMap[animalControle](dadosNovoAnimal))) {
        cout << "Animal adicionado ao cadastro." << endl;
    } else {
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    }
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
    string nome;
    string especie;

    cout << "Qual o nome do animal ?" << endl;
    cin >> nome;
    cout << "E sua espécie?" << endl;
    cin >> especie;

    Animal* atualizar = findAnimal(nome, especie);
    if(atualizar != nullptr) {
        //SO mudando a especie, por enquanto só testando...
        cout << "nova especie: ";
        cin >> especie;

        Animal* novo = new Animal(atualizar->getNome(), especie, atualizar->getVeterinario(),
                                atualizar->getTratador(), atualizar->getPerigoso());
        
        this->excluirAnimal(atualizar);
        delete atualizar;
        this->adicionarAnimal(novo);

        cout << "Animal atualizado com sucesso" << endl;
    } else {
        cout << "O animal não se apresenta nos registros" << endl;
    }
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

void Petshop::listarTratadores() {
    int index = 0;
    for(auto& trt : this->tratadores) {
        cout << index << " - " << *trt;
        index++;
    }
}

void Petshop::listarVeterinarios() {
    int index = 0;
    for(auto& vet : this->veterinarios) {
        cout << index << " - " << *vet;
        index++;
    }
}

void Petshop::listarAnimais() {
    cout << "Escolha seu filtro: " << endl << endl;
    cout << "T - Todos (sem filtro)" << endl;
    cout << "A - Apenas aves" << endl;
    cout << "F - Apenas anfibios" << endl;
    cout << "R - Apenas repteis" << endl;
    cout << "M - Apenas mamiferos" << endl;
    char filtro;
    cin >> filtro;

    switch(toupper(filtro)) {
        case 'A' :
        for(auto& animal : this->animais) {
            if( Ave* checar_ave = dynamic_cast< Ave* >(animal))
                cout << *animal;
        }
        break;

        case 'F' :
        for(auto& animal : this->animais) {
            if( Anfibio* checar_anfibio = dynamic_cast< Anfibio* >(animal))
                cout << *animal;
        }
        break;

        case 'R' :
        for(auto& animal : this->animais) {
            if( Reptil* checar_ave = dynamic_cast< Reptil* >(animal))
                cout << *animal;
        }
        break;

        case 'M' :
        for(auto& animal : this->animais) {
            if( Mamifero* checar_ave = dynamic_cast< Mamifero* >(animal))
                cout << *animal;
        }
        break;

        case 'T' :
        for(auto& animal : this->animais) {
            cout << *animal;
        }
        break;
    }

    cout << endl << "-=-=-=-=-=-=-=-=- Fim -=-=-=-=-=-=-=-=-" << endl << endl;
}