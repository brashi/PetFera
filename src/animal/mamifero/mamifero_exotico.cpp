#include "mamifero_exotico.hpp"

MamiferoExotico::MamiferoExotico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool gestacao):
                Exotico(nome, especie, ameacadoPor, veterinario, tratador, perigoso, local),
                Mamifero(gestacao){}

MamiferoExotico::~MamiferoExotico(){}