#include "Produto.hpp"
#include "Saidas.hpp"
#include <iostream>
#include <list>
  
void Saidas::retiraProduto(Produto* p){
  saidas.push_back(p);
}
 
void Saidas::consultarRetirados (){
  cout << "Último produto retirado: "<< saidas.back()<<endl;
}
