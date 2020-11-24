#include "mamifero_nativo.hpp"

MamiferoNativo::MamiferoNativo(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, string gestacao):
                Nativo(nome, especie, veterinario, tratador, perigoso, regiao),
                Mamifero(gestacao){}

MamiferoNativo::~MamiferoNativo(){}