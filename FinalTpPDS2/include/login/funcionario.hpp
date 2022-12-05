#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "usuario.hpp"

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