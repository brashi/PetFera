#include "ave_exotica.hpp"

AveExotica::AveExotica(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local, bool voa):
                Ave(nome, especie, ameacadoPor, veterinario, tratador, perigoso, voa),
                Exotico(local){}

AveExotica::~AveExotica(){}