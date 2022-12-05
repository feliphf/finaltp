#include "EXCECOESDOSISTEMA.hpp"
#include <string>
#include <iostream>

EscolhaSistemaInvalida::EscolhaSistemaInvalida(){
	mensagem = "Escolha Inválida";	
}

virtual const char* EscolhaSistemaInvalida::what() const throw() override{
	return mensagem.c_str();
}
