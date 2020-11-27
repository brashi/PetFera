#include "anfibio_exotico.hpp"

AnfibioExotico::AnfibioExotico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool cauda, bool pata):
                Anfibio(nome, especie, ameacadoPor, veterinario, tratador, perigoso, cauda, pata),
                Exotico(local){}

AnfibioExotico::~AnfibioExotico(){}