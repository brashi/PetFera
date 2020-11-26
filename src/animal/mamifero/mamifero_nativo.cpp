#include "mamifero_nativo.hpp"

MamiferoNativo::MamiferoNativo(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, string licenca, bool gestacao):
                Nativo(nome, especie, ameacadoPor, veterinario, tratador, perigoso, regiao, licenca),
                Mamifero(gestacao){}

MamiferoNativo::~MamiferoNativo(){}