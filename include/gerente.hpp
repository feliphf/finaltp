#ifndef GERENTE_H
#define GERENTE_H

#include "loginpessoa.hpp"

class Gerente : public Loginpessoa
{

public:
    Gerente (int _senha_digitada);
};

#endif