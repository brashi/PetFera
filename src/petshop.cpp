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

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
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

    try {
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
        
    } catch(char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } catch(...) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
    }
}

void Petshop::criarTratador() {
    string nome, telefone, email, uniforme;
    Uniforme un;

    try {
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

    } catch(char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } catch(...) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
    }
}

void Petshop::criarAnimal() {
    string nome, especie, regiao, local, classe, categoria;
    Veterinario vet;
    Tratador trata;
    bool perigo = false, voa = false, cauda = false, pata = false, gestacao = false, adestrado = false;
    char opcao;
    Pele pele;
    
    try {
        if(this->veterinarios.size() < 1)
            throw "Não há veterinários no sistema!"; 

        if(this->tratadores.size() < 1)
            throw "Não há tratadores no sistema!"; 

        cout << "Nome do animal: " << endl;
        cin.ignore();
        getline(cin, nome);
        if (nome.size() == 0)
            throw "Animal sem nome!";
        cout << endl << "Espécie: " << endl;
        getline(cin, especie);
        if (especie.size() == 0)
            throw "Animal sem espécie!";
        cout << endl << "Digite o número do veterinário responsável: " << endl;
        this->listarVeterinarios();
        int num;
        cin >> num;
        
        if(num >= 0 && num < this->veterinarios.size())
            vet = *this->veterinarios[num];
        else
            throw "Veterinário não existe!";
        cout << endl << "É perigoso ? \t S/N : ";
        cin >> opcao;
        if(toupper(opcao) == 'S')
            perigo = true;
        else
            perigo = false;
        cout << endl << "O animal pertence a que classe?..." << endl;
        cout << "A - ave" << endl;
        cout << "F - anfíbio" << endl;
        cout << "R - réptil" << endl;
        cout << "M - mamífero" << endl;
        cin >> opcao;

        switch(toupper(opcao)) {
            case 'A': 
                classe = "ave";
                break;
            case 'F':
                classe = "anf";
                break;
            case 'R':
                classe = "rep";
                break;
            case 'M':
                classe = "mam";
                break;
            default:
                throw "Animal deve ter uma classe!";
                break;
        }
        cout << endl;
        if(classe == "ave") {
            cout << "Voa? \t S/N : " << endl;
            cin >> opcao;
            if(toupper(opcao) == 'S')
                voa = true;
            else
                voa = false;
        }
        else if(classe == "anf") {
            cout << "Possui cauda? \t S/N : " << endl;
            cin >> opcao;
            if(toupper(opcao) == 'S')
                cauda = true;
            else
                cauda = false;

            cout << "Possui pata? \t S/N : " << endl;
            cin >> opcao;
            if(toupper(opcao) == 'S')
                pata = true;
            else
                pata = false;
        }
        else if(classe == "rep") {
            cout << "Qual o tipo de pele? " << endl;
            cout << "C - carapaça" << endl;
            cout << "E - escama" << endl;
            cout << "P - placa" << endl;
            cin >> opcao;
            if(toupper(opcao) == 'C')
                pele = Carapaca;
            else if(toupper(opcao) == 'E')
                pele = Escama;
            else if(toupper(opcao) == 'P')
                pele = Placa;
            else
                throw "Réptil precisa de pele";
        }
        else {
            cout << "Possui gestação? \t S/N : " << endl;
            cin >> opcao;
            if(toupper(opcao) == 'S')
                gestacao = true;
            else
                gestacao = false;
        }
        cout << endl << "A que categoria o animal pertence?..." << endl;
        cout << "D - doméstico" << endl;
        cout << "E - exótico" << endl;
        cout << "N - nativo" << endl;
        cin >> opcao;

        switch(toupper(opcao)) {
            case 'D': 
                categoria = "D";
                break;
            case 'E' : 
                categoria = "E";
                break;
            case 'N' : 
                categoria = "N";
                break;
            default:
                throw "Animal deve ter uma categoria!";
                break;
        }
        cout << endl;
        if(categoria == "D") {
            cout << "É adestrado? \t S/N : " << endl;
            cin >> opcao;
            if(toupper(opcao) == 'S')
                adestrado = true;
            else
                adestrado = false;
        }
        else if(categoria == "E") {
            cout << "Habitat local: " << endl;
            cin.ignore();
            getline(cin, local);
            if (local.size() == 0)
                throw "Animal sem habitat!";
        }
        else {
            cout << "Região do animal: " << endl;
            cin.ignore();
            getline(cin, regiao);
            if (regiao.size() == 0)
                throw "Animal sem região!";
        }
        cout << endl << "Digite o número do tratador responsável: " << endl;
        this->listarTratadores();
        num;
        cin >> num;

        if(num >= 0 && num < this->tratadores.size()) {
            trata = *this->tratadores[num];
            Uniforme un = trata.getUniforme();

            if(perigo && un != Vermelho)
                throw "Erro de permissão! O tratador necessita de ao menos um nível de segurança Vermelho.";
            else if((classe == "rep" || classe == "mam") && (un == Verde))
                throw "Erro de permissão! O tratador necessita de ao menos um nível de segurança Azul.";
        } else
            throw "Tratador não existe!"; 

        cout << endl;
        
        DadosAnimal dadosNovoAnimal = (DadosAnimal) {
            .nome = nome,
            .especie = especie,
            .veterinario = vet,
            .tratador = trata,
            .perigoso = perigo,
            .regiao = regiao,
            .local = local,
            .adestrado = adestrado,
            .voa = voa,
            .cauda = cauda,
            .pata = pata,
            .gestacao = gestacao,
            .pele = pele,
        };

        string animalControle = classe + categoria;
        
        if(this->adicionarAnimal(mapa.aMap[animalControle](dadosNovoAnimal))) {
            cout << "Animal adicionado ao cadastro." << endl;
        } else {
            cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
        }
    }
    catch (char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } 
    catch(...) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente" << endl;
    }
}

// Atualização
void Petshop::atualizarVeterinario() {
    Veterinario* vet;
    string nomeFind, nome, telefone, email, CRMV;

    try {
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

    } catch(char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } catch(...) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
    }
}

void Petshop::atualizarTratador() {
    string nomeFind, nome, telefone, email, uniforme;
    Uniforme un;
    Tratador* trt;

    try {
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

    } catch(char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } catch(...) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
    }
}

void Petshop::atualizarAnimal() {
    bool perigoso = false, voa = false, cauda = false, pata = false, gestacao = false, adestrado = false;
    string nome, especie, perigo, veterinario, tratador, categoria, classe, regiao, local;
    Pele pele = Escama;
    Veterinario vet;
    Tratador trt;

    try {
        cout << "Qual o nome do animal ?" << endl;
        cin.ignore();
        getline(cin, nome);
        if (nome.size() == 0)
            throw "Não é possível pesquisar animal sem nome!";

        cout << "E sua espécie?" << endl;
        getline(cin, especie);
        if (especie.size() == 0)
            throw "Não é possível pesquisar animal sem espécie!";

        Animal* atualizar = findAnimal(nome, especie);
        if(atualizar != nullptr) {
            cout << "Animal encontrado!" << endl;

            cout << "Alterar nome: (para não alterar mantenha em branco)" << endl;
            getline(cin, nome);
            if (nome.size() == 0)
                nome = atualizar->getNome();
            
            cout << "Alterar especie: (para não alterar mantenha em branco)" << endl;
            getline(cin, especie);
            if (especie.size() == 0)
                especie = atualizar->getEspecie();

            cout << "Alterar periculosidade para S/N: (para não alterar mantenha em branco)" << endl;
            getline(cin, perigo);
            if (perigo.size() == 0)
                perigoso = atualizar->getPerigoso();
            else if(perigo == "S" || perigo == "s") //toupper não cabe por necessariamente ser string, e não um char
                perigoso = true;
            else
                perigoso = false;

            //Alterar classe
            cout << "Alterar classe: (para não alterar mantenha em branco)" << endl;
            cout << "A - ave" << endl;
            cout << "F - anfíbio" << endl;
            cout << "R - réptil" << endl;
            cout << "M - mamífero" << endl;
            getline(cin, classe);
            if(classe == "A" || classe == "a") //toupper não cabe por classe necessariamente ser string, e não um char
                classe = "ave";
            else if(classe == "F" || classe == "f")
                classe = "anf";
            else if(classe == "R" || classe == "r")
                classe = "rep";
            else if(classe == "M" || classe == "m")
                classe = "mam";
            else {
                try {
                    string aux = atualizar->getClasse(atualizar);
                    if(aux == "Mamífero")
                        classe = "mam";
                    else if (aux == "Ave")
                        classe = "ave";
                    else if (aux == "Anfíbio")
                        classe = "anf";
                    else
                        classe = "rep";
                }
                catch(...) {
                    throw "Falha ao pegar a Classe, verifique se cadastrou o animal em questão corretamente.";
                }
            }

            string verificarClasse;
            //Alterar coisas específicas de cada classe:
            if(classe == "ave") {
                Ave* teste = dynamic_cast< Ave* >(atualizar);
                cout << "Alterar status \"voa?\" S/N: (para não alterar mantenha em branco)" << endl;
                
                getline(cin, verificarClasse);
                if (verificarClasse.size() == 0)
                    voa = teste->getVoa();
                else if(verificarClasse == "S" || verificarClasse == "s") //toupper não cabe por necessariamente ser string, e não um char
                    voa = true;
                else
                    voa = false;

            } else if(classe == "anf") {
                Anfibio* teste = dynamic_cast< Anfibio* >(atualizar);
                cout << "Alterar status \"possui cauda?\" S/N: (para não alterar mantenha em branco)" << endl;
                getline(cin, verificarClasse);
                if (verificarClasse.size() == 0)
                    cauda = teste->getCauda();
                else if(verificarClasse == "S" || verificarClasse == "s") //toupper não cabe por necessariamente ser string, e não um char
                    cauda = true;
                else
                    cauda = false;
                
                verificarClasse = "";
                cout << "Alterar status \"possui pata?\" S/N: (para não alterar mantenha em branco)" << endl;
                getline(cin, verificarClasse);
                if (verificarClasse.size() == 0)
                    pata = teste->getPata();
                else if(verificarClasse == "S" || verificarClasse == "s") //toupper não cabe por necessariamente ser string, e não um char
                    pata = true;
                else
                    pata = false;

            } else if(classe == "rep") {
                Reptil* teste = dynamic_cast< Reptil* >(atualizar);
                cout << "Alterar status \"pele?\" S/N: (para não alterar mantenha em branco)" << endl;
                cout << "C - carapaça" << endl;
                cout << "E - escama" << endl;
                cout << "P - placa" << endl;
                getline(cin, verificarClasse);
                if(verificarClasse == "C" || verificarClasse == "c") //toupper não cabe por necessariamente ser string, e não um char
                    pele = Carapaca;
                else if(verificarClasse == "E" || verificarClasse == "e")
                    pele = Escama;
                else if(verificarClasse == "P" || verificarClasse == "p")
                    pele = Placa;
                else
                    pele = teste->getPele();

            } else {
                Mamifero* teste = dynamic_cast< Mamifero* >(atualizar);
                cout << "Alterar status \"possui gestação?\" S/N: (para não alterar mantenha em branco)" << endl;
                getline(cin, verificarClasse);
                if (verificarClasse.size() == 0)
                    gestacao = teste->getGestacao();
                else if(verificarClasse == "S" || verificarClasse == "s") //toupper não cabe por necessariamente ser string, e não um char
                    gestacao = true;
                else
                    gestacao = false;
            }

            //Alterar categoria
            cout << "Alterar categoria: (para não alterar mantenha em branco)" << endl;
            cout << "D - doméstico" << endl;
            cout << "E - exótico" << endl;
            cout << "N - nativo" << endl;
            getline(cin, categoria);

            if(categoria == "D" || categoria == "d") //validação, toupper não cabe por categoria necessariamente ser string, e não um char
                categoria = "D";
            else if (categoria == "E" || categoria == "e")
                categoria = "E";
            else if (categoria == "N" || categoria == "n")
                categoria = "N";
            else {
                try {
                    string aux = atualizar->getClassificacao(atualizar);
                    if(aux == "Silvestre Nativo")
                        categoria = "N";
                    else if (aux == "Silvestre Exótico")
                        categoria = "E";
                    else
                        categoria = "D";
                }
                catch(...) {
                    throw "Falha ao pegar a Classificação, verifique se cadastrou o animal em questão corretamente.";
                }
            }

            //Alterar coisas específicas de cada categoria:
            string verificarCategoria;
            if(categoria == "D") {
                Domestico* teste = dynamic_cast< Domestico* >(atualizar);
                cout << "Alterar status \"adestrado?\" S/N: (para não alterar mantenha em branco)" << endl;
                getline(cin, verificarCategoria);
                if (verificarCategoria.size() == 0)
                    adestrado = teste->getAdestrado();
                else if(verificarCategoria == "S" || verificarCategoria == "s") //toupper não cabe por necessariamente ser string, e não um char
                    adestrado = true;
                else
                    adestrado = false;
            } else if(categoria == "E") {
                Exotico* teste = dynamic_cast< Exotico* >(atualizar);
                cout << "Alterar habitat local: (para não alterar mantenha em branco)" << endl;
                getline(cin, verificarCategoria);
                if (verificarCategoria.size() == 0)
                    local = teste->getLocal();
            } else {
                Nativo* teste = dynamic_cast< Nativo* >(atualizar);
                cout << "Alterar região na qual habita: (para não alterar mantenha em branco)" << endl;
                getline(cin, verificarCategoria);
                if (verificarCategoria.size() == 0)
                    regiao = teste->getRegiao();
            }

            //Alterar veterinário ou tratador:
            cout << "Alterar veterinário S/N: (para não alterar mantenha em branco)" << endl;
            getline(cin, veterinario);
            if (veterinario.size() == 0)
                vet = atualizar->getVeterinario();
            else if(veterinario != "N" && veterinario != "n")
            {
                cout << "Digite o número do veterinario responsável: " << endl;
                this->listarVeterinarios();
                cout << endl;
                int num;
                cin >> num;

                try {
                    vet = *this->veterinarios[num];
                }
                catch(...) {
                    cout << "Não pudemos trocar o veterinário, cheque se o mesmo existe e tente novamente mais tarde." << endl;
                    vet = atualizar->getVeterinario();
                }
            }
            
            cout << "Alterar tratador S/N: (para não alterar mantenha em branco)" << endl;
            getline(cin, tratador);
            if (tratador.size() == 0)
                trt = atualizar->getTratador();
            else if(tratador != "N" && tratador != "n")
            {
                cout << "Digite o número do tratador responsável: " << endl;
                this->listarTratadores();
                cout << endl;
                int num;
                cin >> num;

                try {
                    trt = *this->tratadores[num];
                    Uniforme un = trt.getUniforme();

                    if(perigoso && un != Vermelho)
                        throw "Erro de permissão!";
                    else if((classe == "rep" || classe == "mam") && (un == Verde))
                        throw "Erro de permissão!";
                } catch(...) {
                    cout << "Não pudemos trocar o tratador, cheque se o mesmo existe ou possui a permissão necessária e tente novamente mais tarde." << endl;
                    trt = atualizar->getTratador();
                }
            }
            
            this->excluirAnimal(atualizar);
            delete atualizar;

            DadosAnimal dadosNovoAnimal = (DadosAnimal) {
                .nome = nome,
                .especie = especie,
                .veterinario = vet,
                .tratador = trt,
                .perigoso = perigoso,
                .regiao = regiao,
                .local = local,
                .adestrado = adestrado,
                .voa = voa,
                .cauda = cauda,
                .pata = pata,
                .gestacao = gestacao,
                .pele = pele,
            };

            string animalControle = classe + categoria;
            
            if(this->adicionarAnimal(mapa.aMap[animalControle](dadosNovoAnimal))) {
                cout << "Animal atualizado com sucesso" << endl;
            } else {
                cout << "Houve um erro na operação" << endl << "Cancelando..." << endl;
            }
        } else {
            cout << "O animal não se apresenta nos registros" << endl;
        }
    }
    catch (char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } 
    catch(std::exception& ex) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
    }
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

    try {
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

        cout << right
        << setfill(' ') << setw(19) << "Nome"
        << setfill(' ') << setw(19) << "Espécie"
        << setfill(' ') << setw(19) << "Veterinário"
        << setfill(' ') << setw(19) << "Tratador"
        << setfill(' ') << setw(19) << "Perigoso"
        << setfill(' ') << setw(19) << "Classificação"
        << setfill(' ') << setw(19) << "Classe"
        << endl;

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

    } catch(char const* msg) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        cout << "Erro: " << msg << endl;
    } catch(...) {
        cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
    }
}