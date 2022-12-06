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
        Gerente()=default;
        Gerente(string id, string t, string n, string c, string e, string u, string s);
        void menuInicial() override;
        void menuAdministrativo() override;
        bool temPermissao() override;
        void alterarUsuarioLogado() override;
};


#endif
