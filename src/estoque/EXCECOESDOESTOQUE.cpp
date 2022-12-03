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
	mensagem = "Preço inválido, digite novamente";	
}

virtual const char* PrecoNaoENumero::what() const throw(){
	return mensagem.c_str();
}

EntradaInvalida::EntradaInvalida(){
	mensagem = "Escolha inválida, digite novamente";
}

virtual const char* EntradaInvalida::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoNomeAlt::ExcecaoTamanhoNomeAlt(){
	mensagem = "Nome escolhido maior que o esperado, digite novamente o nome que deseja, com até 20 caracteres";
}

virtual const char* ExcecaoTamanhoNomeAlt::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoFabricAlt::ExcecaoTamanhoFabricAlt(){
	mensagem = "Fabricante escolhido maior que o esperado, digite novamente o fabricante que deseja, com até 20 caracteres";
}

virtual const char* ExcecaoTamanhoFabricAlt::what() const throw(){
	return mensagem.c_str();
}

ExcecaoTamanhoCategAlt::ExcecaoTamanhoCategAlt(){
	mensagem = "Categoria escolhida maior que o esperado, digite novamente a categoria que deseja, com até 20 caracteres";
}

virtual const char* ExcecaoTamanhoCategAlt::what() const throw(){
	return mensagem.c_str();
}

ExcecaoPrecoNegativoAlt::ExcecaoPrecoNegativoAlt(){
	mensagem = "Preço inválido, digite novamente";
}

virtual const char* ExcecaoPrecoNegativoAlt::what() const throw(){
	return mensagem.c_str();
}

ProdutoJaCadastrado::ProdutoJaCadastrado(){
	mensagem = "Produto já cadastrado, por favor adicione a quantidade no campo de entradas";
}

virtual const char* ProdutoJaCadastrado::what() const throw(){
	return mensagem.c_str();
}

ProdutoNaoAdicionado::ProdutoNaoAdicionado(){
	mensagem = "Produto não adicionado, quantidade pedida igual a 0";
}

virtual const char* ProdutoNaoAdicionado::what() const throw(){
	return mensagem.c_str();
}

ProdutoNaoRetirado::ProdutoNaoRetirado(){
	mensagem = "Produto não retirado, quantidade pedida igual a 0";
}

virtual const char* ProdutoNaoRetirado::what() const throw(){
	return mensagem.c_str();
}

TentativaDeRetirada::TentativaDeRetirada(){
	mensagem = "Tentativa de retirada abaixo da quantidade disponível em estoque";
}

virtual const char* TentativaDeRetirada::what() const throw(){
	return mensagem.c_str();
}
