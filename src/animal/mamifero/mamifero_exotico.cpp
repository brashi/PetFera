#include "mamifero_exotico.hpp"

MamiferoExotico::MamiferoExotico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool gestacao):
                Mamifero(nome, especie, ameacadoPor, veterinario, tratador, perigoso, gestacao),
                Exotico(local){}

MamiferoExotico::~MamiferoExotico(){}