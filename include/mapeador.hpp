#include "animal.hpp"

#include "ave_domestica.hpp"
#include "ave_nativa.hpp"
#include "ave_exotica.hpp"

#include "anfibio_domestico.hpp"
#include "anfibio_nativo.hpp"
#include "anfibio_exotico.hpp"

#include "reptil_domestico.hpp"
#include "reptil_nativo.hpp"
#include "reptil_exotico.hpp"

#include "mamifero_domestico.hpp"
#include "mamifero_nativo.hpp"
#include "mamifero_exotico.hpp"

#include "veterinario.hpp"
#include "tratador.hpp"

#include <functional>
#include <string>
#include <map>

typedef struct DadosAnimal {
    //Animal
    string nome;
    string especie;
    Veterinario veterinario;
    Tratador tratador;
    bool perigoso;

    //Categoria
    string regiao;
    string local;
    bool adestrado;

    //Classe
    bool voa;
    bool cauda;
    bool pata;
    string gestacao;
    Pele pele;
    
} DadosAnimal;

class MapeadorAnimal {
    public:
        MapeadorAnimal();
        std::map<string, std::function<Animal* (DadosAnimal dados)>> sMap;
};

class MapeadorMenu {
    public:
        MapeadorMenu();
        std::map<char, std::function<bool()>> escolhas;
};