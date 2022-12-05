#include "EXCECOESDOESTOQUE.hpp"
#include <string>
#include <iostream>

ProdutoNaoCadastrado::ProdutoNaoCadastrado(){
	mensagem = "Produto não localizado no sistema";	
}

virtual const char* ProdutoNaoCadastrado::what() const throw() override{
	return mensagem.c_str();
}

PrecoNaoENumero::PrecoNaoENumero(){
	mensagem = "Preço desejado é inválido";	
}

virtual const char* PrecoNaoENumero::what() const throw() override{
	return mensagem.c_str();
}

EntradaInvalida::EntradaInvalida(){
	mensagem = "Escolha deseja é inválida";
}

virtual const char* EntradaInvalida::what() const throw() override{
	return mensagem.c_str();
}

ExcecaoTamanhoNomeAlt::ExcecaoTamanhoNomeAlt(){
	mensagem = "Nome desejado maior que o esperado, o nome deve conter até 20 caracteres";
}

virtual const char* ExcecaoTamanhoNomeAlt::what() const throw() override{
	return mensagem.c_str();
}

ExcecaoTamanhoFabricAlt::ExcecaoTamanhoFabricAlt(){
	mensagem = "Fabricante desejado maior que o esperado, o fabricante deve conter até 20 caracteres";
}

virtual const char* ExcecaoTamanhoFabricAlt::what() const throw() override{
	return mensagem.c_str();
}

ExcecaoTamanhoCategAlt::ExcecaoTamanhoCategAlt(){
	mensagem = "Categoria desejada maior que o esperado, a categoria deve conter até 20 caracteres";
}

virtual const char* ExcecaoTamanhoCategAlt::what() const throw() override{
	return mensagem.c_str();
}

ExcecaoPrecoNegativoAlt::ExcecaoPrecoNegativoAlt(){
	mensagem = "Preço desejado é inválido";
}

virtual const char* ExcecaoPrecoNegativoAlt::what() const throw() override{
	return mensagem.c_str();
}

ProdutoJaCadastrado::ProdutoJaCadastrado(){
	mensagem = "Produto já cadastrado, por favor adicione a quantidade no campo de entradas";
}

virtual const char* ProdutoJaCadastrado::what() const throw() override{
	return mensagem.c_str();
}

ProdutoNaoAdicionado::ProdutoNaoAdicionado(){
	mensagem = "Produto não adicionado, quantidade pedida igual a 0";
}

virtual const char* ProdutoNaoAdicionado::what() const throw() override{
	return mensagem.c_str();
}

ProdutoNaoRetirado::ProdutoNaoRetirado(){
	mensagem = "Produto não retirado, quantidade pedida igual a 0";
}

virtual const char* ProdutoNaoRetirado::what() const throw() override{
	return mensagem.c_str();
}

TentativaDeRetirada::TentativaDeRetirada(){
	mensagem = "Tentativa de retirada abaixo da quantidade disponível em estoque";
}

virtual const char* TentativaDeRetirada::what() const throw() override{
	return mensagem.c_str();
}
