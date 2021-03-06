#include "ave_exotica.hpp"

AveExotica::AveExotica(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, string local, bool voa):
                Ave(nome, especie, ameacadoPor, veterinario, tratador, perigoso, voa),
                Exotico(local){}

AveExotica::~AveExotica(){}