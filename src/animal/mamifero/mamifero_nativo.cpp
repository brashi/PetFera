#include "mamifero_nativo.hpp"

MamiferoNativo::MamiferoNativo(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, bool voa):
                Nativo(nome, especie, veterinario, tratador, perigoso, regiao),
                Mamifero(voa){}

MamiferoNativo::~MamiferoNativo(){}

ostream& MamiferoNativo::printOutDados(ostream& o) const {
    o << "Teste " << "Nativo" << endl;

    return o; 
}