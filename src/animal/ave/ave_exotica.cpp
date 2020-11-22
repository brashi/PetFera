#include "ave_exotica.hpp"

AveExotica::AveExotica(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool voa):
                Exotico(nome, especie, veterinario, tratador, perigoso, local),
                Ave(voa){}

AveExotica::~AveExotica(){}

ostream& AveExotica::printOutDados(ostream& o) const {
    o << "Teste " << "Exótica" << endl;

    return o; 
}