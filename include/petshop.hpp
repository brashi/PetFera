#pragma once

#include "animal.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include "mapeador.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <functional>

#include "ave_domestica.hpp"

using std::vector;

class Petshop {
    public:
        Petshop();
        ~Petshop();

        vector<Animal*> getAnimais() const;
        vector<Veterinario*> getVeterinarios() const;
        vector<Tratador*> getTratadores() const;
        void listarAnimais();

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