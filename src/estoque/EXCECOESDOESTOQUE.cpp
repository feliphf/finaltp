#ifndef _EXCECOESDOESTOQUE_HPP_
#define _EXCECOESDOESTOQUE_HPP_
#include "exception.hpp"
#include <string>
#include <iostream>

using namespace std;

class ProdutoNaoCadastrado : public std::exception{
	private:
		string mensagem;
    public:,
		ProdutoNaoCadastrado();
		virtual const char* what() const throw();
};

class PrecoNaoENumero : public std::exception{
	private:
		std::string mensagem;
    public:
		PrecoNaoENumero();
		virtual const char* what() const throw();
};

class EntradaInvalida : public std::exception{
	private:
		std::string mensagem;
    public:
		EntradaInvalida();
		virtual const char* what() const throw();
};

#endif
