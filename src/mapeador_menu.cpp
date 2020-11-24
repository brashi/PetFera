#include "mapeador_menu.hpp"

using std::cout;
using std::cin;

MapeadorMenu::MapeadorMenu() {
    escolhas['A'] = [](Petshop* ps) {
        ps->listarAnimais();
        return true;
    };
    escolhas['B'] = [](Petshop* ps) {
        ps->criarAnimal();
        return true;
    };
    escolhas['C'] = [](Petshop* ps) {
        ps->atualizarAnimal();
        return true;
    };
    escolhas['D'] = [](Petshop* ps) {
        ps->excluirAnimal();
        return true;
    };

    escolhas['E'] = [](Petshop* ps) {
        ps->listarVeterinarios();
        return true;
    };
    escolhas['F'] = [](Petshop* ps) {
        ps->criarVeterinario();
        return true;
    };
    escolhas['G'] = [](Petshop* ps) {
        ps->atualizarVeterinario();
        return true;
    };
    escolhas['H'] = [](Petshop* ps) {
        ps->excluirVeterinario();
        return true;
    };

    escolhas['I'] = [](Petshop* ps) {
        ps->listarTratadores();
        return true;
    };
    escolhas['J'] = [](Petshop* ps) {
        ps->criarTratador();
        return true;
    };
    escolhas['K'] = [](Petshop* ps) {
        ps->atualizarTratador();
        return true;
    };
    escolhas['L'] = [](Petshop* ps) {
        ps->excluirTratador();
        return true;
    };

    escolhas['X'] = [](Petshop* ps) {
        cout << "Saindo do programa..." << endl;
        return false;
    };
}