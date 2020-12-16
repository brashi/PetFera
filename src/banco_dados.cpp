#include "banco_dados.hpp"

BancoDados::BancoDados(shared_ptr<Petshop> petshop):
                        petshop(petshop) {
                            diretorio = "dados/";
                            struct stat info;
                            if(stat(diretorio.c_str(), &info) != 0) {
                                mkdir(diretorio.c_str(), 0777);
                            }
                            funcArq = diretorio + "funcionarios.csv";
                            animalArq = diretorio + "animais.csv";
                            #ifdef DEBUG
                                diretorio = "include/dadosDebug/";
                                funcArq = diretorio + "funcionarios.csv";
                                animalArq = diretorio + "animais.csv";
                            #endif
                        }

void BancoDados::salvarDados() {
    #ifdef DEBUG
        cout << "Modo debug, portando nenhum arquivo será salvo." << endl;
        return;
    #endif
    try {
        salvarFuncionarios();
        salvarAnimais();
    } catch(char const* msg) {
        cout << "Erro: " << msg << endl;
    }
    
}

void BancoDados::salvarFuncionarios() {
    /*if(petshop->getTratadores().size() == 0 && petshop->getVeterinarios().size() == 0) {
        throw "Nenhum funcionário registrado. Geração de arquivo cancelada.";
    } */
    ofstream arqDados(funcArq);

    if(arqDados.bad() || arqDados.fail()) {
        throw "Algo deu errado na criação do arquivo de funcionários.";
    }

    for(auto& vet : petshop->getVeterinarios())
        arqDados << "vet;" << vet->getNome() << ';' << vet->getTelefone() << ';' << vet->getEmail() <<
        ';' << vet->getCRMV() << endl;

    for(auto& trt : petshop->getTratadores())
        arqDados << "trt;" << trt->getNome() << ';' << trt->getTelefone() << ';' << trt->getEmail()
            << ';' << trt->getUniforme() << endl;

    
    arqDados.close();
    cout << "Arquivo de funcionários salvo com sucesso." << endl;
}

void BancoDados::salvarAnimais() {
    /*if(petshop->getAnimais().size() == 0) {
        throw "Nenhum animal registrado. Geração de arquivo cancelada.";;
    }*/
    ofstream arqDados(animalArq);
    if(arqDados.bad() || arqDados.fail()) {
        throw "Algo deu errado na criação do arquivo de animais.";
    }

    string classe, classificao;

    for(auto& animal : petshop->getAnimais()) {
        classe = Animal::getClasse(animal, true);
        classificao = Animal::getClassificacao(animal, true);
        arqDados << classe << ';' << classificao << ';'
                 << animal->getNome() << ';' << animal->getEspecie() << ';'
                 << animal->getAmeacadoPor() << ';' << animal->getVeterinario().getNome() << ';'
                 << animal->getTratador().getNome() << ';'
                 << animal->getPerigoso() << ';';


        switch(strFiltro[classificao]) {
            case 'D':
                arqDados << dynamic_pointer_cast<Domestico>(animal)->getAdestrado() << ';';                
                break;
            case 'E':
                arqDados << dynamic_pointer_cast<Exotico>(animal)->getLocal() << ';';
                break;
            case 'N':
                arqDados << dynamic_pointer_cast<Nativo>(animal)->getRegiao() << ';'
                         << dynamic_pointer_cast<Nativo>(animal)->getLicenca() << ';';
                break;
        }

        switch(strFiltro[classe]) {
            case 'A':
                arqDados << dynamic_pointer_cast<Ave>(animal)->getVoa() << endl;
                break;
            case 'F':
                arqDados << dynamic_pointer_cast<Anfibio>(animal)->getCauda() << ';'
                         << dynamic_pointer_cast<Anfibio>(animal)->getPata() << endl;
                break;
            case 'R':
                arqDados << dynamic_pointer_cast<Reptil>(animal)->getPele() << endl;
                break;
            case 'M':
                arqDados << dynamic_pointer_cast<Mamifero>(animal)->getGestacao() << endl;
                break;
        }


    }

    arqDados.close();
    cout << "Arquivo de animais salvo com sucesso." << endl;
}

void BancoDados::lerDados() {
    try {
        lerFuncionarios();
        lerAnimais();
    } catch(char const* msg) {
        cout << "Erro: " << msg << endl << "Caso os arquivos existam,"
         << endl << "Verifique a integridade deles na pasta " << diretorio << endl;
    }
}

void BancoDados::lerFuncionarios() {
    ifstream arqDados(funcArq);
    if(arqDados.bad() || arqDados.fail()){
        throw "Arquivo de funcionarios inexistente ou corrompido.";
    }
    int count = 0;
    string temp;
    string linha;
    string palavra;
    vector<string> tokens;

    while(!arqDados.eof()) {
        tokens.clear();

        getline(arqDados, linha);
        stringstream s(linha);
        while(getline(s, palavra, ';')) {
            tokens.push_back(palavra);
        }

        if(tokens.size()) {
            if(tokens.at(0) == "vet") {
                petshop->adicionarVeterinario(make_shared<Veterinario>(
                    tokens.at(1),
                    tokens.at(2),
                    tokens.at(3),
                    tokens.at(4))
                );
            }
            if(tokens.at(0) == "trt") {
                petshop->adicionarTratador(make_shared<Tratador>(
                    tokens.at(1),
                    tokens.at(2),
                    tokens.at(3),
                    static_cast<Uniforme>(stoi(tokens.at(4)))
                ));
            }
            count++;
        }
    }

    arqDados.close();
    cout << "Arquivo de funcionários carregado com sucesso." << endl;
    cout << "Foram carregados " << count << " funcionários." << endl;
}

void BancoDados::lerAnimais() {
    ifstream arqDados(animalArq);
    if(arqDados.bad() || arqDados.fail()){
        throw "Arquivo de animais inexistente ou corrompido.";
    }
    int count = 0;
    int prox;

    string temp;
    string linha;
    string palavra;
    string classe, classificacao;
    vector<string> tokens;
    shared_ptr<Animal> animal;

    while(!arqDados.eof()) {
        tokens.clear();

        getline(arqDados, linha);
        stringstream s(linha);
        while(getline(s, palavra, ';')) {
            tokens.push_back(palavra);
        }

        if(tokens.size()) {
            classe = tokens.at(0);
            classificacao = tokens.at(1);

            animal = mapa.aMap[classe + classificacao]();
            animal->setNome(tokens.at(2));
            animal->setEspecie(tokens.at(3));
            animal->setAmeacadoPor(tokens.at(4));
            animal->setVeterinario(*petshop->findVeterinario(tokens.at(5)));
            animal->setTratador(*petshop->findTratador(tokens.at(6)));
            animal->setPerigoso(stoi(tokens.at(7)));

            switch(strFiltro[classificacao]) {
                case 'D':
                    dynamic_pointer_cast<Domestico>(animal)->setAdestrado(stoi(tokens.at(8)));
                    prox = 9;
                    break;
                case 'E':
                    dynamic_pointer_cast<Exotico>(animal)->setLocal(tokens.at(8));
                    prox = 9;
                    break;
                case 'N':
                    dynamic_pointer_cast<Nativo>(animal)->setRegiao(tokens.at(8));
                    dynamic_pointer_cast<Nativo>(animal)->setLicenca(tokens.at(9));
                    prox = 10;
                    break;
            }
            
            switch(strFiltro[classe]) {
                case 'A':
                    dynamic_pointer_cast<Ave>(animal)->setVoa(stoi(tokens.at(prox)));
                    break;
                case 'F':
                    dynamic_pointer_cast<Anfibio>(animal)->setCauda(stoi(tokens.at(prox)));
                    dynamic_pointer_cast<Anfibio>(animal)->setPata(stoi(tokens.at(prox + 1)));
                    break;
                case 'R':
                    dynamic_pointer_cast<Reptil>(animal)->setPele(static_cast<Pele>(stoi(tokens.at(prox))));
                    break;
                case 'M':
                    dynamic_pointer_cast<Mamifero>(animal)->setGestacao(stoi(tokens.at(prox)));
            }

            petshop->adicionarAnimal(animal);
            count++;
        }


    }
    arqDados.close();
    cout << "Arquivo de animais carregado com sucesso." << endl;
    cout << "Foram carregados " << count << " animais." << endl;
}