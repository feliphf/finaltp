#include "funcionario.hpp"

bool Funcionario::esta_Logado()
{
    if (_chave_acesso == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
