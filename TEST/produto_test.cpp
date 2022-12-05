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

TEST_CASE("Testando a função que altera o nome do produto") 
{
    Produto p1;
    p1.setNome ("malbec");
    CHECK (p1.getNome() == 'malbec');
	
    Produto p2;
    p2.setNome ("egeo");
    CHECK (p2.getNome() == 'egeo');
}

TEST_CASE("Testando a função que altera o fabricante do produto") 
{
    Produto p1;
    p1.setFabricante ("avon");
    CHECK (p1.getFabricante() == 'avon');
	
    Produto p2;
    p2.setFabricante ("natura");
    CHECK (p2.getFabricante() == 'natura');
}

TEST_CASE("Testando a função que altera a categoria do produto") 
{
    Produto p1;
    p1.setCategoria ("doce");
    CHECK (p1.getCategoria() == 'doce');
	
    Produto p2;
    p2.setCategoria ("intenso");
    CHECK (p2.getCategoria() == 'intenso');
}

TEST_CASE("Testando a função que altera o código do produto") 
{
    Produto p1;
    p1.setCodigo ("973");
    CHECK (p1.getCodigo() == '973');
	
    Produto p2;
    p2.setCodigo ("192");
    CHECK (p2.getCodigo() == '192');
}

TEST_CASE("Testando a função que altera o preço do produto") 
{
    Produto p1;
    p1.setPreco ("180");
    CHECK (p1.getPreco() == '180');
	
    Produto p2;
    p2.setPreco ("110");
    CHECK (p2.getPreco() == '110');
}

TEST_CASE("Testando a função que altera a quantidade do produto") 
{
    Produto p1;
    p1.setQuantidade ("3");
    CHECK (p1.getQuantidade() == '3');
	
    Produto p2;
    p2.setQuantidade ("2");
    CHECK (p2.getQuantidade() == '2');
}

