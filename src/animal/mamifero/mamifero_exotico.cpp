#include "mamifero_exotico.hpp"

MamiferoExotico::MamiferoExotico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool gestacao):
                Exotico(nome, especie, veterinario, tratador, perigoso, local),
                Mamifero(gestacao){}

MamiferoExotico::~MamiferoExotico(){}

ostream& MamiferoExotico::printOutDados(ostream& o) const {
    o << "Teste " << "Exótico" << endl;

    return o; 
}