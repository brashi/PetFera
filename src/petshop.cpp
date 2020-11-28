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
    string nome, telefone, email, CRMV;

    cout << "Nome do funcionário: " << endl;
    cin.ignore();
    getline(cin, nome);
    if (nome.size() == 0)
        throw "Funcionário sem nome!";

    if(this->findVeterinario(nome) != nullptr)
        throw "Funcionário já existe!";

    cout << endl << "Telefone: " << endl;
    getline(cin, telefone);
    if (telefone.size() == 0)
        throw "Funcionário sem telefone!";
    cout << endl << "E-mail pessoal: " << endl;
    getline(cin, email);
    if (email.size() == 0)
        throw "Funcionário sem telefone!";
    cout << endl << "CRMV do veterinário: " << endl;
    getline(cin, CRMV);
    if (CRMV.size() == 0)
        throw "Veterinário precisa de um CRMV!";

    cout << endl;
    
    Veterinario *vet = new Veterinario(nome, telefone, email, CRMV);

    if(this->adicionarVeterinario(vet)) {
        cout << "Veterinário cadastrado com sucesso" << endl;
    } else {
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    }
}

void Petshop::criarTratador() {
    string nome, telefone, email, uniforme;
    Uniforme un;

    cout << "Nome do funcionário: " << endl;
    cin.ignore();
    getline(cin, nome);
    if (nome.size() == 0)
        throw "Funcionário sem nome!";

    if(this->findTratador(nome) != nullptr)
        throw "Funcionário já existe!";

    cout << endl << "Telefone: " << endl;
    getline(cin, telefone);
    if (telefone.size() == 0)
        throw "Funcionário sem telefone!";
    cout << endl << "E-mail pessoal: " << endl;
    getline(cin, email);
    if (email.size() == 0)
        throw "Funcionário sem telefone!";
    cout << endl << "Nível de segurança:" << endl;
    cout << "V - Verde" << endl;
    cout << "A - Azul" << endl;
    cout << "M - verMelho" << endl;
    getline(cin, uniforme);
    if(uniforme == "V" || uniforme == "v") //toupper não cabe por necessariamente ser string, e não um char
        un = Verde;
    else if(uniforme == "A" || uniforme == "a")
        un = Azul;
    else if(uniforme == "M" || uniforme == "m")
        un = Vermelho;
    else
        throw "Funcionário precisa de um nível de segurança válido.";

    cout << endl;

    Tratador *trt = new Tratador(nome, telefone, email, un);

    if(this->adicionarTratador(trt)) {
        cout << "Tratador cadastrado com sucesso" << endl;
    } else {
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    }
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
    cout << endl << "Digite o número do veterinário responsável: " << endl;
    getline(cin, pessoa);
    idPessoa = stoi(pessoa);

    // Pela lista de vet. ser em petshop o tratamento se dá aqui, não no setter
    if(idPessoa >= 0 && idPessoa < this->veterinarios.size())
        animal->setVeterinario(this->veterinarios[idPessoa]);
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
    cout << endl << "Digite o número do tratador responsável: " << endl;
    getline(cin, pessoa);
    idPessoa = stoi(pessoa);

    // Pela lista de trt. ser em petshop o tratador se dá aqui, não no setter
    if(idPessoa >= 0 && idPessoa < this->tratadores.size())
        animal->setTratador(this->tratadores[idPessoa]);
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
    Veterinario* vet;
    string nomeFind, nome, telefone, email, CRMV;

    // Encontrar funcionário
    cout << "Qual o nome do funcionário a ser alterado?: " << endl;
    cin.ignore();
    getline(cin, nome);
    vet = this->findVeterinario(nome);
    if (nome.size() == 0 || vet == nullptr)
        throw "Funcionário não encontrado!";

    cout << "Alterar nome do veterinário: (para não alterar mantenha em branco)" << endl;
    getline(cin, nome);
    if (nome.size() == 0)
        nome = vet->getNome();

    cout << "Alterar telefone do veterinário: (para não alterar mantenha em branco)" << endl;
    getline(cin, telefone);
    if (telefone.size() == 0)
        telefone = vet->getTelefone();

    cout << "Alterar e-mail pessoal do veterinário: (para não alterar mantenha em branco)" << endl;
    getline(cin, email);
    if (email.size() == 0)
        email = vet->getEmail();

    cout << "Alterar CRMV do veterinário: (para não alterar mantenha em branco)" << endl;
    getline(cin, CRMV);
    if (CRMV.size() == 0)
        CRMV = vet->getCRMV();

    this->excluirVeterinario(vet);
    delete vet;

    if(this->adicionarVeterinario(new Veterinario(nome, telefone, email, CRMV))) {
        cout << "Veterinário atualizado com sucesso" << endl;
    } else {
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    }
}

void Petshop::atualizarTratador() {
    string nomeFind, nome, telefone, email, uniforme;
    Uniforme un;
    Tratador* trt;

    // Encontrar funcionário
    cout << "Qual o nome do funcionário a ser alterado?: " << endl;
    cin.ignore();
    getline(cin, nome);
    trt = this->findTratador(nome);
    if (nome.size() == 0 || trt == nullptr)
        throw "Funcionário não encontrado!";

    cout << "Alterar nome do tratador: (para não alterar mantenha em branco)" << endl;
    getline(cin, nome);
    if (nome.size() == 0)
        nome = trt->getNome();

    cout << "Alterar telefone do tratador: (para não alterar mantenha em branco)" << endl;
    getline(cin, telefone);
    if (telefone.size() == 0)
        telefone = trt->getTelefone();

    cout << "Alterar e-mail pessoal do tratador: (para não alterar mantenha em branco)" << endl;
    getline(cin, email);
    if (email.size() == 0)
        email = trt->getEmail();

    cout << "Alterar nível de segurança: (para não alterar mantenha em branco)" << endl;
    cout << "V - Verde" << endl;
    cout << "A - Azul" << endl;
    cout << "M - verMelho" << endl;
    getline(cin, uniforme);
    bool alterou = true;
    if(uniforme == "V" || uniforme == "v") //toupper não cabe por necessariamente ser string, e não um char
        un = Verde;
    else if(uniforme == "A" || uniforme == "a")
        un = Azul;
    else if(uniforme == "M" || uniforme == "m")
        un = Vermelho;
    else
        trt->getUniforme();
    
    // Checa se o novo uniforme do tratador não entra em conflito com algum animal
    if(un != trt->getUniforme()) {
        for(auto& animal : this->animais) {
            if(animal->getTratador() == *trt) {
                string classe = animal->getClasse(animal);
                if(animal->getPerigoso() && un != Vermelho)
                    throw "O tratador possui animais que requerem segurança maior que a informada. Remova os animais de sua cautela e tente novamente.";
                else if((classe == "Réptil" || classe == "Mamífero") && (un == Verde))
                    throw "O tratador possui animais que requerem segurança maior que a informada. Remova os animais de sua cautela e tente novamente.";
            }
        }
    }

    this->excluirTratador(trt);
    delete trt;

    if(this->adicionarTratador(new Tratador(nome, telefone, email, un))) {
        cout << "Tratador atualizado com sucesso" << endl;
    } else {
        cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
    }
}

void Petshop::atualizarAnimal() {
    string nome, especie, pessoa;
    bool trocarHerancas;
    int idPessoa;

    // Configuração do texto acima dos campos de alteração
    string updateText = "Alterar: (para não alterar mantenha em branco)";

    cout << endl << "Nome do animal: " << endl;
    getline(cin, especie);
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
    if(classe.empty()) {
        trocarHerancas = true;
        classe = animal->getClasse(animal);
    }

    cout << endl << updateText;
    string categoria = animal->setClassificacao();
    if(categoria.empty()) {
        trocarHerancas = true;
        categoria = animal->getClassificacao(animal);
    }

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
    cout << "Digite o número do veterinário responsável: " << endl;
    getline(cin, pessoa);
    if(pessoa.size() == 0 && trocarHerancas)
        atualizar->setVeterinario(&animal->getVeterinario());
    else {
        idPessoa = stoi(pessoa);

        // Pela lista de vet. ser em petshop o tratamento se dá aqui, não no setter
        if(idPessoa >= 0 && idPessoa < this->veterinarios.size())
            atualizar->setVeterinario(this->veterinarios[idPessoa]);
        else if(trocarHerancas)
            atualizar->setVeterinario(&animal->getVeterinario());
    }

    cout << endl << updateText;
    if(!atualizar->setPerigoso() && trocarHerancas)
        atualizar->setPerigoso(animal->getPerigoso());

    // Classe
    if(classe == "ave" || classe == "Ave") { // Ave
        Ave* classe = dynamic_cast< Ave* >(atualizar);
        Ave* classeAnimal;

        if(trocarHerancas)
            classeAnimal = dynamic_cast< Ave* >(animal);

        cout << endl << updateText;
        if(!classe->setVoa() && trocarHerancas)
            classe->setVoa(classeAnimal->getVoa());

    } else if(classe == "mam" || classe == "Mamífero") { // Mamífero
        Mamifero* classe = dynamic_cast< Mamifero* >(atualizar);
        Mamifero* classeAnimal;

        if(trocarHerancas)
            classeAnimal = dynamic_cast< Mamifero* >(animal);
    
        cout << endl << updateText;
        if(!classe->setGestacao() && trocarHerancas)
            classe->setGestacao(classeAnimal->getGestacao());

    } else if(classe == "rep" || classe == "Réptil") { // Réptil
        Reptil* classe = dynamic_cast< Reptil* >(atualizar);
        Reptil* classeAnimal;

        if(trocarHerancas)
            classeAnimal = dynamic_cast< Reptil* >(animal);

        cout << endl << updateText;
        if(!classe->setPele() && trocarHerancas)
            classe->setPele(classeAnimal->getPele());

    } else if(classe == "anf" || classe == "Anfíbio") { // Anfíbio
        Anfibio* classe = dynamic_cast< Anfibio* >(atualizar);
        Anfibio* classeAnimal;

        if(trocarHerancas)
            classeAnimal = dynamic_cast< Anfibio* >(animal);

        cout << endl << updateText;
        if(!classe->setCauda() && trocarHerancas)
            classe->setCauda(classeAnimal->getCauda());

        cout << endl << updateText;
        if(!classe->setPata() && trocarHerancas)
            classe->setPata(classeAnimal->getPata());
    }

    // Tratador
    this->listarTratadores();
    cout << endl << updateText;
    cout << "Digite o número do tratador responsável: " << endl;
    getline(cin, pessoa);
    if(pessoa.size() == 0 && trocarHerancas)
        atualizar->setTratador(&animal->getTratador());
    else {
        idPessoa = stoi(pessoa);

        // Pela lista de trt. ser em petshop o tratamento se dá aqui, não no setter
        if(idPessoa >= 0 && idPessoa < this->tratadores.size())
            atualizar->setTratador(this->tratadores[idPessoa]);
        else if(trocarHerancas)
            atualizar->setTratador(&animal->getTratador());
    }

    // Classificação
    if(categoria == "N" || categoria == "Silvestre Nativo") { // Silvestre Nativo
        Nativo* categoria = dynamic_cast< Nativo* >(atualizar);
        Nativo* categoriaAnimal;

        if(trocarHerancas)
            categoriaAnimal = dynamic_cast< Nativo* >(animal);

        cout << endl << updateText;
        if(!categoria->setLicenca() && trocarHerancas)
            categoria->setLicenca(categoriaAnimal->getLicenca());
        
        cout << endl << updateText;
        if(!categoria->setRegiao() && trocarHerancas)
            categoria->setRegiao(categoriaAnimal->getRegiao());

    } else if(categoria == "E" || categoria == "Silvestre Exótico") { // Silvestre Exótico
        Exotico* categoria = dynamic_cast< Exotico* >(atualizar);
        Exotico* categoriaAnimal;

        if(trocarHerancas)
            categoriaAnimal = dynamic_cast< Exotico* >(animal);
    
        cout << endl << updateText;
        if(!categoria->setLocal() && trocarHerancas)
            categoria->setLocal(categoriaAnimal->getLocal());

    } else if(categoria == "D" || categoria == "Doméstico") { // Doméstico
        Domestico* categoria = dynamic_cast< Domestico* >(atualizar);
        Domestico* categoriaAnimal;

        if(trocarHerancas)
            categoriaAnimal = dynamic_cast< Domestico* >(animal);

        cout << endl << updateText;
        if(!categoria->setAdestrado() && trocarHerancas)
            categoria->setAdestrado(categoriaAnimal->getAdestrado());

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
    string nome;
    cout << "Nome do Vet.: ";
    getline(cin, nome);

    string opcao;
    Veterinario* vet = this->findVeterinario(nome);
    if(vet != nullptr) {
        cout << "Registro encontrado !" << endl;
        cout << *vet; //Usar método de listagem unica.
        cout << "Deseja realmente remove-lo dos registros ?" << endl;
        cout << endl << "\t Aperte \"S\" caso queira prosseguir ";
        cin >> opcao;

        if(opcao == "S" || opcao == "s") {
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
    getline(cin, nome);

    string opcao;
    Tratador* tratador = this->findTratador(nome);
    if(tratador != nullptr) {
        cout << "Registro encontrado !" << endl;
        cout << *tratador; //Usar método de listagem unica.
        cout << "Deseja realmente remove-lo dos registros ?" << endl;
        cout << endl << "\t Aperte \"S\" caso queira prosseguir ";
        cin >> opcao;

        if(opcao == "S" || opcao == "s") {
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
    getline(cin, nome);
    cout << "Especie do animal: ";
    getline(cin, especie);

    string opcao;
    Animal* animal = this->findAnimal(nome, especie);
    if(animal != nullptr) {
        cout << "Registro encontrado !" << endl;
        cout << *animal; //Usar método de listagem unica.
        cout << "Deseja realmente remove-lo dos registros ?" << endl;
        cout << endl << "\t Aperte \"S\" caso queira prosseguir ";
        cin >> opcao;

        if(opcao == "S" || opcao == "s") {
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

    string filtro;
    cin.ignore();
    getline(cin, filtro);

    if(filtro == "T" || filtro == "t") {
        if(this->tratadores.size() == 0)
            throw "Não há tratadores no sistema!";

        cout << "Digite o número do tratador responsável: " << endl;
        this->listarTratadores();
        int num;
        cin >> num;
        
        if(num >= 0 && num < this->tratadores.size())
            trt = *this->tratadores[num];
        else
            throw "Tratador não existe!";
    } else if(filtro == "V" || filtro == "v") {
        if(this->veterinarios.size() == 0)
            throw "Não há veterinários no sistema!";

        cout << "Digite o número do veterinário responsável: " << endl;
        this->listarVeterinarios();
        int num;
        cin >> num;
        
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