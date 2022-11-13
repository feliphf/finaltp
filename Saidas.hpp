#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <iostream>
#include <list>

#include "produto.hpp"


class Saidas {
private:
    
  std::list<Produto*> saidas;
  
public:

  void retiraProduto(Produto* p);
  
};
#endif
