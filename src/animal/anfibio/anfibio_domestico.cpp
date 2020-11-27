#include "anfibio_domestico.hpp"

AnfibioDomestico::AnfibioDomestico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool cauda, bool pata):
                Anfibio(nome, especie, ameacadoPor, veterinario, tratador, perigoso, cauda, pata),
                Domestico(adestrado){}

AnfibioDomestico::~AnfibioDomestico(){}