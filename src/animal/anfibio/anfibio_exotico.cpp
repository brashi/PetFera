#include "anfibio_exotico.hpp"

AnfibioExotico::AnfibioExotico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool cauda, bool pata):
                Exotico(nome, especie, veterinario, tratador, perigoso, local),
                Anfibio(cauda, pata){}

AnfibioExotico::~AnfibioExotico(){}