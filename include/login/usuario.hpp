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

/**
   * @brief 
   *
   * @details A classe usuario é responsável por
   * 
   *  
   * 
   * 
   */

class Usuario {
    protected:
  
        ///@brief
        string _id;
  
        ///@brief
        string _tipo;
  
        ///@brief
        string _nome;
  
        ///@brief
        string _cpf;
  
        ///@brief
        string _email;
  
        ///@brief
        string _ultimoAcesso;
  
        ///@brief
        string _senha;
  
        ///@brief
        bool _estaAutenticado;
  
    public:
  
        ///@brief 
        ///@return
        string getId();
  
        ///@brief 
        ///@return
        string getTipo();
  
        ///@brief 
        ///@return
        string getNome();
  
        ///@brief 
        ///@return
        string getCpf();
  
        ///@brief 
        ///@return
        string getEmail();
  
        ///@brief 
        ///@return
        string getUltimoAcesso();
  
        ///@brief 
        ///@return
        string getSenha();
  
        ///@brief 
        ///@return
        bool getEstaAutenticado();
  
        ///@brief
        void setId(string s);
  
        ///@brief
        void setTipo(string s);
  
        ///@brief
        void setNome(string s);
  
        ///@brief
        void setCpf(string s);
  
        ///@brief
        void setEmail(string s);
  
        ///@brief
        void setUltimoAcesso(string s);
  
        ///@brief
        void setSenha(string s);
  
        ///@brief
        void setEstaAutenticado(bool b);
  
        ///@brief
        void alterarUsuario();
  
        ///@brief
        virtual void menuAdministrativo() = 0;
  
        ///@brief
        virtual void alterarUsuarioLogado() = 0;
  
        ///@brief
        virtual void menuInicial() = 0;
  
        ///@brief
        virtual bool temPermissao() = 0;
  
        ///@brief
        void limparTela(string modo);
};

#endif
