#include "anfibio_nativo.hpp"

AnfibioNativo::AnfibioNativo(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, string licenca, bool cauda, bool pata):
                Nativo(nome, especie, ameacadoPor, veterinario, tratador, perigoso, regiao, licenca),
                Anfibio(cauda, pata){}

AnfibioNativo::~AnfibioNativo(){}