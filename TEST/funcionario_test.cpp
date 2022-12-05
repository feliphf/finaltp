#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcionario.hpp"

TEST_CASE("Testando a função menu inicial")
{
    Funcionario f1 ("1029", "Funcionário", "Ana Carolina", "82392354322", "anacarol@gmail.com", "dia 05 de novembro", "239845");
    CHECK (f1.menuInicial());
	
    Funcionario f2 ("2342", "Funcionário", "Gabriel Lage", "47392839273", "bielage@gmail.com", "dia 04 de dezembro", "593023");
    CHECK (f2.menuInicial());
}

TEST_CASE("Testando a função se o usuário tem permissão para determinadas funções") 
{
    Funcionario f1("1029", "Funcionário", "Ana Carolina", "82392354322", "anacarol@gmail.com", "dia 05 de novembro", "239845");
    CHECK (f1.temPermissao() == false);
}
