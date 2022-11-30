#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "LoginPessoa.hpp"

class Funcionario : public LoginPessoa
{

public:
    bool esta_Logado();
};

#endif
