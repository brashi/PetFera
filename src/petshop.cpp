//Classes associadas
#include "petshop.hpp"
#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"

#include <map>
#include <functional>
#include <iomanip>
#include <iostream>

using std::setfill;
using std::setw;
using std::right;
using std::stoi;
using std::cout;
using std::cin;

Petshop::Petshop() {}

Petshop::~Petshop() {}

bool Petshop::adicionarVeterinario(shared_ptr<Veterinario> vetAdd) {
    this->veterinarios.push_back(vetAdd);
    return true;
}

bool Petshop::adicionarTratador(shared_ptr<Tratador> tratAdd) {
    this->tratadores.push_back(tratAdd);
    return true;
}

bool Petshop::adicionarAnimal(shared_ptr<Animal> animalAdd) {
    this->animais.push_back(animalAdd);
    return true;
}

// Criação
void Petshop::criarVeterinario() {
    string nome;
    shared_ptr<Veterinario> veterinario = make_shared<Veterinario>();

    if(veterinario->setNome())
        nome = veterinario->getNome();
    else
        throw "Veterinário deve ter um nome válido!";

    if(this->findVeterinario(nome) != nullptr)
        throw "Funcionário já existe!";

    if(!veterinario->setTelefone())
        throw "Veterinário não pode ficar sem telefone";

    if(!veterinario->setEmail())
        throw "Veterinário não pode ficar sem e-mail";

    if(!veterinario->setCRMV())
        throw "Veterinário não pode ficar sem CRMV";

    if(this->adicionarVeterinario(veterinario))
        cout << "Veterinário adicionado ao cadastro." << endl;
    else
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
}

void Petshop::criarTratador() {
    string nome;
    shared_ptr<Tratador> tratador = make_shared<Tratador>();

    if(tratador->setNome())
        nome = tratador->getNome();
    else
        throw "Tratador deve ter um nome válido!";

    if(this->findTratador(nome) != nullptr)
        throw "Funcionário já existe!";

    if(!tratador->setTelefone())
        throw "Tratador não pode ficar sem telefone";

    if(!tratador->setEmail())
        throw "Tratador não pode ficar sem e-mail";

    if(!tratador->setUniforme())
        throw "Tratador não pode ficar sem nível de segurança";

    if(this->adicionarTratador(tratador))
        cout << "Tratador adicionado ao cadastro." << endl;
    else
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
}

void Petshop::criarAnimal() {
    string nome, especie, pessoa;
    long unsigned int idPessoa;
    shared_ptr<Animal> animal;

    if(this->veterinarios.size() < 1)
        throw "Não há veterinários no sistema!"; 

    if(this->tratadores.size() < 1)
        throw "Não há tratadores no sistema!"; 

    string classe = animal->setClasse();
    if(classe.empty())
        throw "Animal deve ter uma classe válida!";

    string categoria = animal->setClassificacao();
    if(categoria.empty())
        throw "Animal deve ter uma categoria válida!";

    animal = mapa.aMap[classe + categoria]();

    if(animal->setNome())
        nome = animal->getNome();
    else
        throw "Animal deve ter um nome válido!";

    if(animal->setEspecie())
        especie = animal->getEspecie();
    else
        throw "Animal deve ter uma espécie válida!";
    
    if(findAnimal(nome, especie) != nullptr)
        throw "Animal já existe!";

    if(!animal->setAmeacadoPor()) {
        cout << "Animal não está ameaçado de extinção!" << endl;
        animal->setAmeacadoPor("Nada");
    }

    // Adiciona veterinário ao animal
    this->listarVeterinarios();
    cout << endl << "Digite o ID do veterinário responsável: " << endl;
    getline(cin, pessoa);
    idPessoa = stoi(pessoa);

    // Pela lista de vet. ser em petshop o tratamento se dá aqui, não no setter
    if(idPessoa >= 0 && idPessoa < this->veterinarios.size())
        animal->setVeterinario(*this->veterinarios[idPessoa]);
    else
        throw "Veterinário não existe!";

    if(!animal->setPerigoso())
        throw "Animal não pode ficar sem a informação de seu perigo!";

    if(classe == "ave") { // Ave
        shared_ptr<Ave> classe = dynamic_pointer_cast< Ave >(animal);

        if(!classe->setVoa())
            throw "Informe se a ave voa!";

    } else if(classe == "mam") { // Mamífero
        shared_ptr<Mamifero> classe = dynamic_pointer_cast< Mamifero >(animal);

        if(!classe->setGestacao())
            throw "Informe se o mamífero possui gestação!";

    } else if(classe == "rep") { // Réptil
        shared_ptr<Reptil> classe = dynamic_pointer_cast< Reptil >(animal);

        if(!classe->setPele())
            throw "Informe se o réptil possui pele!";

    } else if(classe == "anf") { // Anfíbio
        shared_ptr<Anfibio> classe = dynamic_pointer_cast< Anfibio >(animal);

        if(!classe->setCauda())
            throw "Informe se o anfíbio possui cauda!";

        if(!classe->setPata())
            throw "Informe se o anfíbio possui pata!";

    } else
        throw "Algo de errado aconteceu na criação de animal, verifique se a classe informada condiz com o que foi pedido pela aplicação.";

    // Adiciona tratador ao animal
    this->listarTratadores();
    cout << endl << "Digite o ID do tratador responsável: " << endl;
    getline(cin, pessoa);
    idPessoa = stoi(pessoa);

    // Pela lista de trt. ser em petshop o tratador se dá aqui, não no setter
    if(idPessoa >= 0 && idPessoa < this->tratadores.size())
        animal->setTratador(*this->tratadores[idPessoa]);
    else
        throw "Tratador não existe!";

    // Tratamento de permissão
    Uniforme un = animal->getTratador().getUniforme();
    if(animal->getPerigoso() && un != Vermelho)
        throw "Erro de permissão! O tratador necessita de ao menos um nível de segurança Vermelho.";
    else if((classe == "rep" || classe == "mam") && (un == Verde))
        throw "Erro de permissão! O tratador necessita de ao menos um nível de segurança Azul.";

    if(categoria == "D") { // Animal Doméstico
        shared_ptr<Domestico> categoria = dynamic_pointer_cast< Domestico >(animal);

        if(!categoria->setAdestrado())
            throw "Informe um valor válido de adestramento!";

    } else if(categoria == "N") { // Silvestre Nativo
        shared_ptr<Nativo> categoria = dynamic_pointer_cast< Nativo >(animal);

        if(!categoria->setLicenca())
            throw "Informe um valor válido para a licença!";

        if(!categoria->setRegiao())
            throw "Informe uma região válida!";

    } else if(categoria == "E") { // Silvestre Exótico
        shared_ptr<Exotico> categoria = dynamic_pointer_cast< Exotico >(animal);

        if(!categoria->setLocal())
            throw "Informe um habitat válido!";

    } else
        throw "Algo de errado aconteceu na criação de animal, verifique se a categoria informada condiz com o que foi pedido pela aplicação.";

    if(this->adicionarAnimal(animal))
        cout << "Animal adicionado ao cadastro." << endl;
    else
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
}

// Atualização
void Petshop::atualizarVeterinario() {
    string nome;
    
    shared_ptr<Veterinario> veterinario;
    long unsigned int num;

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    if(this->veterinarios.size() == 0)
        throw "Não há veterinários para remover no sistema!";

    cout << endl << "Veterinários registrados: " << endl;
    this->listarVeterinarios();
    cout << endl << "Digite o ID do veterinário a ser alterado: ";
    getline(cin, nome);
    num = stoi(nome);
    if(num >= 0 && num < this->veterinarios.size())
        veterinario = this->veterinarios[num];
    else
        throw "Veterinário não existe!";

    cout << endl << updateText;
    veterinario->setNome();

    cout << endl << updateText;
    veterinario->setEmail();

    cout << endl << updateText;
    veterinario->setTelefone();

    cout << endl << updateText;
    veterinario->setCRMV();
}

void Petshop::atualizarTratador() {
    string nome;

    shared_ptr<Tratador> tratador;
    long unsigned int num;

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    if(this->tratadores.size() == 0)
        throw "Não há tratadores para remover no sistema!";

    cout << endl << "Tratadores registrados: " << endl;
    this->listarTratadores();
    cout << endl << "Digite o ID do tratador a ser alterado: ";
    getline(cin, nome);
    num = stoi(nome);
    if(num >= 0 && num < this->tratadores.size())
        tratador = this->tratadores[num];
    else
        throw "Tratador não existe!";

    cout << endl << updateText;
    tratador->setNome();

    cout << endl << updateText;
    tratador->setEmail();

    cout << endl << updateText;
    tratador->setTelefone();

    cout << endl << updateText;
    tratador->setUniforme();
}

void Petshop::atualizarAnimal() {
    string nome, pessoa;
    bool trocarHerancas = false;
    long unsigned int idPessoa;

    shared_ptr<Animal> animal;
    long unsigned int num;

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    cout << endl << "Animais registrados: " << endl;
    this->listarAnimais(true);
    cout << endl << "Digite o ID do animal a ser alterado: ";
    getline(cin, nome);
    num = stoi(nome);
    if(num >= 0 && num < this->animais.size())
        animal = this->animais[num];
    else
        throw "Animal não existe!";

    cout << endl << updateText;
    string classe = animal->setClasse();
    if(!classe.empty())
        trocarHerancas = true;
    else
        classe = animal->getClasse(animal);

    cout << endl << updateText;
    string categoria = animal->setClassificacao();
    if(!categoria.empty())
        trocarHerancas = true;
    else
        categoria = animal->getClassificacao(animal);

    // Animal que será atualizado *de facto*
    shared_ptr<Animal> atualizar;

    if(trocarHerancas)
        atualizar = mapa.aMap[classe + categoria]();
    else
        atualizar = animal;

    cout << endl << updateText;
    if(!atualizar->setNome() && trocarHerancas)
        atualizar->setNome(animal->getNome());

    cout << endl << updateText;
    if(!atualizar->setEspecie() && trocarHerancas)
        atualizar->setEspecie(animal->getEspecie());

    cout << endl << updateText;
    if(!atualizar->setAmeacadoPor() && trocarHerancas)
        atualizar->setAmeacadoPor(animal->getAmeacadoPor());

    // Veterinário
    this->listarVeterinarios();
    cout << endl << updateText;
    cout << endl << "Digite o ID do veterinário responsável: " << endl;
    getline(cin, pessoa);
    if(pessoa.size() == 0 && trocarHerancas)
        atualizar->setVeterinario(animal->getVeterinario());
    else if(pessoa.size() != 0) {
        idPessoa = stoi(pessoa);

        // Pela lista de vet. ser em petshop o tratamento se dá aqui, não no setter
        if(idPessoa >= 0 && idPessoa < this->veterinarios.size())
            atualizar->setVeterinario(*this->veterinarios[idPessoa]);
        else if(trocarHerancas)
            atualizar->setVeterinario(animal->getVeterinario());
    }

    cout << endl << updateText;
    if(!atualizar->setPerigoso() && trocarHerancas)
        atualizar->setPerigoso(animal->getPerigoso());

    // Classe
    if(classe == "ave" || classe == "Ave") { // Ave
        shared_ptr<Ave> classe = dynamic_pointer_cast< Ave >(atualizar);

        cout << endl << updateText;
        if(!classe->setVoa() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

    } else if(classe == "mam" || classe == "Mamífero") { // Mamífero
        shared_ptr<Mamifero> classe = dynamic_pointer_cast< Mamifero >(atualizar);
    
        cout << endl << updateText;
        if(!classe->setGestacao() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

    } else if(classe == "rep" || classe == "Réptil") { // Réptil
        shared_ptr<Reptil> classe = dynamic_pointer_cast< Reptil >(atualizar);

        cout << endl << updateText;
        if(!classe->setPele() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

    } else if(classe == "anf" || classe == "Anfíbio") { // Anfíbio
        shared_ptr<Anfibio> classe = dynamic_pointer_cast< Anfibio >(atualizar);

        cout << endl << updateText;
        if(!classe->setCauda() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

        cout << endl << updateText;
        if(!classe->setPata() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";
    }

    // Tratador
    this->listarTratadores();
    cout << endl << updateText;
    cout << endl << "Digite o ID do tratador responsável: " << endl;
    getline(cin, pessoa);
    if(pessoa.size() == 0 && trocarHerancas)
        atualizar->setTratador(animal->getTratador());
    else if(pessoa.size() != 0) {
        idPessoa = stoi(pessoa);

        // Pela lista de trt. ser em petshop o tratamento se dá aqui, não no setter
        if(idPessoa >= 0 && idPessoa < this->tratadores.size())
            atualizar->setTratador(*this->tratadores[idPessoa]);
        else if(trocarHerancas)
            atualizar->setTratador(animal->getTratador());
    }

    // Classificação
    if(categoria == "N" || categoria == "Silvestre Nativo") { // Silvestre Nativo
        shared_ptr<Nativo> categoria = dynamic_pointer_cast< Nativo >(atualizar);

        cout << endl << updateText;
        if(!categoria->setLicenca() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";
        
        cout << endl << updateText;
        if(!categoria->setRegiao() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";

    } else if(categoria == "E" || categoria == "Silvestre Exótico") { // Silvestre Exótico
        shared_ptr<Exotico> categoria = dynamic_pointer_cast< Exotico >(atualizar);
    
        cout << endl << updateText;
        if(!categoria->setLocal() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";

    } else if(categoria == "D" || categoria == "Doméstico") { // Doméstico
        shared_ptr<Domestico> categoria = dynamic_pointer_cast< Domestico >(atualizar);

        cout << endl << updateText;
        if(!categoria->setAdestrado() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";

    }

    // Tratamento de permissão
    Uniforme un = atualizar->getTratador().getUniforme();
    if(atualizar->getPerigoso() && un != Vermelho) {
        throw "Erro de permissão, o tratador informado não possui permissão para manejar esse animal, cadastre ou altere um tratador e tente novamente.";
    } else if((classe == "rep" || classe == "mam") && (un == Verde)) {
        throw "Erro de permissão, o tratador informado não possui permissão para manejar esse animal, cadastre ou altere um tratador e tente novamente.";
    }

    if(trocarHerancas) {
        this->excluirAnimal(animal);
        //delete animal;

        if(this->adicionarAnimal(atualizar))
            cout << "Animal atualizado com sucesso" << endl;
        else
            cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    } else
        cout << "Animal atualizado com sucesso" << endl;
}

// Remoção
void Petshop::excluirVeterinario() {
    string idPessoa, s;
    shared_ptr<Veterinario> veterinario;
    long unsigned int num;

    if(this->veterinarios.size() == 0)
        throw "Não há veterinários para remover no sistema!";

    cout << endl << "Veterinários registrados: " << endl;
    this->listarVeterinarios();
    cout << endl << "Digite o ID do veterinário a ser removido: ";
    getline(cin, idPessoa);
    num = stoi(idPessoa);
    if(num >= 0 && num < this->veterinarios.size())
        veterinario = this->veterinarios[num];
    else
        throw "Veterinário não existe!";

    int animais = 0;
    for(auto& animal : this->animais)
        if(*veterinario == animal->getVeterinario())
            animais++;

    string error = "O veterinário cuida de " + std::to_string(animais) + " animais !\n Portando, ele não pode se removido, verifique nas listagens e tente novamente !";
    if(animais > 0) 
        throw error;

    cout << endl << "Tem certeza que deseja excluir? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        if(this->excluirVeterinario(veterinario))
            cout << "Operação concluída" << endl;
        else
            throw "Erro ao excluir veterinário, tente novamente";
    else
        cout << "Operação cancelada" << endl;
}

void Petshop::excluirTratador() {
    string idPessoa, s;
    shared_ptr<Tratador> tratador;
    long unsigned int num;

    if(this->tratadores.size() == 0)
        throw "Não há tratadores para remover no sistema!";

    
    cout << endl << "Tratadores registrados: " << endl;
    this->listarTratadores();
    cout << endl << "Digite o ID do tratador a ser removido: ";
    getline(cin, idPessoa);
    num = stoi(idPessoa);
    if(num >= 0 && num < this->tratadores.size())
        tratador = this->tratadores[num];
    else
        throw "Tratador não existe!";


    int animais = 0;
    for(auto& animal : this->animais)
        if(*tratador == animal->getTratador())
            animais++;

    string error = "O tratador cuida de " + std::to_string(animais) + " animais !\n Portando, ele não pode se removido, verifique nas listagens e tente novamente !";
    if(animais > 0)
        throw error;
    cout << endl << "Tem certeza que deseja excluir? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        if(this->excluirTratador(tratador))
            cout << "Operação concluída" << endl;
        else
            throw "Erro ao excluir tratador, tente novamente";
    else
        cout << "Operação cancelada" << endl;
}

void Petshop::excluirAnimal() {
    string idAnimal, s;
    shared_ptr<Animal> animal;
    long unsigned int num;

    if(this->animais.size() == 0)
        throw "Não há animais para remover no sistema!";

    
    cout << endl << "Animais registrados: " << endl;
    this->listarAnimais(true);
    cout << endl << "Digite o ID do animal a ser removido: ";
    getline(cin, idAnimal);
    num = stoi(idAnimal);
    if(num >= 0 && num < this->animais.size())
        animal = this->animais[num];
    else
        throw "Animal não existe!";


    cout << endl << "Tem certeza que deseja excluir? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        if(this->excluirAnimal(animal))
            cout << "Operação concluída" << endl;
        else
            throw "Erro ao excluir animal, tente novamente";
    else
        cout << "Operação cancelada" << endl;
}

shared_ptr<Veterinario> Petshop::excluirVeterinario(shared_ptr<Veterinario> removido) {
    int index = 0;

    for(auto& vet : this->veterinarios) {
        if(vet == removido) {
            shared_ptr<Veterinario> ptr_removido = vet;
            this->veterinarios.erase(this->veterinarios.begin() + index);
            return ptr_removido;
        }
        index++;
    }

    return nullptr;
}

shared_ptr<Tratador> Petshop::excluirTratador(shared_ptr<Tratador> removido) {
    int index = 0;

    for(auto& tratador : this->tratadores) {
        if(tratador == removido) {
            shared_ptr<Tratador> ptr_removido = tratador;
            this->tratadores.erase(this->tratadores.begin() + index);
            return ptr_removido;
        }
        index++;
    }

    return nullptr;
}

shared_ptr<Animal> Petshop::excluirAnimal(shared_ptr<Animal> removido) {
    int index = 0;

    for(auto& animal : this->animais) {
        if(animal == removido) {
            shared_ptr<Animal> ptr_removido = animal;
            this->animais.erase(this->animais.begin() + index);
            return ptr_removido;
        }
        index++;
    }

    return nullptr;
}

// Métodos para "encontrar"
shared_ptr<Veterinario> Petshop::findVeterinario(string nome) {
    for(auto& vet : this->veterinarios) {
        if(vet->getNome() == nome) {
            return vet;
        }
    }
    return nullptr;
}

shared_ptr<Tratador> Petshop::findTratador(string nome) {
    for(auto& trata : this->tratadores) {
        if(trata->getNome() == nome) {
            return trata;
        }
    }
    return nullptr;
}

shared_ptr<Animal> Petshop::findAnimal(string nome, string especie) {
    for(auto& animal : this->animais) {
        if(animal->getNome() == nome && animal->getEspecie() == especie) {
            return animal;
        }
    }
    return nullptr;
}

// Listar
void Petshop::listarTratadores() {
    if(this->tratadores.size() == 0) {
        cout << "Não há tratadores registrados" << endl;
    } else {
        int index = 0;
        cout << endl << "-=-=-=-=-=-=-= Tratadores =-=-=-=-=-=-=" << endl;
        cout << right << setfill(' ') << setw(6) << "ID"
        << setfill(' ') << setw(23) << "Nome"
        << setfill(' ') << setw(23) << "E-mail"
        << setfill(' ') << setw(23) << "Telefone"
        << setfill(' ') << setw(23) << "N. segurança"
        << endl;
        for(auto& trt : this->tratadores) {
            cout << right << setfill(' ') << setw(6) << index << *trt;
            index++;
        }
        cout << endl << "-=-=-=-=-=-=-=-=- Fim -=-=-=-=-=-=-=-=-" << endl;
    }
}

void Petshop::listarVeterinarios() {
    if(this->veterinarios.size() == 0) {
        cout << "Não há veterinários registrados" << endl;
    } else {
        int index = 0;
        cout << endl << "-=-=-=-=-=-=- Veterinários -=-=-=-=-=-=" << endl;
        cout << right << setfill(' ') << setw(6) << "ID"
        << setfill(' ') << setw(23) << "Nome"
        << setfill(' ') << setw(23) << "E-mail"
        << setfill(' ') << setw(23) << "Telefone"
        << setfill(' ') << setw(23) << "CRMV"
        << endl;
        for(auto& vet : this->veterinarios) {
            cout << right << setfill(' ') << setw(6) << index << *vet;
            index++;
        }
        cout << endl << "-=-=-=-=-=-=-=-=- Fim -=-=-=-=-=-=-=-=-" << endl;
    }
}

void Petshop::listarAnimais(bool autoList) {
    Veterinario vet;
    Tratador trt;
    string filtro = {}, idPessoa = {}, animalID = {};

    if(autoList)
        goto listBypass;

    if(this->animais.size() == 0)
        throw "Não há animais para visualizar no sistema!";

    cout << "Escolha seu filtro: " << endl << endl;
    cout << "Enter - Todos (sem filtro)" << endl;
    cout << "A - Apenas aves" << endl;
    cout << "F - Apenas anfíbios" << endl;
    cout << "R - Apenas répteis" << endl;
    cout << "M - Apenas mamíferos" << endl;
    cout << "D - Apenas animais domésticos" << endl;
    cout << "E - Apenas silvestres exóticos" << endl;
    cout << "N - Apenas silvestres nativos" << endl;
    cout << "T - Filtrar por tratador" << endl;
    cout << "V - Filtrar por veterinário" << endl;

    getline(cin, filtro);
    long unsigned int num;

listBypass:
    if(filtro.empty())
        filtro = "X";

    if(filtro == "T" || filtro == "t") {
        if(this->tratadores.size() == 0)
            throw "Não há tratadores no sistema!";

        cout << "Digite o ID do tratador responsável: " << endl;
        this->listarTratadores();
        getline(cin, idPessoa);
        num = stoi(idPessoa);
        if(num >= 0 && num < this->tratadores.size())
            trt = *this->tratadores[num];
        else
            throw "Tratador não existe!";
    } else if(filtro == "V" || filtro == "v") {
        if(this->veterinarios.size() == 0)
            throw "Não há veterinários no sistema!";

        cout << "Digite o ID do veterinário responsável: " << endl;
        this->listarVeterinarios();
        getline(cin, idPessoa);
        num = stoi(idPessoa);
        if(num >= 0 && num < this->veterinarios.size())
            vet = *this->veterinarios[num];
        else
            throw "Veterinário não existe!";
    }

    // Imprime cabeçalho:
    cout << endl << "=-=-=-=-=- Lista de animais -=-=-=-=-=-" << endl;
    cout << right << setfill(' ') << setw(6) << "ID"
    << setfill(' ') << setw(23) << "Nome"
    << setfill(' ') << setw(23) << "Espécie"
    << setfill(' ') << setw(23) << "Classificação"
    << setfill(' ') << setw(23) << "Classe"
    << right<< endl;

    int index = 0;
    char selecao = toupper(filtro[0]);
    for(auto& animal : this->animais) {
        if(selecao == 'V') {
            if(animal->getVeterinario() == vet)
                cout << right << setfill(' ') << setw(6) << index << animal;
        } else if(selecao == 'T') {
            if(animal->getTratador() == trt)
                cout << right << setfill(' ') << setw(6) << index << animal;
        } else {
            if(casts.filtro[selecao](animal))
                cout << right << setfill(' ') << setw(6) << index << animal;
        }
        index++;
    }
    cout << endl << "-=-=-=-=-=-=-=-=- Fim -=-=-=-=-=-=-=-=-" << endl << endl;

    if(!autoList) {
        cout << endl << "Digite o ID de um animal a ser visualizado: " << endl;
        cout << "(Mantenha em branco para cancelar a operação)" << endl;
        getline(cin, animalID);
        if(animalID.size() != 0) {
            num = stoi(animalID);
            this->animais[num]->printOutDetails(this->animais[num]);
        } else
            cout << "Operação cancelada..." << endl;
    }
}