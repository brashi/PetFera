#include "ave_domestica.hpp"

AveDomestica::AveDomestica(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool voa):
                Domestico(nome, especie, veterinario, tratador, perigoso, adestrado),
                Ave(voa){}

AveDomestica::~AveDomestica(){}

ostream& AveDomestica::printOutDados(ostream& o) const {
    o << "Teste " << "Domestico" << endl;

    return o; 
}