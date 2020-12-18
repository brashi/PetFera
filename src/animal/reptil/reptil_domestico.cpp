#include "reptil_domestico.hpp"

ReptilDomestico::ReptilDomestico(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, bool adestrado, Pele pele):
                Reptil(nome, especie, ameacadoPor, veterinario, tratador, perigoso, pele),
                Domestico(adestrado){}

ReptilDomestico::~ReptilDomestico(){}