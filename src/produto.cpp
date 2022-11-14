#include "produto.hpp"

Produto::Produto(string n, string fabricante, string categoria, string codigo, float preco, int quantidade){
    _nome=n;
    _fabricante=fabricante;
    _categoria=categoria;
    _codigo=codigo;
    _preco=preco;
    _quantidade=quantidade;
}

string Produto::getNome(){
return _nome;
}

string Produto::getFabricante(){
return _fabricante;
}

string Produto::getCategoria(){
return _categoria;
}

string Produto::getCodigo(){
return _codigo;
}

int Produto::getQuantidade(){
return _quantidade;
}

float Produto::getPreco(){
return _preco;
}

void Produto::setNome(string n){
    _nome=n;
}

void Produto::setFabricante(string f){
    _fabricante=f;
}

void Produto::setCategoria(string c){
    _categoria=c;
}

void Produto::setCodigo(string c){
    _codigo=c;
}

void Produto::setQuantidade(int q){
    _quantidade=q;
}

void Produto::setPreco(float p){
    _preco=p;
}
