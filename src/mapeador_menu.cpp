#include "mapeador_menu.hpp"

using std::cout;
using std::cin;

MapeadorMenu::MapeadorMenu() {
    escolhas['A'] = [](std::shared_ptr<Petshop> ps) {
        ps->listarAnimais();
        return true;
    };
    escolhas['B'] = [](std::shared_ptr<Petshop> ps) {
        ps->criarAnimal();
        return true;
    };
    escolhas['C'] = [](std::shared_ptr<Petshop> ps) {
        ps->atualizarAnimal();
        return true;
    };
    escolhas['D'] = [](std::shared_ptr<Petshop> ps) {
        ps->excluirAnimal();
        return true;
    };

    escolhas['E'] = [](std::shared_ptr<Petshop> ps) {
        ps->listarVeterinarios();
        return true;
    };
    escolhas['F'] = [](std::shared_ptr<Petshop> ps) {
        ps->criarVeterinario();
        return true;
    };
    escolhas['G'] = [](std::shared_ptr<Petshop> ps) {
        ps->atualizarVeterinario();
        return true;
    };
    escolhas['H'] = [](std::shared_ptr<Petshop> ps) {
        ps->excluirVeterinario();
        return true;
    };

    escolhas['I'] = [](std::shared_ptr<Petshop> ps) {
        ps->listarTratadores();
        return true;
    };
    escolhas['J'] = [](std::shared_ptr<Petshop> ps) {
        ps->criarTratador();
        return true;
    };
    escolhas['K'] = [](std::shared_ptr<Petshop> ps) {
        ps->atualizarTratador();
        return true;
    };
    escolhas['L'] = [](std::shared_ptr<Petshop> ps) {
        ps->excluirTratador();
        return true;
    };

    escolhas['X'] = [](std::shared_ptr<Petshop> ps) {
        cout << "Saindo do programa..." << endl;
        return false;
    };
}