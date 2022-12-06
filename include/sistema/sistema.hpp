  /**
   * @file sistema.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe responsável pela inicialização do sistema
   * @version 1.1
   * @date 2022-12-05
   * @details A classe sistema armazena um ponteiro de um usúario ao qual esta classe irá mostrar
   * os menus compatíveis para cada tipo de usuário, esta classe será a principal do sistema, ela inicializará
   * todos as possíveis modificações, movimentações, e funcionamento do sistema 
   * @copyright GNU General Public License v2.0
   */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "EXCECOESDOSISTEMA.hpp"
#include "sistemaLogin.hpp"
#include "estoque.hpp"

/**
   * @brief Armazena um ponteiro de usúario, e mostra os menus de opções possíveis
   *
   * @details A classe sistema é responsável por inicializar o sistema, sendo assim 
   * ela armazena todas as funções, e chama-as de acordo com os menus de opções correspondentes,
   * ela cria um objeto da classe estoque, para poder fazer as movimentações do funcionário ou gerente
   * além de criar um objeto da classe sistemaLogin, para poder abrir os seus menus
   */


class Sistema{
    private:
  
        ///@brief ponteiro de usuário que está armazendo o usuário logado atualmente no sistema
        Usuario *_usuarioLogado;
  
        ///@brief um objeto da classe sistemaLogin que contem as informações e menus dos logins
        sistemaLogin _sistemaLogin;
  
        ///@brief um obejto da classe estoque que contem as possibilidades de modificações de um determinado produto
        Estoque _estoque;
  
    public:
  
        ///@brief Esta é uma função de construtor, ao qual inicaliza com nenhuma informação
        Sistema() = default; 
  
        ///@brief Esta função inicaliza os parametros do sistema, como ler, e abrir de arquivos txt, chamando as funções correspondentes
        void inicializarParametrosSistema();
  
        ///@brief Esta função salva todos os parametros do sistema, para vários arquivos txt, chamando as funções correspondentes
        void salvarParametrosSistema();
  
        ///@brief Esta função abre o menu de opções possíveis para o gerente
        void opcoesMenuGerente();
  
        ///@brief Esta função abre o menu de opções possíveis da parte administrativas  
        void opcoesMenuAdministrativo();
  
        ///@brief Esta função abre o menu de opções possíveis para o funcionário
        void opcoesMenuFuncionario();
  
        ///@brief Esta função efetua o login no sistema, de acordo com seu usuário e senha
        void efetuarLogin();
  
        ///@brief Esta função inicializa todo o sistema
        void inicializarSistema();
  
        ///@brief Esta função limpa a tela, para poder ter uma melhor visualização na compilação
        ///@param Modo sendo uma conferência se deve ou não perguntar se pode limpar a tela
        void limparTela(string modo);
};

#endif
