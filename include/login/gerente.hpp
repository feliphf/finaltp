#ifndef GERENTE_H
#define GERENTE_H

#include "usuario.hpp"

using namespace std;

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