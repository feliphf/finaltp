#include <iostream>
#include "Produto.hpp"
  


void Produto::set_codigo (int _codigo){
  codigo = _codigo;
}

void Produto::set_quantidade (int _quantidade){
  quantidade = _quantidade;
}

void Produto::set_preco (){
  preco = _preco;
}

void Produto::set_nome (std::string _nome){
  nome = _nome;
}

void Produto::set_categoria (std::string _categoria){
  categoria = _categoria;
}

void Produto::set_fabricante (std::string _fabricante){
  fabricante = _fabricante;
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
