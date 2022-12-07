  /**
   * @file sistemaLogin.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe responsável por armazenar um mapa de usuários, e as funções de um sistema de login deve ter
   * @version 1.1
   * @date 2022-12-05
   * @details A classe sistemaLogin armazena um mapa de ponteiros de usuários, ao qual
   * manipula-os, exibe-os, e salva tudo no arquivo txt corresponde, responsável por armazenar os usuários, 
   * podendo a mesma alterar cada atributo de um determinado usuário, além de usar as funções de menus de cada usuário
   * @copyright GNU General Public License v2.0
   */

#ifndef SISTEMALOGIN_H
#define SISTEMALOGIN_N

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
#include "gerente.hpp"
#include "funcionario.hpp"
using namespace std;

/**
   * @brief Armazena um map de vários usuários
   *
   * @details A classe sistemaLogin é responsável por armazenar varios usuários,
   * usando um map, separamos cada usuário de acordo com sua chave, sendo seu
   * Id, e o valor sendo todos os atributos de um usuário, esta classe possui
   * todas as funções que o gerente pode fazer de um usuário
   */


class sistemaLogin{
    private:
  
        ///@brief Mapa com as informações de usuários de acordo com seu Id
        map<string,Usuario*> _usuarios;
  
    public:
        ///@brief Esta é uma função de construtor, ao qual inicaliza com nenhuma informação
        ///@details inicializa um estoque default, sem nenhum parametro.
        sistemaLogin() = default;
  
        ///@brief Esta função lê o arquivo que contém todas as informações salvas, da última vez que foi acessado  
        ///@details lê o arquivo Usuario.txt , constroi objetos dos tipos gerentes e funcionários a depender do tipo declarado no arquivo
        /// e carrega no mapa todas as informações
        void lerArquivo();
  
        ///@brief Esta função salva o arquivo que contém todos os usuários e seus atributos
        ///@details carrega todas as informações do mapa dentro do arquivo Usuarios.txt
        void salvarArquivo();
  
        ///@brief Esta função cadastra um funcionário novo, podendo ser funcionário ou gerente
        ///@details Função responsável por cadastrar o usuário de forma semi-automática, sendo que o usuarioLogado no momento irá declarar
        /// o nome, senha, email e CPF e o subsistema de Login irá gerar automaticamente um ID único e a data de criação da conta no campo
        /// de Último acesso
        void cadastrarUsuario();
  
        ///@brief Esta função exclui um funcionário existente, podendo ser funcionário ou gerente
        ///@details Função responsável por excluir usuários através de uma pesquisa pelo seu ID único ou Nome completo (chama a função
        /// pesquisarUsuário()), a função é de acesso restrito para o gerente
        void excluirUsuario();
  
        ///@brief Esta função lista todos os usuários do sistema
        ///@details Função responsável por listar todos os usuários do sistema de forma dinâmica, por mostrar dados sensíveis de todos os 
        /// usuários, a função fica de acesso restrito para gerente
        void listarUsuarios();
  
        ///@brief Esta função mostra o menu de alterações de um usuário
        ///@details Função responsável por um menu que possibilita alterar todos os atributos de qualquer usuário através de uma pesquisa(
        /// chama a função pesquisarUsuário),sendo que apenas o gerente possuí esse acesso
        void alterarUsuario();
  
        ///@brief Esta função limpa a memoria de usuários do sistema
        ///@details Função responsável por apagar o mapa de usuários, é usada sempre que é preciso ler novamente dos arquivos sendo chamada
        /// antes para que evite que ocorra um overwrite, deixando todo o mapa limpo para a nova leitura do arquivo
        void limparMemoria();
  
        ///@brief Esta função limpa a tela, para poder ter uma melhor visualização na compilação
        ///@details recurso visual para melhor vizualização e interação do usuário, possui modo "perguntar" em que pergunta se pode limpar a
        /// tela antes de limpar, e modo "continuar" em que limpa direto sem perguntar
        ///@param Modo sendo uma conferência se deve ou não perguntar se pode limpar a tela
        void limparTela(string modo);
  
        ///@brief Esta função faz logout do usuário que está logado no momento da execução
        /// @details Função responsável por salvar os dados do _usuárioLogado do sistema de volta do mapa de usuários, e também por fazer
        /// seu logout mudando o atributo bool estaLogado para false
        ///@param U sendo um ponteiro armazenando qual usuário quer fazer logout
        void fazerLogout(Usuario *u);
  
        ///@brief Esta função gera um Id único para cada usuário
        /// @details Função responsável por gerar um ID único para cada usuário, o número gerado
        /// tem sempre 4 dígitos que variam de 0 a 9. A função também analisa se o número gerado existe no mapa de usuários, e caso exista
        /// é gerado um novo ID e conferido novamente, sendo retornado apenas um ID que a função tenha certeza que é único.
        ///@return Retorna este Id gerado 
        string gerarID();
  
        ///@brief Esta função gera a data atual da movimentação do sistema por um usuário específico
        /// @details Função responsável por gerar a data atual no formato DD/MM/AA e retornar em forma de string
        /// que posteriormente será usada para atualizar a última data de acesso do _usuarioLogado no sistema
        /// através da função menuLogin() desta classe.
        ///@return Retorna esta data atual do presente momento da execução
        string gerarDataAtual();
  
        ///@brief Esta função abre um menu de login, com todas as suas opções correspondente de cada usuário
        /// @details Função responsável por exibir o menu de login com duas opções, também é responsável por retornar
        /// um ponteiro para usuário que pode assumir tanto gerente ou funcionário e que será utilizado no sistema
        /// para o atributo _usuarioLogado
        ///@return um ponteiro de usuário
        Usuario* menuLogin();
  
        ///@brief Esta função dá a possibilidade de pesquisar um determinado usuário e seus atributos
        /// @details Função responsáve por pesquisar um usuário através de seu ID único ou através de seu nome completo,
        /// caso ache o usuário, irá retornar um ponteiro de usuário para o encontrado, caso o usuário não seja encontrado
        /// a função retorna um nullptr.
        ///@return um ponteiro de usuário
        ///@param Pesquisa sendo o id do usuário ou o seu nome 
        Usuario* pesquisarUsuario(string pesquisa);
};

#endif
