#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "estoque.hpp"

TEST_CASE("Testando a função ler arquivo ") 
{
    Estoque estoque;
	CHECK(estoque.lerArquivo());
}

TEST_CASE("Testando a função salvar arquivo")
{
    Estoque estoque;
	CHECK(estoque.salvarArquivo());
}

TEST_CASE("Testando a função listar produtos") 
{
    	Estoque estoque;
	CHECK(estoque.listarArquivo());
}

TEST_CASE("Testando a função pesquisar produtos") 
{
        Estoque estoque;
	CHECK_THROWS_AS(estoque.pesquisarProduto("1234567"), ProdutoNaoCadastrado);
}

TEST_CASE("Testando a função alterar o nome do produto") 
{
        Estoque estoque1;
	CHECK_THROWS_AS(estoque1.alterarNomeProduto("1234567","212"), ProdutoNaoCadastrado);

        Estoque estoque2;
	CHECK_THROWS_AS(estoque2.alterarNomeProduto("1234567","O nome do produto esta acima do limite"), ExcecaoTamanhoNomeAlt);
}

TEST_CASE("Testando a função alterar o fabricante do produto") 
{
        Estoque estoque;
	CHECK_THROWS_AS(estoque.alterarFabricanteProduto("456789","Channel"), ProdutoNaoCadastrado);
	
        Estoque estoque2;
	CHECK_THROWS_AS(estoque2.alterarFabricanteProduto("456789","O fabricante do produto esta acima do limite"), ExcecaoTamanhoFabricAlt);
}



TEST_CASE("Testando a função alterar a categoria do produto") 
{
        Estoque estoque1;
	CHECK_THROWS_AS(estoque1.alterarCategoriaProduto("546123","amaderado"), ProdutoNaoCadastrado);

        Estoque estoque2;
	CHECK_THROWS_AS(estoque2.alterarCategoriaProduto("546123","A categoria do produto esta acima do limite"), ExcecaoTamanhoCategAlt);
}

TEST_CASE("Testando a função alterar o preço do produto") 
{
        Estoque estoque1;
	CHECK_THROWS_AS(estoque1.alterarPrecoProduto("789456",100), ProdutoNaoCadastrado);

        Estoque estoque2;
	CHECK_THROWS_AS(estoque2.alterarPrecoProduto("789456",-1), ExcecaoPrecoNegativoAlt;
}

TEST_CASE("Testando a função alterar produto") 
{
    	Estoque estoque;
	CHECK(estoque.alterarProduto());
}

TEST_CASE("Testando a função cadastro de produtos") 
{
    	Estoque estoque;
	CHECK(estoque.cadastroDeProdutos());
}

TEST_CASE("Testando a função gerar histórico de movimentação") 
{
    	Estoque estoque;
	CHECK(estoque.gerarLog("alterado por","Ana Carolina","no dia 05 de novembro"));
}

TEST_CASE("Testando a função imprimir histórico de movimentação") 
{
    	Estoque estoque;
	CHECK(estoque.imprimirLog());
}

TEST_CASE("Testando a função limpar a tela") 
{
    	Estoque estoque;
	CHECK(estoque.limparTela("clear"));
	
	Estoque estoque;
	CHECK(estoque.limparTela("perguntar"));
	
	Estoque estoque;
	CHECK(estoque.limparTela("cls"));
}

TEST_CASE("Testando a função excluir cadastro de produto") 
{
    	Estoque estoque;
	CHECK(estoque.excluirProduto("123456"));
}
