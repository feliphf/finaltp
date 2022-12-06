#include "doctest.h"
#include "sistemaLogin.hpp"

TEST_CASE("Testando a função de gerar ID") 
{
    sistemaLogin s1;
    string str;
    str = s1.gerarID();
    CHECK (str.size()==4);
}

TEST_CASE("Testando a função de pesquisar usuario") 
{
    sistemaLogin s1;
    s1.lerArquivo();
    Usuario *u = s1.pesquisarUsuario("1542");
    CHECK (u->getNome() == "Yan Figueiras Alves");
}