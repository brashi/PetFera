#include "mamifero_domestico.hpp"

MamiferoDomestico::MamiferoDomestico(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador,
                bool perigoso, bool adestrado, bool gestacao):
                Mamifero(nome, especie, ameacadoPor, veterinario, tratador, perigoso, gestacao),
                Domestico(adestrado){}

MamiferoDomestico::~MamiferoDomestico(){}