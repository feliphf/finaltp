#ifndef LOGINPESSOA_H
#define LOGINPESSOA_H

#include <iostream>

class Loginpessoa
{

public:
    Loginpessoa()=default;
    bool esta_Logado_Gerente();
    bool esta_Logado_Funcionario();
    int _senha;
};

#endif