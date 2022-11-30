#include "gerente.hpp"

bool Gerente::esta_Logado()
{
    if (_chave_acesso == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
