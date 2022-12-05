#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "produto.hpp"

TEST_CASE("Testando a função retornar nome do produto")
{
    Produto p1("luna", "natura", "amadeirado", "347", 73, 1);
    CHECK(p1.getNome() == 'luna');

    Produto p2("floratta", "boticario", "citrico", "765", 112, 2);
    CHECK(p2.getNome() == 'floratta');
}

TEST_CASE("Testando a função retornar fabricante do produto") 
{
    Produto p1("luna", "natura", "amadeirado", "347", 79, 1);
    CHECK(p1.getFabricante() == 'natura');

    Produto p2("floratta", "boticario", "citrico", "765", 119, 2);
    CHECK(p2.getFabricante() == 'boticario');
}

TEST_CASE("Testando a função retornar categoria do produto") 
{
    Produto p1("luna", "natura", "amadeirado", "347", 79, 1);
    CHECK(p1.getCategoria() == 'amadeirado');

    Produto p2("floratta", "boticario", "citrico", "765", 119, 2);
    CHECK(p2.getCategoria() == 'citrico');
}

TEST_CASE("Testando a função retornar código do produto") 
{
    Produto p1("luna", "natura", "amadeirado", "347", 79, 1);
    CHECK(p1.getCodigo() == '347');

    Produto p2("floratta", "boticario", "citrico", "765", 119, 2);
    CHECK(p2.getCodigo() == '765');
}

TEST_CASE("Testando a função retornar preço do produto") 
{
    Produto p1("luna", "natura", "amadeirado", "347", 79, 1);
    CHECK(p1.getPreco() == 79);

    Produto p2("floratta", "boticario", "citrico", "765", 119, 2);
    CHECK(p2.getPreco() == 119);
}

TEST_CASE("Testando a função retornar quantidade do produto") 
{
    Produto p1("luna", "natura", "amadeirado", "347", 79, 1);
    CHECK(p1.getQuantidade() == 1);

    Produto p2("floratta", "boticario", "citrico", "765", 119, 2);
    CHECK(p2.getQuantidade() == 2);
}

TEST_CASE("Testando a função que altera o fabricante do produto") 
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

TEST_CASE("Testando a função que altera a categoria do produto") 
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

TEST_CASE("Testando a função que altera o código do produto") 
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

TEST_CASE("Testando a função que altera a quantidade do produto") 
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

TEST_CASE("Testando a função que altera o preço do produto") 
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
