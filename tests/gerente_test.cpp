#include "doctest.h"
#include "gerente.hpp"

TEST_CASE("Testando a função se o usuário tem permissão para determinadas funções")
{
    Gerente g1 ("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
    CHECK (g1.temPermissao() == true);
}
