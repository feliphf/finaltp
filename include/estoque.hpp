/**
 * @file estoque.hpp
 * @author Felipe Henrique Ferraz, Yan Figueira e Ana Carolina
 * @brief Classe responsavel por armazenar produtos
 * @version 1.0
 * @date 2022-11-14
 * @details A classe estoque armazena um mapa de objetos do tipo produtos,
 * manipula-os e exibe-os, e salva tudo no arquivo "Estoque.txt".
 * @copyright GNU General Public License v2.0
 */

#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <map>
#include "produto.hpp"

using namespace std;

class Estoque{
    private:
        map<string,Produto> _estoque;
    public:
        Estoque()=default;
        void salvarArquivo();
        void lerArquivo();
        void pesquisarProduto(string pesquisa);
        void listarProdutos();
        void alterarNomeProduto(string pesquisa,string nome);
        void alterarFabricanteProduto(string pesquisa,string fabric);
        void alterarCategoriaProduto(string pesquisa,string categ);
        void alterarPrecoProduto(string pesquisa, float preco);
        void cadastroDeProdutos(string codig, string nome, string categ, float preco, int quant);
        void entradasDeProdutos(string codig, int quant);
        void saidasDeProdutos(string codig, int quant);

        //possiveis outras funçoes de pesquisa se der tempo

};

#endif
