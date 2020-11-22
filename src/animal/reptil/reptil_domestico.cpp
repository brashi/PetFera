#include "reptil_domestico.hpp"

ReptilDomestico::ReptilDomestico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, Pele pele):
                Domestico(nome, especie, veterinario, tratador, perigoso, adestrado),
                Reptil(pele){}

ReptilDomestico::~ReptilDomestico(){}