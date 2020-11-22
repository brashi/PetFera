#include "reptil_exotico.hpp"

ReptilExotico::ReptilExotico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, Pele pele):
                Exotico(nome, especie, veterinario, tratador, perigoso, local),
                Reptil(pele){}

ReptilExotico::~ReptilExotico(){}

ostream& ReptilExotico::printOutDados(ostream& o) const {
    o << "Teste " << "Exótico" << endl;

    return o; 
}