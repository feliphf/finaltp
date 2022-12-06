#include "EXCECOESDOESTOQUE.hpp"
#include <string>
#include <iostream>

ProdutoNaoCadastrado::ProdutoNaoCadastrado(){
	mensagem = "Produto não localizado no sistema";	
}

const char* ProdutoNaoCadastrado::what() const throw(){
	return mensagem.c_str();
}

PrecoNaoENumero::PrecoNaoENumero(){
	mensagem = "Preço desejado é inválido";	
}

const char* PrecoNaoENumero::what() const throw(){
	return mensagem.c_str();
}

EntradaInvalida::EntradaInvalida(){
	mensagem = "Escolha deseja é inválida";
}

const char* EntradaInvalida::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoNomeAlt::ExcecaoTamanhoNomeAlt(){
	mensagem = "Nome desejado maior que o esperado, o nome deve conter até 26 caracteres";
}

const char* ExcecaoTamanhoNomeAlt::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoFabricAlt::ExcecaoTamanhoFabricAlt(){
	mensagem = "Fabricante desejado maior que o esperado, o fabricante deve conter até 23 caracteres";
}

const char* ExcecaoTamanhoFabricAlt::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoCategAlt::ExcecaoTamanhoCategAlt(){
	mensagem = "Categoria desejada maior que o esperado, a categoria deve conter até 23 caracteres";
}

const char* ExcecaoTamanhoCategAlt::what() const throw(){
	return mensagem.c_str();
}

ExcecaoPrecoNegativoAlt::ExcecaoPrecoNegativoAlt(){
	mensagem = "Preço desejado é inválido";
}

const char* ExcecaoPrecoNegativoAlt::what() const throw(){
	return mensagem.c_str();
}

ProdutoJaCadastrado::ProdutoJaCadastrado(){
	mensagem = "Produto já cadastrado, por favor adicione a quantidade no campo de entradas";
}

const char* ProdutoJaCadastrado::what() const throw(){
	return mensagem.c_str();
}

ProdutoNaoAdicionado::ProdutoNaoAdicionado(){
	mensagem = "Produto não adicionado, quantidade pedida igual a 0";
}

const char* ProdutoNaoAdicionado::what() const throw(){
	return mensagem.c_str();
}

ProdutoNaoRetirado::ProdutoNaoRetirado(){
	mensagem = "Produto não retirado, quantidade pedida igual a 0";
}

const char* ProdutoNaoRetirado::what() const throw(){
	return mensagem.c_str();
}

TentativaDeRetirada::TentativaDeRetirada(){
	mensagem = "Tentativa de retirada abaixo da quantidade disponível em estoque";
}

const char* TentativaDeRetirada::what() const throw(){
	return mensagem.c_str();
}

quantidadeInvalida::quantidadeInvalida(){
	mensagem = "Quantidade inválida! Deve ser um valor positivo.";
}

const char* quantidadeInvalida::what() const throw(){
	return mensagem.c_str();
}