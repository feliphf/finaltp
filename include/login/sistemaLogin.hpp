#ifndef SISTEMALOGIN_H
#define SISTEMALOGIN_N

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
#include "gerente.hpp"
#include "funcionario.hpp"
using namespace std;

class sistemaLogin{
    private:
        map<string,Usuario*> _usuarios;
    public:
        void lerArquivo();
        void salvarArquivo(); 
        void cadastrarUsuario(); 
        void excluirUsuario(); 
        void listarUsuarios();
        void alterarUsuario();
        void limparMemoria();
        void limparTela(string modo);
        void fazerLogout(Usuario *u);
        string gerarID(); 
        string gerarDataAtual(); 
        Usuario* menuLogin(); 
        Usuario* pesquisarUsuario(string pesquisa);
        ~sistemaLogin();
};

#endif