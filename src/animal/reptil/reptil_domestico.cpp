#include "reptil_domestico.hpp"

ReptilDomestico::ReptilDomestico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, Pele pele):
                Domestico(nome, especie, ameacadoPor, veterinario, tratador, perigoso, adestrado),
                Reptil(pele){}

ReptilDomestico::~ReptilDomestico(){}