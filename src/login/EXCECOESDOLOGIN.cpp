#include "EXCECOESDOLOGIN.hpp"
#include <string>
#include <iostream>

UsuarioNaoCadastrado::UsuarioNaoCadastrado(){
	mensagem = "Usuário não cadastrado";	
}

const char* UsuarioNaoCadastrado::what() const throw(){
	return mensagem.c_str();
}

SenhaIncorreta::SenhaIncorreta(){
	mensagem = "Senha Incorreta";	
}

const char* SenhaIncorreta::what() const throw(){
	return mensagem.c_str();
}

EscolhaInvalida::EscolhaInvalida(){
	mensagem = "Escolha Inválida";	
}

const char* EscolhaInvalida::what() const throw(){
	return mensagem.c_str();
}
