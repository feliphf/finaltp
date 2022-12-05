#include "EXCECOESDOLOGIN.hpp"
#include <string>
#include <iostream>

UsuarioNaoCadastrado::UsuarioNaoCadastrado(){
	mensagem = "Usuário não cadastrado";	
}

virtual const char* UsuarioNaoCadastrado::what() const throw() override{
	return mensagem.c_str();
}

SenhaIncorreta::SenhaIncorreta(){
	mensagem = "Senha Incorreta";	
}

virtual const char* SenhaIncorreta::what() const throw() override{
	return mensagem.c_str();
}

EscolhaInvalida::EscolhaInvalida(){
	mensagem = "Escolha Inválida";	
}

virtual const char* EscolhaInvalida::what() const throw() override{
	return mensagem.c_str();
}
