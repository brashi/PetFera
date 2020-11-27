#include "ave_nativa.hpp"

AveNativa::AveNativa(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, string licenca, bool voa):
                Ave(nome, especie, ameacadoPor, veterinario, tratador, perigoso, voa),
                Nativo(regiao, licenca){}

AveNativa::~AveNativa(){}