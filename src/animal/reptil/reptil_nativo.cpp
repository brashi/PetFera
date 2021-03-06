#include "reptil_nativo.hpp"

ReptilNativo::ReptilNativo(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, string regiao, string licenca, Pele pele):
                Reptil(nome, especie, ameacadoPor, veterinario, tratador, perigoso, pele),
                Nativo(regiao, licenca){}

ReptilNativo::~ReptilNativo(){}