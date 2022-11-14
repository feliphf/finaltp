#include "produto.hpp"
#include "saidas.hpp"
#include <iostream>
#include <list>
  
void Saidas::retira_produto(Produto* p){
  saidas.push_back(p);
}
 
void Saidas::consultar_retirado(){
  std::cout << "Último produto retirado: "<< saidas.back()<<endl;
}
