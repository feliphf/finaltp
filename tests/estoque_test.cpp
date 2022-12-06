#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "estoque.hpp"

TEST_CASE("Testando a função pesquisar produtos") 
{
        Estoque estoque;
	CHECK_THROWS_AS(estoque.pesquisarProduto("1451343"), ProdutoNaoCadastrado);
}

TEST_CASE("Testando a função alterar o nome do produto") 
{
        Estoque estoque1;
        estoque1.lerArquivo();
	CHECK_THROWS_AS(estoque1.alterarNomeProduto("1234567","212"), ProdutoNaoCadastrado);
	CHECK_THROWS_AS(estoque1.alterarNomeProduto("0001","O nome do produto esta acima do limite"), ExcecaoTamanhoNomeAlt);
}

TEST_CASE("Testando a função alterar o fabricante do produto") 
{
        Estoque estoque1;
        estoque1.lerArquivo();
	CHECK_THROWS_AS(estoque1.alterarFabricanteProduto("456789","Channel"), ProdutoNaoCadastrado);
	CHECK_THROWS_AS(estoque1.alterarFabricanteProduto("0001","O fabricante do produto esta acima do limite"), ExcecaoTamanhoFabricAlt);
}



TEST_CASE("Testando a função alterar a categoria do produto") 
{
        Estoque estoque1;
        estoque1.lerArquivo();
	CHECK_THROWS_AS(estoque1.alterarCategoriaProduto("546123","amaderado"), ProdutoNaoCadastrado);
	CHECK_THROWS_AS(estoque1.alterarCategoriaProduto("0001","A categoria do produto esta acima do limite"), ExcecaoTamanhoCategAlt);
}

TEST_CASE("Testando a função alterar o preço do produto") 
{
        Estoque estoque1;
        estoque1.lerArquivo();
	CHECK_THROWS_AS(estoque1.alterarPrecoProduto("789456",100), ProdutoNaoCadastrado);
	CHECK_THROWS_AS(estoque1.alterarPrecoProduto("0001",-1), ExcecaoPrecoNegativoAlt);
}

TEST_CASE("Testando a função excluir cadastro de produto") 
{
    	Estoque estoque;
	CHECK_THROWS_AS(estoque.excluirProduto("123456"),ProdutoNaoCadastrado);
}
