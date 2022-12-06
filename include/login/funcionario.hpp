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

class Funcionario: public Usuario {
    private:
    public:
        Funcionario(string id, string t, string n, string c, string e, string u, string s);
        void menuInicial() override;
        void menuAdministrativo() override;
        bool temPermissao() override;
        void alterarUsuarioLogado() override;
};


#endif
