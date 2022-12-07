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
        ///@details inicializa um estoque default, sem nenhum parametro.
        Sistema() = default; 
  
        ///@brief Esta função inicaliza os parametros do sistema, como ler, e abrir de arquivos txt, chamando as funções correspondentes
        /// @details chama a função de ler arquivos do subsistema de login e do estoque, para garantir que toda vez 
        /// que o sistema é inicializado os mapas de usuarios (presente no login) e mapa de produtos (presente no estoque)
        /// estejam já com os devidos objetos instanciados
        void inicializarParametrosSistema();
  
        ///@brief Esta função salva todos os parametros do sistema, para vários arquivos txt, chamando as funções correspondentes
        /// @details chama a função de salvar arquivos do subsistema de login e do estoque, para garantir que toda vez 
        /// que o sistema quiser salvar os mapas de usuários (presente no login) e mapa de produtos (presente no estoque)
        /// nos arquivos novamente (geralmente quando volta ao menu principal) os objetos instânciados nos mapas sejam os mesmos
        /// dos gravados no arquivo
        void salvarParametrosSistema();
  
        ///@brief Esta função abre o menu de opções possíveis para o gerente
        /// @details Através do _usuarioLogado e utilizando o polimorfismo da classe usuário, a função chama o menu principal
        /// através do usuário logado no sistema e depois lança um switch case para captar todas as possíveis funções para esse menu
        void opcoesMenuGerente();
  
        ///@brief Esta função abre o menu de opções possíveis da parte administrativas
        /// @details Através do _usuarioLogado e utilizando o polimorfismo da classe usuário, a função chama o menu administrativo
        /// através do usuário logado no sistema e depois lança um switch case para captar todas as possíveis funções para esse menu
        void opcoesMenuAdministrativo();
  
        ///@brief Esta função abre o menu de opções possíveis para o funcionário
        /// @details Através do _usuarioLogado e utilizando o polimorfismo da classe usuário, a função chama o menu principal
        /// através do usuário logado no sistema e depois lança um switch case para captar todas as possíveis funções para esse menu
        void opcoesMenuFuncionario();
  
        ///@brief Esta função efetua o login no sistema, de acordo com seu usuário e senha
        /// @details Efetua o login para o atributo _usuarioLogado chamando a função menuLogin do subsistema de login. Uma vez chamada 
        /// essa função, o sistema entra em um loop infinito até o usuário ser logado, ou seja _usuarioLogado != nullptr, ou até o usuário
        /// encerrar a execução do programa selecinando a opção 2.
        void efetuarLogin();
  
        ///@brief Esta função inicializa todo o sistema
        /// @details Esta função é a principal, em que a main irá instânciar um objeto do sistema e chamar apenas uma vez. Ela entra em um loop
        /// infinito enquanto o usuário deseje que o programa continue o funcionando, também é responsável por chamar funções de menu principal,
        /// gerir permissões, inicializar arquivos dos subsistemas e salvá-los também
        void inicializarSistema();
  
        ///@brief Esta função limpa a tela, para poder ter uma melhor visualização na compilação
        ///@details recurso visual para melhor vizualização e interação do usuário, possui modo "perguntar" em que pergunta se pode limpar a
        /// tela antes de limpar, e modo "continuar" em que limpa direto sem perguntar
        ///@param Modo sendo uma conferência se deve ou não perguntar se pode limpar a tela
        void limparTela(string modo);
};

#endif
