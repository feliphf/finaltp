#include "Produto.hpp"
#include "Entradas.hpp"
#include <iostream>
#include <list>

void Entradas::adiciona_produto(Produto* p){
  entradas.push_back(p);
}

void Entradas::consultar_adicionado(){
  std::cout << "Último produto adicionado: "<< entradas.back()<<endl;
}
   
