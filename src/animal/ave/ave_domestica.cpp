#include "ave_domestica.hpp"

AveDomestica::AveDomestica(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, bool adestrado, bool voa):
                Ave(nome, especie, ameacadoPor, veterinario, tratador, perigoso, voa),
                Domestico(adestrado){}

AveDomestica::~AveDomestica(){}