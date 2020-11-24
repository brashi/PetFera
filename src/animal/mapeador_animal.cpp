#include "mapeador_animal.hpp"


FiltroAnimal::FiltroAnimal() {
    filtro['A'] = [](Animal* animal) {
        Ave* checar = dynamic_cast<Ave*>(animal);
        return dynamic_cast<Animal*>(checar);
    };

    filtro['F'] = [](Animal* animal) {
        Anfibio* checar = dynamic_cast<Anfibio*>(animal);
        return dynamic_cast<Animal*>(checar);
    };

    filtro['R'] = [](Animal* animal) {
        Reptil* checar = dynamic_cast<Reptil*>(animal);
        return dynamic_cast<Animal*>(checar);
    };

    filtro['M'] = [](Animal* animal) {
        Mamifero* checar = dynamic_cast<Mamifero*>(animal);
        return dynamic_cast<Animal*>(checar);
    };

    filtro['T'] = [](Animal* animal) {
        //Mamifero* checar = dynamic_cast<Mamifero*>(animal);
        return animal;
    };
}


MapeadorAnimal::MapeadorAnimal() {
    aMap["aveD"] = [](DadosAnimal dados) { 
        return new AveDomestica(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.voa); 
        };

    aMap["aveN"] = [](DadosAnimal dados) { 
        return new AveNativa(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.voa); 
        };

    aMap["aveE"] = [](DadosAnimal dados) { 
        return new AveExotica(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.voa); 
        };


    aMap["anfD"] = [](DadosAnimal dados) { 
        return new AnfibioDomestico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.cauda, dados.pata); 
        };

    aMap["anfN"] = [](DadosAnimal dados) { 
        return new AnfibioNativo(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.cauda, dados.pata); 
        };

    aMap["anfE"] = [](DadosAnimal dados) { 
        return new AnfibioExotico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.cauda, dados.pata); 
        };

    
    aMap["repD"] = [](DadosAnimal dados) { 
        return new ReptilDomestico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.pele); 
        };

    aMap["repN"] = [](DadosAnimal dados) { 
        return new ReptilNativo(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.pele); 
        };

    aMap["repE"] = [](DadosAnimal dados) { 
        return new ReptilExotico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.pele); 
        };


    aMap["mamD"] = [](DadosAnimal dados) { 
        return new MamiferoDomestico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.adestrado, dados.gestacao); 
        };

    aMap["mamN"] = [](DadosAnimal dados) { 
        return new MamiferoNativo(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.regiao, dados.gestacao); 
        };

    aMap["mamE"] = [](DadosAnimal dados) { 
        return new MamiferoExotico(dados.nome, dados.especie, dados.veterinario, dados.tratador,
                    dados.perigoso, dados.local, dados.gestacao); 
        };
}