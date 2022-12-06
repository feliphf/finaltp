#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "usuario.hpp"

TEST_CASE("Testando a função retornar e setar o id do usuário")
{
    	Usuario usuario1;
	usuario1.setId("1234");
	CHECK(usuario1.getId()=="1234");
    
    	Usuario usuario2;
	usuario2.setId("4321");
	CHECK(usuario2.getId()=="4321");
}

TEST_CASE("Testando a função retornar e setar o tipo do usuário") 
{
    	Usuario usuario1;
	usuario1.setTipo("funcionário");
	CHECK(usuario1.getTipo()=="funcionário");
    
    	Usuario usuario2;
	usuario2.setTipo("gerente");
	CHECK(usuario2.getTipo()=="gerente");
}

TEST_CASE("Testando a função retornar e setar o nome do usuário") 
{
    	Usuario usuario1;
	usuario1.setNome("Ana_Carolina_Lima");
	CHECK(usuario1.getNome()=="Ana Carolina Lima");
    
    	Usuario usuario2;
	usuario2.setNome("Guilherme_de_Souza");
	CHECK(usuario2.getNome()=="Guilherme de Souza");
}

TEST_CASE("Testando a função retornar e setar o CPF do usuário") 
{
    	Usuario usuario1;
	usuario1.setCpf("49562799916");
	CHECK(usuario1.getCpf()=="49562799916");
    
    	Usuario usuario2;
	usuario2.setCpf("70545688857");
	CHECK(usuario2.getCpf()=="70545688857");
}

TEST_CASE("Testando a função retornar e setar o email do usuário") 
{
    	Usuario usuario1;
	usuario1.setEmail("anapat@gmail.com");
	CHECK(usuario1.getEmail()=="anapat@gmail.com");
    
    	Usuario usuario2;
	usuario2.setEmail("vinicius@gmail.com");
	CHECK(usuario2.getEmail()=="vinicius@gmail.com");
}

TEST_CASE("Testando a função retornar e setar o ultimo acesso do usuário") 
{
    	Usuario usuario1;
	usuario1.setUltimoAcesso("dia 05 de novembro");
	CHECK(usuario1.getUltimoAcesso()=="dia 05 de novembro");
    
    	Usuario usuario2;
	usuario2.setUltimoAcesso("dia 14 de outubro");
	CHECK(usuario2.getUltimoAcesso()=="dia 14 de outubro");
}

TEST_CASE("Testando a função retornar e setar a senha do usuário") 
{
    	Usuario usuario1;
	usuario1.setSenha("251436");
	CHECK(usuario1.getSenha()=="251436");
    
    	Usuario usuario2;
	usuario2.setSenha("584769");
	CHECK(usuario2.getSenha()=="584769");
}

TEST_CASE("Testando a função retornar se o usuário está autenticado ou não") 
{
    	Usuario usuario1;
	usuario1.setEstaAutenticado(true);
	CHECK(usuario1.getEmail()==true);
    
    	Usuario usuario2;
	usuario2.setEmail(false);
	CHECK(usuario2.getEmail()==false);
}

TEST_CASE("Testando a função que limpa a tela") 
{
    	Estoque estoque;
	CHECK(estoque.limparTela("clear"));
	
	Estoque estoque;
	CHECK(estoque.limparTela("perguntar"));
	
	Estoque estoque;
	CHECK(estoque.limparTela("cls"));
}

