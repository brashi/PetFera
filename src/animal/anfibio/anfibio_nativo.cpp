#include "anfibio_nativo.hpp"

AnfibioNativo::AnfibioNativo(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, bool cauda, bool pata):
                Nativo(nome, especie, veterinario, tratador, perigoso, regiao),
                Anfibio(cauda, pata){}

AnfibioNativo::~AnfibioNativo(){}