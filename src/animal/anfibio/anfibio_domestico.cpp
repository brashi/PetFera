#include "anfibio_domestico.hpp"

AnfibioDomestico::AnfibioDomestico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool cauda, bool pata):
                Domestico(nome, especie, ameacadoPor, veterinario, tratador, perigoso, adestrado),
                Anfibio(cauda, pata){}

AnfibioDomestico::~AnfibioDomestico(){}