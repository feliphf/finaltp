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
        ///@brief Construtor sistema login
        sistemaLogin() = default;
        ///@brief Esta função lê o arquivo que contém todas as informações salvas, da última vez que foi acessado   
        void lerArquivo();
  
        ///@brief Esta função salva o arquivo que contém todos os usuários e seus atributos
        void salvarArquivo();
  
        ///@brief Esta função cadastra um funcionário novo, podendo ser funcionário ou gerente
        void cadastrarUsuario();
  
        ///@brief Esta função exclui um funcionário existente, podendo ser funcionário ou gerente
        void excluirUsuario();
  
        ///@brief Esta função lista todos os usuários do sistema
        void listarUsuarios();
  
        ///@brief Esta função mostra o menu de alterações de um usuário
        void alterarUsuario();
  
        ///@brief Esta função limpa a memoria de usuários do sistema
        void limparMemoria();
  
        ///@brief Esta função limpa a tela, para poder ter uma melhor visualização na compilação
        void limparTela(string modo);
  
        ///@brief Esta função faz logout do usuário que está logado no momento da execução
        void fazerLogout(Usuario *u);
  
        ///@brief Esta função gera um Id único para cada usuário
        ///@return Retorna este Id gerado 
        string gerarID();
  
        ///@brief Esta função gera a data atual da movimentação do sistema por um usuário específico
        ///@return Retorna esta data atual do presente momento da execução
        string gerarDataAtual();
  
        ///@brief Esta função abre um menu de login, com todas as suas opções correspondente de cada usuário
        ///@return um ponteiro de usuário
        Usuario* menuLogin();
  
        ///@brief Esta função dá a possibilidade de pesquisar um determinado usuário e seus atributos
        ///@return um ponteiro de usuário
        Usuario* pesquisarUsuario(string pesquisa);
};

#endif
