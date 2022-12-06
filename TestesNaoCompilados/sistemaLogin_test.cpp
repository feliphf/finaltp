#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sistemaLogin.hpp"

TEST_CASE("Testando a função que lê aquivo")
{
    sistemaLogin s1;
    CHECK (s1.lerArquivo());
}

TEST_CASE("Testando a função que salva o arquivo") 
{
    sistemaLogin s1;
    CHECK (s1.salvarArquivo());
}

TEST_CASE("Testando a função que cadastra um usuário") 
{
    sistemaLogin s1;
    CHECK (s1.cadastrarUsuario());
}

TEST_CASE("Testando a função que exclui um usuário") 
{
    sistemaLogin s1;
    CHECK (s1.excluirUsuario());
}

TEST_CASE("Testando a função que lista os usuários") 
{
    sistemaLogin s1;
    CHECK (s1.listarUsuarios());
}

TEST_CASE("Testando a função que altera um usuário") 
{
    sistemaLogin s1;
    CHECK (s1.alterarUsuario());
}

TEST_CASE("Testando a função que limpa a memoria") 
{
    sistemaLogin s1;
    CHECK (s1.limparMemoria());
}

TEST_CASE("Testando a função que limpa a tela") 
{	
    sistemaLogin s1;
    CHECK(s1.limparTela("clear"));
	
    sistemaLogin s2
    CHECK(s2.limparTela("perguntar"));
	
    sistemaLogin s3;
    CHECK(s3.limparTela("cls"));
}

TEST_CASE("Testando a função do menu login") 
{
    sistemaLogin s1;
    CHECK (s1.menuLogin());
}
