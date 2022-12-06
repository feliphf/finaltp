  /**
   * @file funcionario.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para
   * @version 1.1
   * @date 2022-12-05
   * @details 
   *
   * 
   * @copyright GNU General Public License v2.0
   */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "usuario.hpp"
#include "EXCECOESDOLOGIN.hpp"

using namespace std;

/**
   * @brief 
   *
   * @details A classe funcionario é responsável por
   * 
   *  
   * 
   * 
   */

class Funcionario: public Usuario {
    private:
    public:
  
        ///@brief
        Funcionario(string id, string t, string n, string c, string e, string u, string s);
  
        ///@brief
        void menuInicial() override;
  
        ///@brief
        void menuAdministrativo() override;
  
        ///@brief
        ///@return Retorna se
        bool temPermissao() override;
  
        ///@brief
        void alterarUsuarioLogado() override;
};


#endif
