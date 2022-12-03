#include "EXCECOESDOESTOQUE.hpp"
#include <string>
#include <iostream>

using namespace std;

ProdutoNaoCadastrado::ProdutoNaoCadastrado(){
	mensagem = "Produto não cadastrado";	
}

virtual const char* ProdutoNaoCadastrado::what() const throw(){
	return mensagem.c_str();
}

PrecoNaoENumero::PrecoNaoENumero(){
	mensagem = "Preço selecionado para alteração não é válido";	
}

virtual const char* PrecoNaoENumero::what() const throw(){
	return mensagem.c_str();
}

EntradaInválida::EntradaInvalida(){
	mensagem = "Entrada inválida, digite um número de 1 a 5";
}

virtual const char* EntradaInvalida::what() const throw(){
	return mensagem.c_str();
}

