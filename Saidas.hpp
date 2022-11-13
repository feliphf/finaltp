#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <iostream>
#include <list>

#include "Produto.hpp"

class Saidas {
private:
    
  std::list<Produto*> saidas;
  
public:

  void retiraProduto(Produto* p);
  std::list getSaida();  
  std::string consultarRetirados (int codigo);
  
};
#endif
