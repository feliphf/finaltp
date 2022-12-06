  /**
   * @file usuario.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para
   * @version 1.1
   * @date 2022-12-05
   * @details 
   *
   * 
   * @copyright GNU General Public License v2.0
   */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "EXCECOESDOLOGIN.hpp"
using namespace std;

class Usuario {
    protected:
        string _id;
        string _tipo;
        string _nome;
        string _cpf;
        string _email;
        string _ultimoAcesso;
        string _senha;
        bool _estaAutenticado;
    public:
        string getId();
        string getTipo();
        string getNome();
        string getCpf();
        string getEmail();
        string getUltimoAcesso();
        string getSenha();
        bool getEstaAutenticado();
        void setId(string s);
        void setTipo(string s);
        void setNome(string s);
        void setCpf(string s);
        void setEmail(string s);
        void setUltimoAcesso(string s);
        void setSenha(string s);
        void setEstaAutenticado(bool b);
        void alterarUsuario();
        virtual void menuAdministrativo() = 0;
        virtual void alterarUsuarioLogado() = 0;
        virtual void menuInicial() = 0;
        virtual bool temPermissao() = 0;
        void limparTela(string modo);
};

#endif
