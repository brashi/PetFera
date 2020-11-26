#include "ave_domestica.hpp"

AveDomestica::AveDomestica(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool voa):
                Domestico(nome, especie, ameacadoPor, veterinario, tratador, perigoso, adestrado),
                Ave(voa){}

AveDomestica::~AveDomestica(){}