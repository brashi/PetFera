#include "anfibio_domestico.hpp"

AnfibioDomestico::AnfibioDomestico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool cauda, bool pata):
                Domestico(nome, especie, veterinario, tratador, perigoso, adestrado),
                Anfibio(cauda, pata){}

AnfibioDomestico::~AnfibioDomestico(){}

ostream& AnfibioDomestico::printOutDados(ostream& o) const {
    o << "Teste " << "Doméstico" << endl;

    return o; 
}