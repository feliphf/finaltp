#include "estoque.hpp" //olaaaaa
#include "produto.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

void Estoque::salvarArquivo(){
    fstream arquivo;
    map<string, Produto>::iterator it;
    arquivo.open("Estoque.txt", ios::out);
    for(it=_estoque.begin(); it!=_estoque.end(); it++){
         arquivo<< (it->second).getNome()<<' '<< (it->second).getFabricante()<<' ' <<
        (it->second).getCategoria()<<' ' << (it->second).getCodigo()<<' ' << (it->second).getPreco()<<' ' << 
        (it->second).getQuantidade() << endl;
    }
    arquivo.close();
}

void Estoque::lerArquivo(){
    fstream arquivo;
    string nome;
    string fabricante;
    string categoria;
    string codigo;
    float preco;
    int quantidade;
    arquivo.open("Estoque.txt",ios::in);
    if (arquivo.is_open())
    {
        while (arquivo >> nome >> fabricante >> categoria >> codigo >> preco >> quantidade){
            Produto p(nome, fabricante, categoria, codigo, preco, quantidade); 
           _estoque.insert(pair<string,Produto>(codigo,p));
        }
    }else
        arquivo.open("Estoque.txt",ios::out);
    arquivo.close(); 
}

void Estoque::listarProdutos(){
    map<string, Produto>::iterator it;
    cout << left << setw(20) << "Nome" << setw(23) << "Fabricante"<< setw(23) <<
        "Categoria"<< setw(24) << "Código" << setw(22) << "Preço" << setw(20) <<
        "Quantidade" << endl << fixed << showpoint;
    cout << endl;
    for(it=_estoque.begin(); it!=_estoque.end(); it++){
        cout << setprecision(2) << left << setw(20) << (it->second).getNome() << setw(23) << (it->second).getFabricante() << setw(23) <<
        (it->second).getCategoria() << setw(23) << (it->second).getCodigo() << setw(17) << (it->second).getPreco() << setw(10) << right <<
        (it->second).getQuantidade() << endl;
    }
}

void Estoque::pesquisarProduto(string pesquisa){
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        cout << left << setw(20) << "Nome" << setw(23) << "Fabricante"<< setw(23) <<
        "Categoria"<< setw(24) << "Código" << setw(22) << "Preço" << setw(20) <<
        "Quantidade" << endl << fixed << showpoint;
        cout << endl;
        cout << setprecision(2) << left << setw(20) << (it->second).getNome() << setw(23) << (it->second).getFabricante() << setw(23) <<
        (it->second).getCategoria() << setw(23) << (it->second).getCodigo() << setw(17) << (it->second).getPreco() << setw(10) << right <<
        (it->second).getQuantidade() << endl;
      }else
        cout << "Produto não cadastrado" << endl;
}

void Estoque::alterarNomeProduto(string pesquisa, string nome){//fazer uma pra cada atributo exceto codigo e quantidade, que se da pelas entradas e saidas, junto com registrar nas entradas
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        cout<<"O nome foi alterado de "<<(it->second).getNome()<<" para "<<nome<<endl;
        (it->second).setNome(nome);
      }else
        cout << "Produto não cadastrado" << endl;
}

void Estoque::alterarFabricanteProduto(string pesquisa, string fabric){//fazer uma pra cada atributo exceto codigo e quantidade, que se da pelas entradas e saidas, junto com registrar nas entradas
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        cout<<"O fabricante foi alterado de "<<(it->second).getFabricante()<<" para "<<fabric<<endl;
        (it->second).setFabricante(fabric);
      }else
        cout << "Produto não cadastrado" << endl;
}

void Estoque::alterarCategoriaProduto(string pesquisa, string categ){//fazer uma pra cada atributo exceto codigo e quantidade, que se da pelas entradas e saidas, junto com registrar nas entradas
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        cout<<"A categoria foi alterada de "<<(it->second).getCategoria()<<" para "<<categ<<endl;
        (it->second).setCategoria(categ);
      }else
        cout << "Produto não cadastrado" << endl;
}

void Estoque::alterarPrecoProduto(string pesquisa, float preco){//fazer uma pra cada atributo exceto codigo e quantidade, que se da pelas entradas e saidas, junto com registrar nas entradas
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        cout<<setprecision(2)<<"O preço foi alterado de "<<(it->second).getPreco()<<" para "<<preco<<endl;
        (it->second).setPreco(preco);
      }else
        cout << "Produto não cadastrado" << endl;
}
