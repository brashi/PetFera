#pragma once

#include "../funcionarios/tratador.hpp"
#include "../funcionarios/veterinario.hpp"

#include <string>
#include <iostream>

using std::string;

class Animal {
    public:
        Animal(string nome, string especie, Veterinario veterinario, Tratador tratador, bool perigoso);
        virtual ~Animal();

        string getNome() const;
        string getEspecie() const;
        Veterinario getVeterinario() const;
        Tratador getTratador() const;
        bool getPerigoso() const;

    protected:
        string nome;
        string especie;
        Veterinario veterinario;
        Tratador tratador;
        bool perigoso;
};