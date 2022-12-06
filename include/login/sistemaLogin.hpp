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
        map<string,Usuario*> _usuarios;
    public:
        void lerArquivo();
        void salvarArquivo(); 
        void cadastrarUsuario(); 
        void excluirUsuario(); 
        void listarUsuarios();
        void alterarUsuario();
        void limparMemoria();
        void limparTela(string modo);
        void fazerLogout(Usuario *u);
        string gerarID(); 
        string gerarDataAtual(); 
        Usuario* menuLogin(); 
        Usuario* pesquisarUsuario(string pesquisa);
};

#endif
