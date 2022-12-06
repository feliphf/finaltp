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

class Sistema{
    private:
        Usuario *_usuarioLogado;
        sistemaLogin _sistemaLogin;
        Estoque _estoque;
    public:
        Sistema() = default;    
        void inicializarParametrosSistema();
        void salvarParametrosSistema();
        void opcoesMenuGerente();
        void opcoesMenuAdministrativo();
        void opcoesMenuFuncionario();
        void efetuarLogin();
        void inicializarSistema();
        void limparTela(string modo);
};

#endif
