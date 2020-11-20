#pragma once

#include <string>
#include <iostream>

using namespace std;

class Animal {
    public:
        Animal();
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