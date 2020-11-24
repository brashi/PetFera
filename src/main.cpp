#include <iostream>
#include "pessoa.hpp"
#include "veterinario.hpp"

#include "exotico.hpp"
#include "ave_exotica.hpp"
#include "ave_nativa.hpp"
#include "ave_domestica.hpp"
#include "anfibio_domestico.hpp"

#include "petshop.hpp"

using namespace std;

int main() {

    cout << "Oi," << endl;
    Veterinario *vet = new Veterinario("Adelmar Sampaio", "(84) 9892-2224", "sampaio@petfera.com.br",
                        "1212-44");
    Tratador *tratador = new Tratador("Rodrigo Aveias", "(84) 9292-4832", "aveias@petfera.com.br",
                                Vermelho);

    // AveExotica *exot = new AveExotica("BoB", "Penguin", *vet, *tratador, false, "Antartica", true);
    // AveNativa *natv = new AveNativa("Bica", "Arara Azul", *vet, *tratador, false, "Floresta Amazonica", true);
    AveDomestica *domes = new AveDomestica("Bina", "Calopsita", *vet, *tratador, false, true, true);

    cout << *vet;
    cout << *tratador;
    cout << "Testando sobrecarga para animais... \n" << endl;
    // cout << *exot << endl;
    // cout << *natv << endl;


    // if( Ave* checar_ave = dynamic_cast< Ave* >(domes)) {
    //     cout << "O animal é uma ave!" << endl;
    // }
    // if( Ave* checar_ave = dynamic_cast< Ave* >(natv)) {
    //     cout << "O animal é uma ave!" << endl;
    // }
    
    AnfibioDomestico *novo = new AnfibioDomestico("Pepe", "Sapo", *vet, *tratador, false, true, false, true);

    cout << *domes;
    cout << *novo;

    /*if( Ave* checar_ave = dynamic_cast< Ave* >(novo)) {
        cout << "O animal é uma ave!" << endl;
    } else {
        cout << "Não é uma ave" << endl;
    } */

    Tratador *outro = new Tratador("Adelmar Sampaio", "(84) 9892-2224", "sampaio@petfera.com.br",
                        Verde);
    if( (*vet) == (*outro) )
        cout << "sao iguais" << endl;
    else
        cout << "nao sao iguais" << endl;
    
    AveDomestica *teste1 = new AveDomestica("Bina", "Calopsita", *vet, *tratador, false, true, true);
    AnfibioDomestico *teste2 = new AnfibioDomestico("tete", "Calopsita", *vet, *tratador, false, true, true, false);

    if (*teste1 == *teste2)
        cout << "animais iguais" << endl;
    else
        cout << "Animais diferentes" << endl;


    Petshop* fera = new Petshop;

    fera->adicionarTratador(tratador);
    fera->adicionarVeterinario(vet);
    fera->adicionarAnimal(teste1);
    fera->adicionarAnimal(teste2);
    fera->criarAnimal();
    fera->listarAnimais();
    return 0;
}