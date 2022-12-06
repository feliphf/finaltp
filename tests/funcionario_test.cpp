#include "doctest.h"
#include "funcionario.hpp"

TEST_CASE("Testando a função se o usuário tem permissão para determinadas funções") 
{
    Funcionario f1("1029", "Funcionário", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
    CHECK (f1.temPermissao() == false);
}

