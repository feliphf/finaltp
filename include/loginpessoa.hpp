#ifndef LOGINPESSOA_H
#define LOGINPESSOA_H

#include <iostream>

class LoginPessoa
{
public:
    int Logar();
    std::string _senha, _senha_Gerente = "123456", _senha_Funcionario = "654321";
    int _chave_acesso = Logar();
};

#endif
