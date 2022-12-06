  /**
   * @file funcionario.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe responsável por armazenar todos os atributos de um funcionário
   * @version 1.1
   * @date 2022-12-05
   * @details A classe funcionário armazena todos os atributos de um funcionário criado pelo gerente
   * sendo filha de um usuário, a mesma possui todas as funções que são cabíveis a ela, 
   * além da mesma poder fazer alterações no seu cadastro, como sua senha, ela será utilizada
   * na inicalização do sistema
   * @copyright GNU General Public License v2.0
   */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "usuario.hpp"
#include "EXCECOESDOLOGIN.hpp"

using namespace std;

/**
   * @brief Classe filha de usuário, onde possui todos os seus atributos
   *
   * @details A classe funcionario é responsável por possuir as funções que são possíveis
   * de funcionário acessar, possui funções que são necessárias pode poder tornar um sistema
   * seguro, além de possuir um menu com as funções iniciais de um funcionário, que será utilizado  
   * na inicialização do sistema  
   */

class Funcionario: public Usuario {
    private:
    public:
  
        ///@brief Construtor da classe Funcionario, recebe todos os atributos como parâmetro.
        ///@param Id sendo o id de um funcionário, t sendo o tipo de um funcionário, n sendo o nome de um funcionário, c sendo o CPF de um funcionário, 
        /// e sendo o email de um funcionário, u sendo o ultimo acesso do funcionário e s sendo a senha de um funcionário
        Funcionario(string id, string t, string n, string c, string e, string u, string s);
  
        ///@brief Esta Função abre o menu incial com todas as escolhas possíveis do funcionário
        void menuInicial() override;
  
        ///@brief Esta função abre o menu administrativo com todas as escolhas possíveis do funcionário
        void menuAdministrativo() override;
  
        ///@brief Retorna se o funcionário tem ou não permissão
        ///@return Retorna true ou false, de acordo com a permissão do funcionário
        bool temPermissao() override;
  
        ///@brief Esta função altera o funcionário que está logado no momento da execução
        void alterarUsuarioLogado() override;
};


#endif
