#pragma once

#include "tratador.hpp"
#include "veterinario.hpp"

#include <string>
#include <iostream>

using std::string;

class Animal {
    public:
        Animal() {};
        Animal(string nome, string especie, Veterinario veterinario,
            Tratador tratador, bool perigoso);
        virtual ~Animal();

        string getNome() const;
        string getEspecie() const;
        Veterinario getVeterinario() const;
        Tratador getTratador() const;
        bool getPerigoso() const;

        string getClassificacao(Animal* animal) const;
        string getClasse(Animal* animal) const;
        ostream& printOutDados(ostream& o, Animal* animal) const;

        bool operator==(const Animal& outro) const;
 
        friend ostream& operator<< (ostream& o, Animal& animal);
    protected:
        string nome;
        string especie;
        Veterinario veterinario;
        Tratador tratador;
        bool perigoso;
};