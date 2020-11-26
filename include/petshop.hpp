#pragma once

#include "animal.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include "mapeador_animal.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <functional>

using std::vector;

/**
 * @brief Classe de controle
 * @details A classe é responsável pelo controle das demais. Formando a estrutura
 * digital do PetFera como um todo. Realizando as atividades de cadastro, administração
 * e atualização de dados. Nela podemos:
 * - Adicionar, remover e atualizar dados cadastrais de...
 *  -# Animais
 *  -# Veterinarios
 *  -# Tratadores
 * - Listagem de dados de diversas origens
 * - Interface entre usuario
 * - Guardar as informações de cada classe anterior a esta.
 * @todo
 * - Cadastro de Especies
 * - Lisenças para animais (Silvestre... Nativo)
 * - Classificações de status de extinção para animais com base na espécie
 */
class Petshop {
    public:
        /**
         * @brief O construtor deve ser padrão.
         * @details Por padrão devemos ter nenhum parâmetro, sendo eles
         * definido pela própia classe de acordo com as opções determinadas
         * pelo usuário, de forma natural.
         */
        Petshop();
        /**
         * @brief Destrutor padrão.
         * @details Tem uma função importante
         * sendo ela a importante questão de desalocar
         * os vetores alocados para Animal, Tratador e Veterinario.
         */
        ~Petshop();
        
        /**
         * @brief Listagem de Animais no registro.
         * @details Abre a interface de listagem para animais.
         * Abrindo as opções ao usuário de listar por filtros ou não.
         * As opções dadas ao usuário são:
         * - Listagem pela classificação do animal, tais como:
         *  -# (A) para listar os do tipo Ave no sistema.
         *  -# (F) para listar os do tipo Anfibio no sistema.
         *  -# (R) para listar os do tipo Reptil no sistema.
         *  -# (M) para listar os do tipo Mamifero no sistema.
         *  -# (F) para listar os do tipo Anfibio no sistema.
         * - Listagem pela categoria do IBAMA, tais como:
         *  -# (D) listando os da categoria Domestico.
         *  -# (E) listando os da categoria Exotico.
         *  -# (N) listando os da categoria Nativo.
         * - E além disso, é possível listar animais sobre
         * responsábilidade de um certo Veterinario ou Tratador.
         * - Também é possível listar todos os animais cadastrados
         * no sistema.
         */
        void listarAnimais();
        
        /**
         * @brief Listagem dos Tratadores registrados.
         * @details Lista todos os funcionarios do tipo
         * Tratador cadastrados no sistema. A listagem apresenta
         * dados em relação a...
         * - Nome do Tratador
         * - Telefone para contato
         * - E-mail
         * - Uniforme do mesmo, categorizando-o em um nível de segurança.
         */
        void listarTratadores();
        
        /**
         * @brief Listagem dos Veterinarios registrados.
         * @details Lista todos os funcionarios do tipo
         * Veterinario cadastrados no sistema. A listagem
         * apresenta dados em relação a...
         * - Nome do Veterinario
         * - Telefone para contato
         * - E-mail
         * - CRMV cadastrado em acordo com a legislação vigente.
         */
        void listarVeterinarios();

        /**
         * @brief Criação de tipo Veterinario.
         * @details Implementa a interface de criação
         * para um novo cadastro de Veterinario para o
         * sistema. Após seu cadastro, o mesmo é salvo no sistema.
         * Neste método é requirido as informações
         * do Veterinario a ser cadastrado no sistema, como...
         * - Seu nome, não podendo se repetir...
         * - Telefone para contato.
         * - E-mail
         * - CRMV cadastrado no orgão vigente.
         */
        void criarVeterinario();

        /**
         * @brief Criação do tipo Tratador.
         * @details Implementa a interface de criação
         * para um novo cadastro do tipo Tratador. Sendo
         * salvo no sistema após um processo de cadastro
         * bem sucedido. Neste método, é necessário
         * informar as informações do Tratador a ser
         * cadastrado, sendo elas...
         * - Seu nome, não podendo se repetir no sistema...
         * - Telefone para contato.
         * - E-mail
         * - Uniforme do mesmo, categorizando-o em um nível de segurança.
         */
        void criarTratador();

        /**
         * @brief Criação do tipo Animal.
         * @details Implementação da interface
         * e função de cadastro para tipo Animal. Nesta
         * função temos a coleta de dados para o cadastro
         * de um novo Animal no sistema. Seus dados são
         * postos no cadastro geral após o processo.
         * Um animal necessita de um Veterinario e
         * um Tratador previamente cadastrado no sistema,
         * além disso, é necessário que o Tratador seja
         * qualificado (pelo seu Uniforme) a trabalhar
         * com as especificidades do Animal em questão.
         * Para o cadastro, é necessário informar os seguintes
         * dados:
         * - Nome, especie, Veterinario, Tratador
         * - Informar a Classificação do animal, entre elas:
         *  -# Ave
         *  -# Reptil
         *  -# Anfibio
         *  -# Mamifero
         * - E também sua categoria legal, podendo ser:
         *  -# Domestico
         *  -# Exotico
         *  -# Nativo
         * - Também é necessário informar específicidades de cada
         * espécie.
         */
        void criarAnimal();

        /**
         * @brief Adição interna de Veterinario no sistema.
         * @details Realiza o processo de facto de adição no
         * sistema para as classes do tipo Veterinario. Sendo
         * chamado pelo método criarVeterinario().
         * A função guarda a instância da classe em seu sistema,
         * localizado no Vetor de cadastro de Veterinario na
         * classe Petshop.
         */
        bool adicionarVeterinario(Veterinario* vetAdd);

        /**
         * @brief Adição interna de Tratador no sistema.
         * @details Realiza o processo de facto de adição no
         * sistema para as classes do tipo Tratador. Sendo
         * chamado pelo método criarTratador().
         * A função guarda a instância da classe em seu sistema,
         * localizado no Vetor de cadastro de Tratador na
         * classe Petshop.
         */
        bool adicionarTratador(Tratador* tratAdd);

        /**
         * @brief Adição interna de Animal no sistema.
         * @details Realiza o processo de facto de adição no
         * sistema para as classes do tipo Animal. Sendo
         * chamado pelo método criarAnimal().
         * A função guarda a instância da classe em seu sistema,
         * localizado no Vetor de cadastro de Animal na
         * classe Petshop.
         */
        bool adicionarAnimal(Animal* animalAdd);


        /**
         * @brief Atualização de cadastro para Veterinario
         * @details Implementa a interface e realiza
         * a atualização do cadastro para classes
         * do tipo Veterinario no sistema. O processo
         * pede a informação de um Veterinario devidamente
         * cadastrado para o processo de atualização cadastral.
         * É necessário prover dados semelhantes aos citados
         * no método criarVeterinario(), podendo haver uma total
         * recriação da instancia.
         */
        void atualizarVeterinario();

        /**
         * @brief Atualização de cadastro para Tratador
         * @details Implementa a interface e realiza
         * a atualização do cadastro para classes do tipo
         * Tratador no sistema. O processo pede a informação de um Tratador devidamente
         * cadastrado para o processo de atualização cadastral.
         * É necessário prover dados semelhantes aos citados
         * no método criarTratador(), podendo haver uma total
         * recriação da instancia.
         */
        void atualizarTratador();

        /**
         * @brief Atualização de cadastro para Animal
         * @details Implementa a interface e realiza
         * a atualização do cadastro para classes
         * do tipo Animal no sistema. O processo
         * pede a informação de um Animal devidamente
         * cadastrado para o processo de atualização cadastral.
         * É necessário prover dados semelhantes aos citados
         * no método criarAnimal(), podendo haver uma total
         * recriação da instancia. Para animal em específico é possível
         * também mudar as Classificações e Categorias do animal, sendo
         * um processo completo de atualização cadastral.
         */
        void atualizarAnimal();


        /**
         * @brief Exclusão de cadastro para Veterinario
         * @details Implementação da interface e processo
         * de remoção de cadastro no sistema. O método
         * após ser chamado pede por parâmetros do
         * alvo a ser removido. Neste caso é necessário
         * o nome do Veterinario a ser removido.
         * Após o processo, o mesmo é removido do sistema
         * e dos registros, podendo ser oferecido um
         * ponteiro da instância do alvo removido para usos futuros.
         * Por enquanto, a instância é apenas deletada do sistema.
         */
        void excluirVeterinario();

        /**
         * @brief Exclusão de cadastro para Tratador
         * @details Implementação da interface e processo
         * de remoção de cadastro no sistema. O método
         * após ser chamado pede por parâmetros do
         * alvo a ser removido. Neste caso é necessário
         * o nome do Tratador a ser removido.
         * Após o processo, o mesmo é removido do sistema
         * e dos registros, podendo ser oferecido um
         * ponteiro da instância do alvo removido para usos futuros.
         * Por enquanto, a instância é apenas deletada do sistema.
         */
        void excluirTratador();

        /**
         * @brief Exclusão de cadastro para Animal
         * @details Implementação da interface e processo
         * de remoção de cadastro no sistema. O método
         * após ser chamado pede por parâmetros do
         * alvo a ser removido. Neste caso é necessário
         * o nome e a especie do Animal a ser removido.
         * Após o processo, o mesmo é removido do sistema
         * e dos registros, podendo ser oferecido um
         * ponteiro da instância do alvo removido para usos futuros.
         * Por enquanto, a instância é apenas deletada do sistema.
         */
        void excluirAnimal();


        /**
         * @brief Remoção interna de Veterinario
         * @details O método em questão é usado
         * internamente pela classe. Fazendo a exclusão
         * da instância removida do Vetor que é usado
         * para guarda-la no sistema.
         * A função retorna uma referência ao alvo
         * removido, podendo ser utilizado posteriormente
         * a quem chamou a função.
         * Depois do método, referências sobre a instância
         * removida não vão estar mais ao alcance da 
         * classe, pois a mesma não se encontra no Vetor
         * organizador da classe.
         * A função é chamada pela de mesmo nome, com tipo
         * void, que implementa a interface chamada de
         * excluirVeterinario().
         */
        Veterinario* excluirVeterinario(Veterinario* removido);

        /**
         * @brief Remoção interna de Tratador
         * @details O método em questão é usado
         * internamente pela classe. Fazendo a exclusão
         * da instância removida do Vetor que é usado
         * para guarda-la no sistema.
         * A função retorna uma referência ao alvo
         * removido, podendo ser utilizado posteriormente
         * a quem chamou a função.
         * Depois do método, referências sobre a instância
         * removida não vão estar mais ao alcance da 
         * classe, pois a mesma não se encontra no Vetor
         * organizador da classe.
         * A função é chamada pela de mesmo nome, com tipo
         * void, que implementa a interface chamada de
         * excluirTratador().
         */
        Tratador* excluirTratador(Tratador* removido);

        /**
         * @brief Remoção interna de Animal
         * @details O método em questão é usado
         * internamente pela classe. Fazendo a exclusão
         * da instância removida do Vetor que é usado
         * para guarda-la no sistema.
         * A função retorna uma referência ao alvo
         * removido, podendo ser utilizado posteriormente
         * a quem chamou a função.
         * Depois do método, referências sobre a instância
         * removida não vão estar mais ao alcance da 
         * classe, pois a mesma não se encontra no Vetor
         * organizador da classe.
         * A função é chamada pela de mesmo nome, com tipo
         * void, que implementa a interface chamada de
         * excluirAnimal().
         */
        Animal* excluirAnimal(Animal* removido);
    
    private:
        /**
         * @brief Uso interno
         * @details Acha e retorna a referência
         * para o tipo Veterinario com o mesmo
         * nome que o informado.
         * @param nome como string
         * @return Referência a instância, retorna
         * nullptr caso não exista.
         */
        Veterinario* findVeterinario(string nome);
        /**
         * @brief Uso interno
         * @details Acha e retorna a referência
         * para o tipo Tratador com o mesmo
         * nome que o informado.
         * @param nome como string
         * @return Referência a instância, retorna
         * nullptr caso não exista.
         */
        Tratador* findTratador(string nome);
        /**
         * @brief Uso interno
         * @details Acha e retorna a referência
         * para o tipo Animal com o mesmo
         * nome que o informado.
         * @param nome como string
         * @param especie como string
         * @return Referência a instância, retorna
         * nullptr caso não exista.
         */
        Animal* findAnimal(string nome, string especie);

        /** @brief vetor guardando as instâncias de Veterinario do sistema. */
        vector<Veterinario*> veterinarios;
        /** @brief vetor guardando as instâncias de Tratador do sistema. */
        vector<Tratador*> tratadores;
        /** @brief vetor guardando as instâncias de Animal do sistema. */
        vector<Animal*> animais;

        /** @brief Mapeador de animais, veja MapeadorAnimal */
        MapeadorAnimal mapa;
};