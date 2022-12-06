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

ExcecaoTamanhoCPF::ExcecaoTamanhoCPF(){
	mensagem = "CPF maior que o esperado, digite na formatação XXX.XXX.XXX-XX";
}
const char* ExcecaoTamanhoCPF::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoEmail::ExcecaoTamanhoEmail(){
	mensagem = "Email maior que o esperado, o email deve conter até 28 caracteres";
}
const char* ExcecaoTamanhoCPF::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoSenha::ExcecaoTamanhoSenha(){
	mensagem = "Senha maior que a esperada, o limite é de 6 dígitos";
}
const char* ExcecaoTamanhoSenha::what() const throw(){
	return mensagem.c_str();
}