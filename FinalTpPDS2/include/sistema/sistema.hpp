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