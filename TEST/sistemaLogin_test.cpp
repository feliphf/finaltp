#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sistemaLogin.hpp"

TEST_CASE("Testando a função que lê aquivo")
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

TEST_CASE("Testando a função que salva o arquivo") 
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

TEST_CASE("Testando a função que cadastra um usuário") 
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

TEST_CASE("Testando a função que exclui um usuário") 
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

TEST_CASE("Testando a função que lista os usuários") 
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

TEST_CASE("Testando a função que altera um usuário") 
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

TEST_CASE("Testando a função que limpa a memoria") 
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

TEST_CASE("Testando a função que limpa a tela") 
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

TEST_CASE("Testando a função que faz logout") 
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

TEST_CASE("Testando a função que gera e retorna o id do usuário") 
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

TEST_CASE("Testando a função que gera e retorna a data da movimentação de um usuário") 
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

TEST_CASE("Testando a função do menu login") 
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

TEST_CASE("Testando a função que pesquisa um usuário") 
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