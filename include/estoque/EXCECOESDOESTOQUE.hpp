#ifndef _EXCECOESDOESTOQUE_HPP_
#define _EXCECOESDOESTOQUE_HPP_
#include "exception.hpp"
#include <string>
#include <iostream>

class ProdutoNaoCadastrado : public std::exception{
	private:
		std::string mensagem;
    public:
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

class ExcecaoTamanhoNomeAlt : public std::exception{
	private:
		std::string mensagem;
    public:
		ExcecaoTamanhoNomeAlt();
		virtual const char* what() const throw();
};

class ExcecaoTamanhoFabricAlt : public std::exception{
	private:
		std::string mensagem;
    public:
		ExcecaoTamanhoFabricAlt();
		virtual const char* what() const throw();
};

class ExcecaoTamanhoCategAlt : public std::exception{
	private:
		std::string mensagem;
    public:
		ExcecaoTamanhoCategAlt();
		virtual const char* what() const throw();
};

class ExcecaoPrecoNegativoAlt : public std::exception{
	private:
		std::string mensagem;
    public:
		EntradaInvalida();
		virtual const char* what() const throw();
};

class ProdutoJaCadastrado : public std::exception{
	private:
		std::string mensagem;
    public:
		ProdutoJaCadastrado();
		virtual const char* what() const throw();
};

class ProdutoNaoAdicionado : public std::exception{
	private:
		std::string mensagem;
    public:
		ProdutoNaoAdicionado();
		virtual const char* what() const throw();
};

class ProdutoNaoRetirado : public std::exception{
	private:
		std::string mensagem;
    public:
		ProdutoNaoRetirado();
		virtual const char* what() const throw();
};

class TentativaDeRetirada : public std::exception{
	private:
		std::string mensagem;
    public:
		TentativaDeRetirada();
		virtual const char* what() const throw();
};


#endif
