#pragma once

#include "tratador.hpp"
#include "veterinario.hpp"

#include <string>
#include <iostream>

using std::string;

class Animal {
    public:
        Animal(string nome, string especie, Veterinario veterinario,
            Tratador tratador, bool perigoso);
        virtual ~Animal();

        string getNome() const;
        string getEspecie() const;
        Veterinario getVeterinario() const;
        Tratador getTratador() const;
        bool getPerigoso() const;

        virtual ostream& printOutDados(ostream& o) const = 0;
 
        friend ostream& operator<< (ostream& o, Animal& animal);
    protected:
        string nome;
        string especie;
        Veterinario veterinario;
        Tratador tratador;
        bool perigoso;
};