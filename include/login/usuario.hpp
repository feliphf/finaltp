  /**
   * @file usuario.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para armazenamento de todas as informações de cada usuário
   * @version 1.1
   * @date 2022-12-05
   * @details A classe usuário é a mãe de funcionário e gerente, ao qual possui todos os atributos necessários
   * de ambos, ela tem a possibilidade de retornar estas informações como também modifica-las, ao qual serão
   * utilizadas pelas filhas, e pelos menus responsáveis por chama-las 
   * @copyright GNU General Public License v2.0
   */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "EXCECOESDOLOGIN.hpp"
#include "EXCECOESDOESTOQUE.hpp"
using namespace std;

/**
   * @brief Armazena todos os atributos de um determinado usuário
   *
   * @details A classe usuario é responsável por armazenar os atributos necessários
   * para os usuários, ao qual serão necessárias para inicializar o sistema, de acordo 
   * com um usuário específico, esta função dá a possibilidade de alterar e retornar 
   * quaisquer atributos, ela possui funções virtuais, aos quais serão utilizadas pelas filhas
   */

class Usuario {
    protected:
  
        ///@brief Id de um Usuário
        string _id;
  
        ///@brief Tipo de um Usuário
        string _tipo;
  
        ///@brief Nome de um Usuário
        string _nome;
  
        ///@brief CPF de um Usuário
        string _cpf;
  
        ///@brief Email de um Usuário
        string _email;
  
        ///@brief Ultimo acesso de um Usuário
        string _ultimoAcesso;
  
        ///@brief Senha de um Usuário
        string _senha;
  
        ///@brief Autenticação de um Usuário
        bool _estaAutenticado;
  
    public:
  
        ///@brief retorna o id de um Usuário
        ///@return retorna o id de um Usuário
        string getId();
  
        ///@brief retorna o tipo de um Usuário
        ///@return retorna o tipo de um Usuário
        string getTipo();
  
        ///@brief retorna o nome de um Usuário
        ///@return retorna o nome de um Usuário
        string getNome();
  
        ///@brief retorna o CPF de um Usuário
        ///@return retorna o CPF de um Usuário
        string getCpf();
  
        ///@brief retorna o email de um Usuário
        ///@return retorna o email de um Usuário
        string getEmail();
  
        ///@brief retorna o ultimo acesso de um Usuário
        ///@return retorna o ultimo acesso de um Usuário
        string getUltimoAcesso();
  
        ///@brief retorna a senha de um Usuário
        ///@return retorna a senha de um Usuário
        string getSenha();
  
        ///@brief retorna se o usuário está autenticado ou não
        ///@return retorna true ou false se o usuário está autenticado
        bool getEstaAutenticado();
  
        ///@brief Altera o id de um usuário 
        void setId(string s);
  
        ///@brief Altera o tipo de um usuário 
        void setTipo(string s);
  
        ///@brief Altera o nome de um usuário 
        void setNome(string s);
  
        ///@brief Altera o CPF de um usuário 
        void setCpf(string s);
  
        ///@brief Altera o email de um usuário 
        void setEmail(string s);
  
        ///@brief Altera o ultimo aceso de um usuário 
        void setUltimoAcesso(string s);
  
        ///@brief Altera a senha de um usuário 
        void setSenha(string s);
  
        ///@brief Altera a autenticação de um usuário 
        void setEstaAutenticado(bool b);
  
        ///@brief Esta função abre um menu de opções para alterar os atributos acima de um determinado usuário
        void alterarUsuario();
  
        ///@brief Função virtual que abre um  menu administrativo
        virtual void menuAdministrativo() = 0;
  
        ///@brief Função virtual que altera o usuário logado no momento da execução
        virtual void alterarUsuarioLogado() = 0;
  
        ///@brief Função virtual que abre um menu Inicial de um Usuário determinado
        virtual void menuInicial() = 0;
  
        ///@brief Função virtual que retorna se tem permissão ou não
        ///@return Retorna true ou false, de acordo com a permissão do usuário logado
        virtual bool temPermissao() = 0;
  
        ///@brief Esta função limpa a tela, para uma melhor visualização do sistema
        void limparTela(string modo);
};

#endif
