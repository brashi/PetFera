#include <iostream>
#include "pessoa.hpp"
#include "veterinario.hpp"

#include "exotico.hpp"
#include "ave_exotica.hpp"

using namespace std;

int main() {

    cout << "Oi," << endl;
    Veterinario *vet = new Veterinario("Adelmar Sampaio", "(84) 9892-2224", "sampaio@petfera.com.br",
                        "1212-44");
    Tratador *tratador = new Tratador("Rodrigo Aveias", "(84) 9292-4832", "aveias@petfera.com.br",
                                Vermelho);

    AveExotica *exot = new AveExotica("BoB", "Penguin", *vet, *tratador, false, "Antartica", true);


    //cout << "Animal: " << exot->getNome() << " Especie: " << exot->getEspecie() << endl;
    cout << *vet;
    cout << *tratador;

    return 0;
}