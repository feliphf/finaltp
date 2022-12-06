  /**
   * @file gerente.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para
   * @version 1.1
   * @date 2022-12-05
   * @details 
   *
   * 
   * @copyright GNU General Public License v2.0
   */

#ifndef GERENTE_H
#define GERENTE_H

#include "usuario.hpp"

using namespace std;

/**
   * @brief 
   *
   * @details A classe gerente é responsável por
   * 
   *  
   * 
   * 
   */

class Gerente: public Usuario {
    private:

    public:
  
        ///@brief
        Gerente()=default;
  
        ///@brief
        Gerente(string id, string t, string n, string c, string e, string u, string s);
  
        ///@brief
        void menuInicial() override;
  
        ///@brief
        void menuAdministrativo() override;
  
        ///@brief
        bool temPermissao() override;
  
        ///@brief
        void alterarUsuarioLogado() override;
};


#endif
