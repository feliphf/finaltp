#ifndef _EXCECOESDOLOGIN_HPP_
#define _EXCECOESDOLOGIN_HPP_
#include <string>
#include <iostream>

class UsuarioNaoCadastrado : public std::exception{
	private:
		std::string mensagem;
    	public:
		UsuarioNaoCadastrado();
		virtual const char* what() const throw();
};

class SenhaIncorreta : public std::exception{
	private:
		std::string mensagem;
    	public:
		SenhaIncorreta();
		virtual const char* what() const throw() override;
};

class EscolhaInvalida : public std::exception{
	private:
		std::string mensagem;
    	public:
		EscolhaInvalida();
		virtual const char* what() const throw() override;
};

#endif
