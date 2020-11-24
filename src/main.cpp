#include <functional>
#include <iostream> 
#include <iterator>
#include <string>
#include <map>

#include "mapeador.hpp"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

void imprimirMenu() {
    cout << "Menu teste!" << endl;
}

void limparTela() {
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}

void pausar() {
    string aux;
    cout << "Aperte enter para continuar..." << endl;
    cin.ignore();
    getline(cin, aux);
}

void menu() {
    MapeadorMenu *mapeador = new MapeadorMenu();
    bool executando = true;
    char opcao;

    while(executando) {
        limparTela();
        imprimirMenu();

        cin >> opcao;
        limparTela();

        executando = mapeador->escolhas[toupper(opcao)]();
        pausar();
    }
}

int main() {
    menu();
    return 0;
}