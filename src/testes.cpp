#include "testes.hpp"


void acionarTestes(shared_ptr<Petshop> ps) {
    shared_ptr<Veterinario> vet = make_shared<Veterinario>("General Sampaio", "(84) 19898-9292", "sampaio@petfera.com", "12345");
    shared_ptr<Tratador> verdes = make_shared<Tratador>("Adriano Verdes", "(84) 9129-1012", "verdes@petfera", Verde);
    shared_ptr<Tratador> azulis = make_shared<Tratador>("Laila Azulis", "(21) 92222-2221", "azulis@petfera", Azul);
    shared_ptr<Tratador> rubro = make_shared<Tratador>("Moura Rubro", "(51) 2312-1444", "rubro@petfera", Vermelho);


    ps->adicionarVeterinario(vet);
    ps->adicionarTratador(verdes);
    ps->adicionarTratador(azulis);
    ps->adicionarTratador(rubro);

    ps->adicionarAnimal(make_shared<AveDomestica>("Pita", "Calopsita", "Nada", *vet, *verdes, false, false, true));
    ps->adicionarAnimal(make_shared<AveDomestica>("PiuPiu", "Canário", "Nada", *vet, *verdes, false, true, true));
    ps->adicionarAnimal(make_shared<AveNativa>("Blu", "Arara Azul", "Desmatamento e tráfico", *vet, *verdes, false, "Pantanal", "3333-1233-IBAMA", false));
    ps->adicionarAnimal(make_shared<AveExotica>("Tux", "Pinguim", "Aquecimento Global", *vet, *verdes, false, "Antártida", false));

    ps->adicionarAnimal(make_shared<AnfibioDomestico>("Cururu", "Sapo-Cururu", "Nada", *vet, *verdes, false, false, false, true));
    ps->adicionarAnimal(make_shared<AnfibioNativo>("Nanarã", "Phyllobates terribilis", "Desmatamento", *vet, *rubro, true, "Amazonia", "0777-4040-IBAMA", false, true));

    ps->adicionarAnimal(make_shared<ReptilNativo>("Darwin", "Jabuti", "Nada", *vet, *azulis, false, "Nordeste", "5953-0001-IBAMA", Carapaca));
    ps->adicionarAnimal(make_shared<ReptilNativo>("Ananaconda", "Sucuri", "Nada", *vet, *rubro, true, "Amazonia", "1110-2222-IBAMA", Escama));
    ps->adicionarAnimal(make_shared<ReptilExotico>("Aligatore", "Aligátor americano", "Nada", *vet, *rubro, true, "America do Norte", Placa));

    ps->adicionarAnimal(make_shared<MamiferoDomestico>("Polar", "Husky siberiano", "Nada", *vet, *azulis, false, true, true));
    ps->adicionarAnimal(make_shared<MamiferoNativo>("Tatada", "Tamanduá-bandeira", "Caça predatória", *vet, *azulis, true, "America do Norte", "8842-2220-IBAMA",true));
    ps->adicionarAnimal(make_shared<MamiferoExotico>("Usarde", "Urso-pardo", "Nada", *vet, *rubro, true, "America do Norte", true));
    ps->adicionarAnimal(make_shared<MamiferoExotico>("Parry", "Ornitorrinco", "Nada", *vet, *azulis, true, "Australia", false));
}