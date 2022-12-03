#ifndef _EXCECOESDOSISTEMA_HPP_
#define _EXCECOESDOSISTEMA_HPP_
#include "exception.hpp"
#include <string>
#include <iostream>

class EscolhaSistemaInvalida : public std::exception{
	private:
		std::string mensagem;
  public:
		EscolhaSistemaInvalida();
		virtual const char* what() const throw();
};

#endif
