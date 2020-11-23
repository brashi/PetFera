#pragma once

#include <string>
#include <iostream>

class Petshop {
    public:
        void criarVeterinario() const;
        void criarTratador() const;
        void criarAnimal() const;
        void getAnimais() const;
        void getAnimaisDeVeterinario() const;
        void getVeterinarios() const;
        void getTratadores() const;
        void atualizarVeterinario() const;
        void atualizarTratador() const;
        void atualizarAnimal() const;
        void excluirVeterinario() const;
        void excluirTratador() const;
        void excluirAnimal() const;
};