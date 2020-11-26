#include "ave_exotica.hpp"

AveExotica::AveExotica(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool voa):
                Exotico(nome, especie, ameacadoPor, veterinario, tratador, perigoso, local),
                Ave(voa){}

AveExotica::~AveExotica(){}