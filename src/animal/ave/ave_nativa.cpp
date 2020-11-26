#include "ave_nativa.hpp"

AveNativa::AveNativa(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, string licenca, bool voa):
                Nativo(nome, especie, ameacadoPor, veterinario, tratador, perigoso, regiao, licenca),
                Ave(voa){}

AveNativa::~AveNativa(){}