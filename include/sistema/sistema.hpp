  /**
   * @file sistema.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para
   * @version 1.1
   * @date 2022-12-05
   * @details 
   *
   * 
   * @copyright GNU General Public License v2.0
   */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "EXCECOESDOSISTEMA.hpp"
#include "sistemaLogin.hpp"
#include "estoque.hpp"

/**
   * @brief 
   *
   * @details A classe sistema é responsável por
   * 
   *  
   * 
   * 
   */


class Sistema{
    private:
  
        ///@brief 
        Usuario *_usuarioLogado;
  
        ///@brief 
        sistemaLogin _sistemaLogin;
  
        ///@brief 
        Estoque _estoque;
  
    public:
  
        ///@brief 
        Sistema() = default; 
  
        ///@brief 
        void inicializarParametrosSistema();
  
        ///@brief 
        void salvarParametrosSistema();
  
        ///@brief 
        void opcoesMenuGerente();
  
        ///@brief 
        void opcoesMenuAdministrativo();
  
        ///@brief 
        void opcoesMenuFuncionario();
  
        ///@brief 
        void efetuarLogin();
  
        ///@brief 
        void inicializarSistema();
  
        ///@brief 
        void limparTela(string modo);
};

#endif
