#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sistema.hpp"

TEST_CASE("Testando a função que inicializa os parâmetros do sistema")
{
    	Sistema sistema;
	CHECK(sistema.inicializarParametrosSsitema());
}

TEST_CASE("Testando a função que salva os parâmetros do sistema") 
{
    	Sistema sistema;
	CHECK(sistema.salvarParametrosSsitema());
}

TEST_CASE("Testando a função de opções do menu do gerente") 
{
    	Sistema sistema;
	CHECK(sistema.opcoesMenuGerente());
}

TEST_CASE("Testando a função de opções do menu administrativo") 
{
    	Sistema sistema;
	CHECK(sistema.opcoesMenuAdministrativo());
}

TEST_CASE("Testando a função de opções do menu do funcionário") 
{
    	Sistema sistema;
	CHECK(sistema.opcoesMenuFuncionario());
}

TEST_CASE("Testando a função de efetuar login no sistema") 
{
    	Sistema sistema;
	CHECK(sistema.efetuarLogin());
}

TEST_CASE("Testando a função de inicializar o sistema") 
{
    	Sistema sistema;
	CHECK(sistema.inicializarSistema());
}

TEST_CASE("Testando a função de limpar a tela") 
{
    	Sistema sistema;
	CHECK(sistema.limparTela("clear"));
	
	Sistema sistema;
	CHECK(sistema.limparTela("perguntar"));
	
	Sistema sistema;
	CHECK(sistema.limparTela("cls"));
}
