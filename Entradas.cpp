#include "Produto.hpp"
#include "Entradas.hpp"
#include <iostream>
#include <list>

void Entradas::adicionaProduto(Produto* p){
  entradas.push_back(p);
}

void Entradas::consultarAdicionado (){
  cout << "Último produto adicionado: "<< entradas.back()<<endl;
}
   
