#include "mamifero_domestico.hpp"

MamiferoDomestico::MamiferoDomestico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool gestacao):
                Domestico(nome, especie, veterinario, tratador, perigoso, adestrado),
                Mamifero(gestacao){}

MamiferoDomestico::~MamiferoDomestico(){}

ostream& MamiferoDomestico::printOutDados(ostream& o) const {
    o << "Teste " << "Doméstico" << endl;

    return o; 
}