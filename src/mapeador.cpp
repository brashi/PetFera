#include "mapeador.hpp"

using std::cout;
using std::cin;

MapeadorMenu::MapeadorMenu() {
    escolhas['A'] = []() {
        cout << "TESTE 1" << endl;
        return true;
    };
    escolhas['B'] = []() {
        cout << "TESTE 2" << endl;
        return true;
    };
    escolhas['X'] = []() {
        cout << "Saindo do programa..." << endl;
        return false;
    };
}

MapeadorAnimal::MapeadorAnimal() {
    sMap["aveD"] = [](DadosAnimal dados) { 
        return new AveDomestica(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.voa); 
        };

    sMap["aveN"] = [](DadosAnimal dados) { 
        return new AveNativa(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.voa); 
        };

    sMap["aveE"] = [](DadosAnimal dados) { 
        return new AveExotica(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.voa); 
        };

    

    sMap["anfD"] = [](DadosAnimal dados) { 
        return new AnfibioDomestico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.cauda, dados.pata); 
        };

    sMap["anfN"] = [](DadosAnimal dados) { 
        return new AnfibioNativo(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.cauda, dados.pata); 
        };

    sMap["anfE"] = [](DadosAnimal dados) { 
        return new AnfibioExotico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.cauda, dados.pata); 
        };


    
    sMap["repD"] = [](DadosAnimal dados) { 
        return new ReptilDomestico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.pele); 
        };

    sMap["repN"] = [](DadosAnimal dados) { 
        return new ReptilNativo(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.pele); 
        };

    sMap["repE"] = [](DadosAnimal dados) { 
        return new ReptilExotico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.pele); 
        };

    

    sMap["mamD"] = [](DadosAnimal dados) { 
        return new MamiferoDomestico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.gestacao); 
        };

    sMap["mamN"] = [](DadosAnimal dados) { 
        return new MamiferoNativo(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.gestacao); 
        };

    sMap["mamE"] = [](DadosAnimal dados) { 
        return new MamiferoExotico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.gestacao); 
        };
}