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
    string nome;
    Veterinario* veterinario = new Veterinario();

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
    Tratador* tratador = new Tratador();

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
    int idPessoa;

    Animal* animal;

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
        Ave* classe = dynamic_cast< Ave* >(animal);

        if(!classe->setVoa())
            throw "Informe se a ave voa!";

    } else if(classe == "mam") { // Mamífero
        Mamifero* classe = dynamic_cast< Mamifero* >(animal);

        if(!classe->setGestacao())
            throw "Informe se o mamífero possui gestação!";

    } else if(classe == "rep") { // Réptil
        Reptil* classe = dynamic_cast< Reptil* >(animal);

        if(!classe->setPele())
            throw "Informe se o réptil possui pele!";

    } else if(classe == "anf") { // Anfíbio
        Anfibio* classe = dynamic_cast< Anfibio* >(animal);

        if(classe->setCauda())
            throw "Informe se o anfíbio possui cauda!";

        if(classe->setPata())
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
        Domestico* categoria = dynamic_cast< Domestico* >(animal);

        if(!categoria->setAdestrado())
            throw "Informe um valor válido de adestramento!";

    } else if(categoria == "N") { // Silvestre Nativo
        Nativo* categoria = dynamic_cast< Nativo* >(animal);

        if(!categoria->setLicenca())
            throw "Informe um valor válido para a licença!";

        if(!categoria->setRegiao())
            throw "Informe uma região válida!";

    } else if(categoria == "E") { // Silvestre Exótico
        Exotico* categoria = dynamic_cast< Exotico* >(animal);

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

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    cout << endl << "Nome do veterinário: " << endl;
    getline(cin, nome);
    if (nome.size() == 0)
        throw "Não é possível pesquisar um veterinário sem nome!";

    Veterinario* veterinario = findVeterinario(nome);

    if(veterinario == nullptr)
        throw "Veterinário não encontrado! Verifique os dados e tente novamente";
    else
        cout << "Veterinário encontrado!" << endl;

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

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    cout << endl << "Nome do tratador: " << endl;
    getline(cin, nome);
    if (nome.size() == 0)
        throw "Não é possível pesquisar um tratador sem nome!";

    Tratador* tratador = findTratador(nome);

    if(tratador == nullptr)
        throw "Tratador não encontrado! Verifique os dados e tente novamente";
    else
        cout << "Tratador encontrado!" << endl;

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
    string nome, especie, pessoa;
    bool trocarHerancas = false;
    int idPessoa;

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    cout << endl << "Nome do animal: " << endl;
    getline(cin, nome);
    if (nome.size() == 0)
        throw "Não é possível pesquisar animal sem nome!";
    
    cout << "E sua espécie?" << endl;
    getline(cin, especie);
    if (especie.size() == 0)
        throw "Não é possível pesquisar animal sem espécie!";

    Animal* animal = findAnimal(nome, especie);

    if(animal == nullptr)
        throw "Animal não encontrado! Verifique os dados e tente novamente";
    else
        cout << "Animal encontrado!" << endl;

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
    Animal* atualizar;

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
        Ave* classe = dynamic_cast< Ave* >(atualizar);

        cout << endl << updateText;
        if(!classe->setVoa() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

    } else if(classe == "mam" || classe == "Mamífero") { // Mamífero
        Mamifero* classe = dynamic_cast< Mamifero* >(atualizar);
    
        cout << endl << updateText;
        if(!classe->setGestacao() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

    } else if(classe == "rep" || classe == "Réptil") { // Réptil
        Reptil* classe = dynamic_cast< Reptil* >(atualizar);

        cout << endl << updateText;
        if(!classe->setPele() && trocarHerancas)
            throw "Para troca de classes é necessário informar tal informação. Operação cancelada";

    } else if(classe == "anf" || classe == "Anfíbio") { // Anfíbio
        Anfibio* classe = dynamic_cast< Anfibio* >(atualizar);

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
        Nativo* categoria = dynamic_cast< Nativo* >(atualizar);

        cout << endl << updateText;
        if(!categoria->setLicenca() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";
        
        cout << endl << updateText;
        if(!categoria->setRegiao() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";

    } else if(categoria == "E" || categoria == "Silvestre Exótico") { // Silvestre Exótico
        Exotico* categoria = dynamic_cast< Exotico* >(atualizar);
    
        cout << endl << updateText;
        if(!categoria->setLocal() && trocarHerancas)
            throw "Para troca de categorias é necessário informar tal informação. Operação cancelada";

    } else if(categoria == "D" || categoria == "Doméstico") { // Doméstico
        Domestico* categoria = dynamic_cast< Domestico* >(atualizar);

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
        delete animal;

        if(this->adicionarAnimal(atualizar))
            cout << "Animal atualizado com sucesso" << endl;
        else
            cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    } else
        cout << "Animal atualizado com sucesso" << endl;
}

// Remoção
void Petshop::excluirVeterinario() {
    string s;

    cout << endl << "Nome do veterinário: " << endl;
    getline(cin, s);
    if (s.size() == 0)
        throw "Não é possível pesquisar um veterinário sem nome!";

    Veterinario* veterinario = findVeterinario(s);

    if(veterinario == nullptr)
        throw "Veterinário não encontrado! Verifique os dados e tente novamente";
    else
        cout << "Veterinário encontrado!" << endl;

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
    string s;

    cout << endl << "Nome do tratador: " << endl;
    getline(cin, s);
    if (s.size() == 0)
        throw "Não é possível pesquisar um tratador sem nome!";

    Tratador* tratador = findTratador(s);

    if(tratador == nullptr)
        throw "Tratador não encontrado! Verifique os dados e tente novamente";
    else
        cout << "Tratador encontrado!" << endl;

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
    string nome, especie, s;

    cout << endl << "Nome do animal: " << endl;
    getline(cin, nome);
    if (nome.size() == 0)
        throw "Não é possível pesquisar um animal sem nome!";

    cout << endl << "Espécie do animal: " << endl;
    getline(cin, especie);
    if (especie.size() == 0)
        throw "Não é possível pesquisar um animal sem espécie!";

    Animal* animal = findAnimal(nome, especie);

    if(animal == nullptr)
        throw "Animal não encontrado! Verifique os dados e tente novamente";
    else
        cout << "Animal encontrado!" << endl;

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

// Métodos para "encontrar"
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

void Petshop::listarAnimais() {
    Veterinario vet;
    Tratador trt;

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

    string filtro, idPessoa;
    getline(cin, filtro);
    int num;

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

    cout << setfill(' ') << setw(23) << "Nome"
    << setfill(' ') << setw(23) << "Espécie"
    << setfill(' ') << setw(23) << "Ameaçado por:"
    << setfill(' ') << setw(23) << "Perigoso"
    << setfill(' ') << setw(23) << "Classificação"
    << setfill(' ') << setw(23) << "Classe"
    << right<< endl;

    for(auto& animal : this->animais) {
        if(filtro == "a" || filtro == "A") {
            if( Ave* checar_ave = dynamic_cast< Ave* >(animal))
                cout << *animal;
        } else if(filtro == "f" || filtro == "F") {
            if( Anfibio* checar_anfibio = dynamic_cast< Anfibio* >(animal))
                cout << *animal;
        } else if(filtro == "r" || filtro == "R") {
            if( Reptil* checar_ave = dynamic_cast< Reptil* >(animal))
                cout << *animal;
        } else if(filtro == "m" || filtro == "M") {
            if( Mamifero* checar_ave = dynamic_cast< Mamifero* >(animal))
                cout << *animal;
        } else if(filtro == "d" || filtro == "D") {
            if( Domestico* checar_domestico = dynamic_cast< Domestico* >(animal))
                cout << *animal;
        } else if(filtro == "e" || filtro == "E") {
            if( Exotico* checar_exotico = dynamic_cast< Exotico* >(animal))
                cout << *animal;
        } else if(filtro == "n" || filtro == "N") {
            if( Nativo* checar_nativo = dynamic_cast< Nativo* >(animal))
                cout << *animal;
        } else if(filtro == "T" || filtro == "t") {
            if(animal->getTratador() == trt)
                cout << *animal;
        } else if(filtro == "V" || filtro == "v") {
            if(animal->getVeterinario() == vet)
                cout << *animal;
        } else
            cout << *animal;
    }
    cout << endl << "-=-=-=-=-=-=-=-=- Fim -=-=-=-=-=-=-=-=-" << endl << endl;
}