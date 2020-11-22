#include "reptil_nativo.hpp"

ReptilNativo::ReptilNativo(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, Pele pele):
                Nativo(nome, especie, veterinario, tratador, perigoso, regiao),
                Reptil(pele){}

ReptilNativo::~ReptilNativo(){}