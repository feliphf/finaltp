#include "Produto.hpp"
#include "Saidas.hpp"
#include <iostream>
#include <list>
  
void Saidas::retira_produto(Produto* p){
  saidas.push_back(p);
}
 
void Saidas::consultar_retirado(){
  cout << "Último produto retirado: "<< saidas.back()<<endl;
}
