#include "mamifero_domestico.hpp"

MamiferoDomestico::MamiferoDomestico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado, bool gestacao):
                Mamifero(nome, especie, ameacadoPor, veterinario, tratador, perigoso, gestacao),
                Domestico(adestrado){}

MamiferoDomestico::~MamiferoDomestico(){}