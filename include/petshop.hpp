#pragma once

#include "animal.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"

#include <vector>
#include <string>
#include <iostream>

using std::vector;

class Petshop {
    public:
        Petshop() {};
        ~Petshop();

        vector<Animal*> getAnimais() const;
        vector<Veterinario*> getVeterinarios() const;
        vector<Tratador*> getTratadores() const;

        bool criarVeterinario();
        bool criarTratador();
        bool criarAnimal();

        void atualizarVeterinario();
        void atualizarTratador();
        void atualizarAnimal();

        void excluirVeterinario();
        void excluirTratador();
        void excluirAnimal();
    
    private:
        vector<Veterinario*> veterinarios;
        vector<Tratador*> tratador;
        vector<Animal*> animais;
};