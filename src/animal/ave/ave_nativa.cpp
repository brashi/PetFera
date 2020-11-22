#include "ave_nativa.hpp"

AveNativa::AveNativa(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, bool voa):
                Nativo(nome, especie, veterinario, tratador, perigoso, regiao),
                Ave(voa){}

AveNativa::~AveNativa(){}

ostream& AveNativa::printOutDados(ostream& o) const {
    o << "Teste " << "Nativa" << endl;

    return o; 
}