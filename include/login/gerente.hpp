  /**
   * @file gerente.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe responsável por armazenar todos os atributos de um gerente
  * @version 1.1
   * @date 2022-12-05
   * @details A classe gerente armazena todos os atributos de um gerente sendo filha de 
   * usuário, a mesma possui todas as funções, como adicionar um cadastro de um produto, adicionar um 
   * produto ou retirar, além da mesma poder fazer alterações no seu cadastro, e em todos os cadastros dos 
   * funcionários, além de poder adicionar os mesmos, ela será utilizada na inicalização do sistema
   * @copyright GNU General Public License v2.0
   */

#ifndef GERENTE_H
#define GERENTE_H

#include "usuario.hpp"

using namespace std;

/**
   * @brief Classe filha de usuário, onde possui todos os seus atributos
   *
   * @details A classe gerente é responsável por possuir todoas as funções que são possíveis
   * de fazer com as movimentaçõs do sistema, ela possui funções que são necessárias para poder 
   * tornar um sistema seguro, além de possuir um menu com as funções iniciais de um gerente, 
   * que será utilizado na inicialização do sistema 
   */

class Gerente: public Usuario {
    private:

    public:
  
        ///@brief Construtor da classe Gerente, recebe todos os atributos como parâmetro.
        ///@param Id sendo o id de um gerente
        ///@param t sendo o tipo de um gerente
        ///@param n sendo o nome de um gerente
        ///@param c sendo o CPF de um gerente, 
        ///@param e sendo o email de um gerente
        ///@param u sendo o ultimo acesso do gerente 
        ///@param s sendo a senha de um gerente
        ///@details constroi objeto da classe gerente com os parametros de ID, tipo, nome, CPF, email, ultimo acesso e senha
        Gerente(string id, string t, string n, string c, string e, string u, string s);
  
        ///@brief Esta Função abre o menu incial com todas as escolhas possíveis do gerente
        ///@details exibe o menu inicial da classe de gerente
       void menuInicial() override;
  
        ///@brief Esta Função abre o menu administrativo com todas as escolhas possíveis do gerente
        ///@details exibe o menu administrativo que apenas o gerente possui acesso, podendo levar à diversas opções de funções administrativas
        void menuAdministrativo() override;
  
        ///@brief Retorna se o gerente tem ou não permissão
        ///@return Retorna true ou false, de acordo com a permissão do gerente
        ///@details função que sobreescreve uma função de usuario que determina a permissão de acesso à funções do usuario, quando este é do tipo gerente sempre retornará true
        bool temPermissao() override;
  
        ///@brief Esta função altera o usuário que está logado no momento da execução
        ///@details abre um menu de alterar usuário, no caso do gerente, o menu leva à todas as opções de alteração, desde todos os produtos até todos os usuários 
        void alterarUsuarioLogado() override;
};


#endif
