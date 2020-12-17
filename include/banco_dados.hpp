#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>

#include <memory>
#include <unordered_map>

#include "mapeador_animal.hpp"
#include "petshop.hpp"

using std::shared_ptr;
using std::make_shared;

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::vector;
using std::fixed;
using std::ostream;
using std::istream;

class BancoDados {
    public:
        BancoDados(shared_ptr<Petshop> petshop);
        
        void salvarDados();
        void lerDados();
        
    private:
        shared_ptr<Petshop> petshop;
        string funcArq;
        string animalArq;
        string diretorio;

        void salvarFuncionarios();
        void salvarAnimais();

        void lerFuncionarios();
        void lerAnimais();

        MapeadorAnimal mapa;
        FiltroAnimal casts;

        std::unordered_map<string, char> strFiltro = {
            {"ave",'A'}, {"anf", 'F'},
            {"mam", 'M'}, {"rep", 'R'},
            {"E", 'E'}, {"D", 'D'},
            {"N", 'N'}
        };

};