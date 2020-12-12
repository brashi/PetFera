#include <iostream> 
#include <iterator>
#include <memory>

#include "mapeador_menu.hpp"
#include "petshop.hpp"
#include "banco_dados.hpp"

using std::cout;
using std::cin;

using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;

#ifdef DEBUG
#define Aviso(x) std::cout << x
#else
#define Debug(x)
#define Aviso(x)
#endif

void imprimirMenu() {
    cout << "/\u2588\u2588\u2588\u2588\u2588\u2588\u2588  /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 /\u2588\u2588\u2588\u2588\u2588\u2588\u2588    /\u2588\u2588\u2588\u2588\u2588\u2588 " << endl;
    cout << "| \u2588\u2588__  \u2588\u2588| \u2588\u2588_____/|__  \u2588\u2588__/| \u2588\u2588_____/| \u2588\u2588_____/| \u2588\u2588__  \u2588\u2588 /\u2588\u2588__  \u2588\u2588" << endl;
    cout << "| \u2588\u2588  \\ \u2588\u2588| \u2588\u2588         | \u2588\u2588   | \u2588\u2588      | \u2588\u2588      | \u2588\u2588  \\ \u2588\u2588| \u2588\u2588  \\ \u2588\u2588" << endl;
    cout << "| \u2588\u2588\u2588\u2588\u2588\u2588\u2588/| \u2588\u2588\u2588\u2588\u2588      | \u2588\u2588   | \u2588\u2588\u2588\u2588\u2588   | \u2588\u2588\u2588\u2588\u2588   | \u2588\u2588\u2588\u2588\u2588\u2588\u2588/| \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588" << endl;
    cout << "| \u2588\u2588____/ | \u2588\u2588__/      | \u2588\u2588   | \u2588\u2588__/   | \u2588\u2588__/   | \u2588\u2588__  \u2588\u2588| \u2588\u2588__  \u2588\u2588" << endl;
    cout << "| \u2588\u2588      | \u2588\u2588         | \u2588\u2588   | \u2588\u2588      | \u2588\u2588      | \u2588\u2588  \\ \u2588\u2588| \u2588\u2588  | \u2588\u2588" << endl;
    cout << "| \u2588\u2588      | \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588   | \u2588\u2588   | \u2588\u2588      | \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588| \u2588\u2588  | \u2588\u2588| \u2588\u2588  | \u2588\u2588" << endl;
    cout << "|__/      |________/   |__/   |__/      |________/|__/  |__/|__/  |__/" << endl;
    Aviso(  "                                                        * Modo DEBUG *" << endl;);
    cout << "======================================================================" << endl;
    cout << "    A - Listar animais                                  [ X - Fechar ]" << endl;
    cout << "    B - Adicionar animal" << endl;
    cout << "    C - Atualizar animal" << endl;
    cout << "    D - Remover animal" << endl << endl;
    cout << "    E - Listar veterinários" << endl;
    cout << "    F - Adicionar veterinário" << endl;
    cout << "    G - Atualizar veterinário" << endl;
    cout << "    H - Remover veterinário" << endl << endl;
    cout << "    I - Listar tratadores" << endl;
    cout << "    J - Adicionar tratador" << endl;
    cout << "    K - Atualizar tratador" << endl;
    cout << "    L - Remover tratador" << endl;
    cout << "======================================================================" << endl;
}

void limparTela() {
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void pausar() {
    string aux;
    cout << "Aperte enter para continuar...";
    getline(cin, aux);
}

void menu() {
    shared_ptr<Petshop> petshop = make_shared<Petshop>();
    unique_ptr<MapeadorMenu> mapeador = make_unique<MapeadorMenu>();
    bool executando = true;
    string opcao;
    
    BancoDados banco(petshop);
    banco.lerDados();
    while(executando) {
        limparTela();
        imprimirMenu();

        getline(cin, opcao);
        limparTela();

        try {
            executando = mapeador->escolhas[toupper(opcao[0])](petshop);
        } catch (const std::bad_function_call&) {
            cout << "Informe uma opção válida para realizar uma ação" << endl;
        } catch (const std::invalid_argument&) {
            cout << "Um valor numérico era esperado e não condiz com o introduzido." << endl;
        } catch (char const* msg) {
            cout << "Erro: " << msg << endl << "Verifique os dados informados e tente novamente." << endl;
        } catch (const string msg) {
            cout << "Erro: " << msg << endl << "Verifique os dados informados e tente novamente." << endl;
        } catch (...) {
            cout << "Algo de errado ocorreu, verifique os dados informados e tente novamente." << endl;
        }

        pausar();
    }
    
    banco.salvarDados();
}

int main() {
    menu();
    return 0;
}