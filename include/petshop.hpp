#pragma once

#include "animal.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include "mapeador_animal.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <functional>

using std::vector;

class Petshop {
    public:
        Petshop();
        ~Petshop();
        
        void listarAnimais();
        void listarTratadores();
        void listarVeterinarios();

        void criarVeterinario();
        void criarTratador();
        void criarAnimal();

        bool adicionarVeterinario(Veterinario* vetAdd);
        bool adicionarTratador(Tratador* tratAdd);
        bool adicionarAnimal(Animal* animalAdd);

        void atualizarVeterinario();
        void atualizarTratador();
        void atualizarAnimal();

        void excluirVeterinario();
        void excluirTratador();
        void excluirAnimal();

        Veterinario* excluirVeterinario(Veterinario* removido);
        Tratador* excluirTratador(Tratador* removido);
        Animal* excluirAnimal(Animal* removido);
    
    private:
        Veterinario* findVeterinario(string nome);
        Tratador* findTratador(string nome);
        Animal* findAnimal(string nome, string especie);

        vector<Veterinario*> veterinarios;
        vector<Tratador*> tratadores;
        vector<Animal*> animais;

        MapeadorAnimal mapa;
};