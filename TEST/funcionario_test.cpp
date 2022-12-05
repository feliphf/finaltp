#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcionario.hpp"

TEST_CASE("Testando a função menu inicial")
{
    //EXEMPLOS DE 3 CHECAGENS
    Triangle t1(3,2,2);
    CHECK(t1.getPerimeter()==7);

    Usuario usuario = Usuario();
	usuario.setCpf("12341234123");
	usuario.setSenha("senha");
	CHECK(usuario.login());
    
    Usuario usuario = Usuario();
	usuario.setCpf("32132132132");
	usuario.setSenha("senha");
	CHECK_THROWS_AS(usuario.login(), UsuarioNaoEncontradoException);
}

TEST_CASE("Testando a função se o usuário tem permissão para determinadas funções") 
{
    //EXEMPLOS DE 3 CHECAGENS
    Triangle t1(3,2,2);
    CHECK(t1.getPerimeter()==7);

    Usuario usuario = Usuario();
	usuario.setCpf("12341234123");
	usuario.setSenha("senha");
	CHECK(usuario.login());
    
    Usuario usuario = Usuario();
	usuario.setCpf("32132132132");
	usuario.setSenha("senha");
	CHECK_THROWS_AS(usuario.login(), UsuarioNaoEncontradoException);
}

TEST_CASE("Testando a função que altera o usuário logado") 
{
    //EXEMPLOS DE 3 CHECAGENS
    Triangle t1(3,2,2);
    CHECK(t1.getPerimeter()==7);

    Usuario usuario = Usuario();
	usuario.setCpf("12341234123");
	usuario.setSenha("senha");
	CHECK(usuario.login());
    
    Usuario usuario = Usuario();
	usuario.setCpf("32132132132");
	usuario.setSenha("senha");
	CHECK_THROWS_AS(usuario.login(), UsuarioNaoEncontradoException);
}