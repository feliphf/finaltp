#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "loginpessoa.hpp"

class Funcionario : public Loginpessoa
{
    
public:
    Funcionario (int _senha_digitada);
};

#endif