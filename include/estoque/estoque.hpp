/**
 * @file estoque.hpp
 * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
 * @brief Classe responsavel por armazenar produtos
 * @version 1.0
 * @date 2022-12-05
 * @details A classe estoque armazena um mapa de objetos do tipo produtos,
 * manipula-os e exibe-os, e salva tudo no arquivo "Estoque.txt".
 * @copyright GNU General Public License v2.0
 */

#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include "EXCECOESDOESTOQUE.hpp"
#include "produto.hpp"
using namespace std;

 /**
   * @brief
   *
   * @details A classe estoque é responsável por  
   * 
   *  
   * 
   * 
   */

class Estoque{
    private:

        ///@brief 
        map<string,Produto> _estoque;

    public:
        
        ///@brief 
        Estoque()=default;
        
        ///@brief 
        void salvarArquivo();
        
        ///@brief        
        void lerArquivo();
        
        ///@brief
        void pesquisarProduto(string pesquisa);
        
        ///@brief
        void listarProdutos();
 
        ///@brief
        void alterarNomeProduto(string pesquisa,string nome);
 
        ///@brief
        void alterarFabricanteProduto(string pesquisa,string fabric);
 
        ///@brief
        void alterarCategoriaProduto(string pesquisa,string categ);
 
        ///@brief
        void alterarPrecoProduto(string pesquisa, float preco);
 
        ///@brief
        void alterarProduto();
 
        ///@brief
        void entradasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual);
 
        ///@brief
        void saidasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual);
 
        ///@brief
        void cadastroDeProdutos();
 
        ///@brief
        void menuEntradaESaidaDeProdutos(std::list<pair<unsigned int,pair<Produto,int>>>& listaQuantidades, std::string modo,
        bool& loop,unsigned int& count, string nomeUsuario, string dataAtual);
 
        ///@brief
        void gerarLog(string mensagem, string nomeUsuario, string dataAtual);
 
        ///@brief
        void imprimirLog();
 
        ///@brief
        void excluirProduto(string codigo);
 
        ///@brief
        void limparTela(string modo);
};

#endif
