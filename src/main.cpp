#include <iostream> 
#include <iterator>

#include "mapeador.hpp"
#include "petshop.hpp"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

void imprimirMenu() {
    cout << "/\u2588\u2588\u2588\u2588\u2588\u2588\u2588  /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588    /\u2588\u2588\u2588\u2588\u2588\u2588 " << endl;
    cout << "| \u2588\u2588__  \u2588\u2588| \u2588\u2588_____/|__  \u2588\u2588__/| \u2588\u2588_____/| \u2588\u2588_____/| \u2588\u2588__  \u2588\u2588 /\u2588\u2588__  \u2588\u2588" << endl;
    cout << "| \u2588\u2588  \\ \u2588\u2588| \u2588\u2588         | \u2588\u2588   | \u2588\u2588      | \u2588\u2588      | \u2588\u2588  \\ \u2588\u2588| \u2588\u2588  \\ \u2588\u2588" << endl;
    cout << "| \u2588\u2588\u2588\u2588\u2588\u2588\u2588/| \u2588\u2588\u2588\u2588\u2588      | \u2588\u2588   | \u2588\u2588\u2588\u2588\u2588   | \u2588\u2588\u2588\u2588\u2588   | \u2588\u2588\u2588\u2588\u2588\u2588\u2588/| \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588" << endl;
    cout << "| \u2588\u2588____/ | \u2588\u2588__/      | \u2588\u2588   | \u2588\u2588__/   | \u2588\u2588__/   | \u2588\u2588__  \u2588\u2588| \u2588\u2588__  \u2588\u2588" << endl;
    cout << "| \u2588\u2588      | \u2588\u2588         | \u2588\u2588   | \u2588\u2588      | \u2588\u2588      | \u2588\u2588  \\ \u2588\u2588| \u2588\u2588  | \u2588\u2588" << endl;
    cout << "| \u2588\u2588      | \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588   | \u2588\u2588   | \u2588\u2588      | \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588| \u2588\u2588  | \u2588\u2588| \u2588\u2588  | \u2588\u2588" << endl;
    cout << "|__/      |________/   |__/   |__/      |________/|__/  |__/|__/  |__/" << endl;
    cout << "======================================================================" << endl;
    cout << "A - Listar animais                                      [ X - Fechar ]" << endl;
    cout << "B - Adicionar animal" << endl;
    cout << "C - Atualizar animal" << endl;
    cout << "D - Remover animal" << endl;
    cout << "======================================================================" << endl;
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
    Petshop *petshop = new Petshop();
    MapeadorMenu *mapeador = new MapeadorMenu();
    bool executando = true;
    char opcao;

    while(executando) {
        limparTela();
        imprimirMenu();

        cin >> opcao;
        limparTela();

        try {
            executando = mapeador->escolhas[toupper(opcao)](petshop);
        }
        catch (const std::bad_function_call&) {
            cout << "Informe uma opção válida para realizar uma ação" << endl;
        }
        catch (...) {
            cout << "Algo de errado ocorreu, tente novamente" << endl;
        }

        pausar();
    }
    
    delete petshop;
}

int main() {
    menu();
    return 0;
}