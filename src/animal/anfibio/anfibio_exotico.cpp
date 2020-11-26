#include "anfibio_exotico.hpp"

AnfibioExotico::AnfibioExotico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool cauda, bool pata):
                Exotico(nome, especie, ameacadoPor, veterinario, tratador, perigoso, local),
                Anfibio(cauda, pata){}

AnfibioExotico::~AnfibioExotico(){}