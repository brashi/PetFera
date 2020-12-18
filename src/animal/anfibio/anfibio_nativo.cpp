#include "anfibio_nativo.hpp"

AnfibioNativo::AnfibioNativo(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, string regiao, string licenca, bool cauda, bool pata):
                Anfibio(nome, especie, ameacadoPor, veterinario, tratador, perigoso, cauda, pata),
                Nativo(regiao, licenca){}

AnfibioNativo::~AnfibioNativo(){}