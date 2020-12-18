#include "mapeador_menu.hpp"

using std::cout;
using std::cin;

MapeadorMenu::MapeadorMenu() {
    escolhas['A'] = [](shared_ptr<Petshop> ps) {
        ps->listarAnimais();
        return true;
    };
    escolhas['B'] = [](shared_ptr<Petshop> ps) {
        ps->criarAnimal();
        return true;
    };
    escolhas['C'] = [](shared_ptr<Petshop> ps) {
        ps->atualizarAnimal();
        return true;
    };
    escolhas['D'] = [](shared_ptr<Petshop> ps) {
        ps->excluirAnimal();
        return true;
    };

    escolhas['E'] = [](shared_ptr<Petshop> ps) {
        ps->listarVeterinarios();
        return true;
    };
    escolhas['F'] = [](shared_ptr<Petshop> ps) {
        ps->criarVeterinario();
        return true;
    };
    escolhas['G'] = [](shared_ptr<Petshop> ps) {
        ps->atualizarVeterinario();
        return true;
    };
    escolhas['H'] = [](shared_ptr<Petshop> ps) {
        ps->excluirVeterinario();
        return true;
    };

    escolhas['I'] = [](shared_ptr<Petshop> ps) {
        ps->listarTratadores();
        return true;
    };
    escolhas['J'] = [](shared_ptr<Petshop> ps) {
        ps->criarTratador();
        return true;
    };
    escolhas['K'] = [](shared_ptr<Petshop> ps) {
        ps->atualizarTratador();
        return true;
    };
    escolhas['L'] = [](shared_ptr<Petshop> ps) {
        ps->excluirTratador();
        return true;
    };

    escolhas['X'] = [](shared_ptr<Petshop> ps) {
        cout << "Saindo do programa..." << endl;
        return false;
    };

    escolhas['T'] = [](shared_ptr<Petshop> ps) {
        #ifdef DEBUG
            cout << "Arquivos de testes carregado !" << endl;
            return true;
        #else
            cout << "Informe uma opção válida para realizar uma ação" << endl;
            return true;
        #endif
    };

    escolhas['N'] = [](shared_ptr<Petshop> ps) {
        if(std::filesystem::is_empty("dados/")) {
            cout << "Informe uma opção válida para realizar uma ação" << endl;
            return true;
        }
        cout << "O banco de dados foi completamente apagado." << endl;
        return true;
    };
}