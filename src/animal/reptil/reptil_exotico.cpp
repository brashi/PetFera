#include "reptil_exotico.hpp"

ReptilExotico::ReptilExotico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, Pele pele):
                Reptil(nome, especie, ameacadoPor, veterinario, tratador, perigoso, pele),
                Exotico(local){}

ReptilExotico::~ReptilExotico(){}