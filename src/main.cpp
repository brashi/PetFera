#include <iostream>
#include "pessoa.hpp"
#include "veterinario.hpp"

#include "exotico.hpp"
#include "ave_exotica.hpp"
#include "ave_nativa.hpp"
#include "ave_domestica.hpp"

using namespace std;

int main() {

    cout << "Oi," << endl;
    Veterinario *vet = new Veterinario("Adelmar Sampaio", "(84) 9892-2224", "sampaio@petfera.com.br",
                        "1212-44");
    Tratador *tratador = new Tratador("Rodrigo Aveias", "(84) 9292-4832", "aveias@petfera.com.br",
                                Vermelho);

    AveExotica *exot = new AveExotica("BoB", "Penguin", *vet, *tratador, false, "Antartica", true);
    AveNativa *natv = new AveNativa("Bica", "Arara Azul", *vet, *tratador, false, "Floresta Amazonica", true);
    AveDomestica *domes = new AveDomestica("Bina", "Calopsita", *vet, *tratador, false, true, true);

    cout << *vet;
    cout << *tratador;
    cout << "Testando sobrecarga para animais... \n" << endl;
    cout << *exot << endl;
    cout << *natv << endl;

    Domestico testedomestico = *domes;
    cout << testedomestico << endl;

    if( Ave* checar_ave = dynamic_cast< Ave* >(domes)) {
        cout << "O animal é uma ave!" << endl;
    }
    if( Ave* checar_ave = dynamic_cast< Ave* >(natv)) {
        cout << "O animal é uma ave!" << endl;
    }

    return 0;
}