#ifndef _EXCECOESDOLOGIN_HPP_
#define _EXCECOESDOLOGIN_HPP_
#include "exception.hpp"
#include <string>
#include <iostream>

using namespace std;

class UsuarioNaoCadastrado : public std::exception{
	private:
		std::string mensagem;
    public:
		UsuarioNaoCadastrado();
		virtual const char* what() const throw();
};

class SenhaIncorreta : public std::exception(){
	private:
		std::string mensagem;
    public:
		SenhaIncorreta();
		virtual const char* what() const throw();
};

class EntradaLoginInvalida : public std::exception(){
	private:
		std::string mensagem;
    public:
		EntradaLoginInvalida();
		virtual const char* what() const throw();
};

class EscolhaInvalida : public std::exception(){
	private:
		std::string mensagem;
    public:
		EscolhaInvalida();
		virtual const char* what() const throw();
};

#endif
