#include "doctest.h"
#include "usuario.hpp"
#include "gerente.hpp"
#include "funcionario.hpp"

TEST_CASE("Testando a função retornar e setar o id do usuário")
{
    Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setId("1234");
	CHECK(u->getId()=="1234");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setId("4321");
	CHECK(u2->getId()=="4321");
}

TEST_CASE("Testando a função retornar e setar o tipo do usuário") 
{
    Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setTipo("Funcionario");
	CHECK(u->getTipo()=="Funcionario");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setTipo("Gerente");
	CHECK(u2->getTipo()=="Gerente");
}

TEST_CASE("Testando a função retornar e setar o nome do usuário") 
{
    Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setNome("Ana_Carolina_Lima");
	CHECK(u->getNome()=="Ana Carolina Lima");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setNome("Guilherme_de_Souza");
	CHECK(u2->getNome()=="Guilherme de Souza");
}

TEST_CASE("Testando a função retornar e setar o CPF do usuário") 
{
    Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setCpf("49562799916");
	CHECK(u->getCpf()=="49562799916");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setCpf("111.111.111-12");
	CHECK(u2->getCpf()=="111.111.111-12");
}

TEST_CASE("Testando a função retornar e setar o email do usuário") 
{
    Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setEmail("anapat@gmail.com");
	CHECK(u->getEmail()=="anapat@gmail.com");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setEmail("vinicius@gmail.com");
	CHECK(u2->getEmail()=="vinicius@gmail.com");
}

TEST_CASE("Testando a função retornar e setar o ultimo acesso do usuário") 
{
    Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setUltimoAcesso("06/12/2022");
	CHECK(u->getUltimoAcesso()=="06/12/2022");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setUltimoAcesso("06/12/2022");
	CHECK(u2->getUltimoAcesso()=="06/12/2022");
}

TEST_CASE("Testando a função retornar e setar a senha do usuário") 
{
	Usuario *u = new Gerente("1029", "Gerente", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setSenha("251436");
	CHECK(u->getSenha()=="251436");
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setSenha("584769");
	CHECK(u2->getSenha()=="584769");
}

TEST_CASE("Testando a função retornar se o usuário está autenticado ou não") 
{
    Usuario *u = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u->setEstaAutenticado(true);
	CHECK(u->getEstaAutenticado());
    
    Usuario *u2 = new Funcionario("1029", "Funcionario", "Ana Carolina", "111.111.111-11", "anacarol@gmail.com", "05/12/2022", "1");
	u2->setEstaAutenticado(false);
	CHECK((u2->getEstaAutenticado())==false);
}


