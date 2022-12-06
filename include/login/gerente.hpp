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
        ///@param Id sendo o id de um gerente, t sendo o tipo de um gerente, n sendo o nome de um gerente, c sendo o CPF de um gerente, 
        /// e sendo o email de um gerente, u sendo o ultimo acesso do gerente e s sendo a senha de um gerente
        Gerente(string id, string t, string n, string c, string e, string u, string s);
  
        ///@brief Esta Função abre o menu incial com todas as escolhas possíveis do gerente
       void menuInicial() override;
  
        ///@brief Esta Função abre o menu administrativo com todas as escolhas possíveis do gerente
        void menuAdministrativo() override;
  
        ///@brief Retorna se o gerente tem ou não permissão
        ///@return Retorna true ou false, de acordo com a permissão do gerente
        bool temPermissao() override;
  
        ///@brief Esta função altera o usuário que está logado no momento da execução
        void alterarUsuarioLogado() override;
};


#endif
