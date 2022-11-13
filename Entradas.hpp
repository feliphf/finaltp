#ifndef ENTRADAS.HPP
#define ENTRADAS.HPP
#include "Produto.hpp"
#include <iostream>

class Produto{
  private:
  
  std::list <Produto*> entradas;
  
  public:
  
  void adicionaProduto(Produto* p);
  std::list getEntrada(); 
  std::string consultarAdicionados (int codigo);
    
};
#endif;
