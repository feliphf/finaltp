  /**
   * @file sistemaLogin.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para
   * @version 1.1
   * @date 2022-12-05
   * @details 
   *
   * 
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
   * @brief 
   *
   * @details A classe sistemaLogin é responsável por
   * 
   *  
   * 
   * 
   */


class sistemaLogin{
    private:
  
        ///@brief
        map<string,Usuario*> _usuarios;
  
    public:
  
        ///@brief
        void lerArquivo();
  
        ///@brief
        void salvarArquivo();
  
        ///@brief
        void cadastrarUsuario();
  
        ///@brief
        void excluirUsuario();
  
        ///@brief
        void listarUsuarios();
  
        ///@brief
        void alterarUsuario();
  
        ///@brief
        void limparMemoria();
  
        ///@brief
        void limparTela(string modo);
  
        ///@brief
        void fazerLogout(Usuario *u);
  
        ///@brief
        ///@return
        string gerarID();
  
        ///@brief
        ///@return
        string gerarDataAtual();
  
        ///@brief
        ///@return
        Usuario* menuLogin();
  
        ///@brief
        ///@return
        Usuario* pesquisarUsuario(string pesquisa);
};

#endif
