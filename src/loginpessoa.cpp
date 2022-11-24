#include "loginpessoa.hpp"

bool LoginPessoa::esta_Logado_Gerente()
{
    if (_senha == 11)
    {
        std::cout << "Voce logou como Gerente!\n";
        return true;
    }
    else
    {
        std::cout << "Login Gerente invalido!\n";
        return false;
    }
}

bool LoginPessoa::esta_Logado_Funcionario()
{
    if (_senha == 10)
    {
        std::cout << "Voce logou como Funcionario!\n";
        return true;
    }
    else
    {
        std::cout << "Login Funcionario invalido!\n";
        return false;
    }
}