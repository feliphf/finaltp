#include <iostream>
#include "Produto.hpp"
  
  void Produto::set_nome (){
    nome = _nome;
  }

  void Produto::set_codigo (){
    codigo = _codigo;
  }

  void Produto::set_fabricante (){
    frabricante = _fabricante;
  }

  void Produto::set_categoria (){
    preco = _preco;
  }

  void Produto::set_nome (){
    categoria = _categoria;
  }

  void Produto::set_quantidade (){
    quantidade = _quantidade;
  }

  int Produto::get_codigo (){
    return codigo;
  }

  int Produto::get_quantidade (){
    return quantidade;
  }

  float Produto::get_preco (){
    return preco;
  }

  std::string Produto::get_nome (){
    return nome;
  }

  sdt::string Produto::get_categoria (){
    return categoria;
  }

  std::string Produto::get_fabricante (){
    return fabricante;
  }
  
  
}
