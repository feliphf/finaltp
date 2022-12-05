#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sistema.hpp"

TEST_CASE("Testando a função que inicializa os parâmetros do sistema")
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

TEST_CASE("Testando a função que salva os parâmetros do sistema") 
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

TEST_CASE("Testando a função de opções do menu do gerente") 
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

TEST_CASE("Testando a função de opções do menu administrativo") 
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

TEST_CASE("Testando a função de opções do menu do funcionário") 
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

TEST_CASE("Testando a função de efetuar login no sistema") 
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

TEST_CASE("Testando a função de inicializar o sistema") 
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

TEST_CASE("Testando a função de limpar a tela") 
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