#include "EXCECOESDOSISTEMA.hpp"
#include <string>
#include <iostream>

EscolhaSistemaInvalida::EscolhaSistemaInvalida(){
	mensagem = "Escolha Inválida";	
}

const char* EscolhaSistemaInvalida::what() const throw(){
	return mensagem.c_str();
}
