#include "mamifero_nativo.hpp"

MamiferoNativo::MamiferoNativo(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, string regiao, string licenca, bool gestacao):
                Mamifero(nome, especie, ameacadoPor, veterinario, tratador, perigoso, gestacao),
                Nativo(regiao, licenca){}

MamiferoNativo::~MamiferoNativo(){}