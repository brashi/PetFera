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

/**
 * @brief Classe implementando persistencia de arquivos.
 * @details A classe recebe um ponteiro para um Petshop em
 * seu construtor. Assim, a mesma oferece métodos para
 * salvar os dados referentes a funcionarios e animais
 * em arquivos csv.
 */
class BancoDados {
    public:
        /**
         * @brief construtor do Banco de dados.
         * @details Cria o banco e define as características
         * tais como diretório e nome dos arquivos para guardar
         * as informações em relação ao petshop.
         * @param Petshop como shared_ptr<Petshop>
         */
        BancoDados(shared_ptr<Petshop> petshop);
        
        /** @brief Salva os dados do Petshop */
        void salvarDados();

        /** @brief Lê os dados dos arquivos para o Petshop */
        void lerDados();
        
    private:
        /** @brief Petshop administrado pelo banco de dados */
        shared_ptr<Petshop> petshop;

        /** @brief Nome do arquivo csv de funcionarios. Definido no construtor */
        string funcArq;

        /** @brief Nome do arquivo csv de animais. Definido no construtor */
        string animalArq;

        /** @brief Nome do diretório onde os arquivos se encontram. Definido no construtor */
        string diretorio;

        /** @brief Chamada por salvarDados(), salva os dados dos funcionarios */
        void salvarFuncionarios();

        /** @brief Chamada por salvarDados(), salva os dados dos animais */
        void salvarAnimais();

        /** @brief Chamada por lerDados(), lê os dados dos funcionarios */
        void lerFuncionarios();

        /** @brief Chamada por lerDados(), lê os dados dos animais */
        void lerAnimais();

        
        /** @brief Mapeador de animais para criar um animal de acordo com o que foi lido */
        MapeadorAnimal mapa;


        /** @brief Filtro "Tradutor", serve para atribuir os valores de string para chars específicos */
        std::unordered_map<string, char> strFiltro = {
            {"ave",'A'}, {"anf", 'F'},
            {"mam", 'M'}, {"rep", 'R'},
            {"E", 'E'}, {"D", 'D'},
            {"N", 'N'}
        };

};