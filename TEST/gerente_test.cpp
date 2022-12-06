#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gerente.hpp"

TEST_CASE("Testando a função de menu inicial")
{   
    Gerente g1 ("1029", "Gerente", "Ana Carolina", "82392354322", "anacarol@gmail.com", "dia 04 de dezembro", "239845");
    CHECK (g1.menuInicial());
}

TEST_CASE("Testando a função de menu administrativo")
{
    Gerente g1 ("1029", "Gerente", "Ana Carolina", "82392354322", "anacarol@gmail.com", "dia 04 de dezembro", "239845");
    CHECK (g1.menuAdministrativo());
}

TEST_CASE("Testando a função se o usuário tem permissão para determinadas funções")
{
    Gerente g1 ("1029", "Gerente", "Ana Carolina", "82392354322", "anacarol@gmail.com", "dia 04 de dezembro", "239845");
    CHECK (g1.temPermissao() == true);
}

TEST_CASE("Testando a função que altera o usuário logado")
{
    Gerente g1 ("1029", "Gerente", "Ana Carolina", "82392354322", "anacarol@gmail.com", "dia 04 de dezembro", "239845");
    CHECK (g1.alterarUsuarioLogado());
}
