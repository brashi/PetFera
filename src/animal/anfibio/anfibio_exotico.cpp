#include "anfibio_exotico.hpp"

AnfibioExotico::AnfibioExotico(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, string local, bool cauda, bool pata):
                Anfibio(nome, especie, ameacadoPor, veterinario, tratador, perigoso, cauda, pata),
                Exotico(local){}

AnfibioExotico::~AnfibioExotico(){}