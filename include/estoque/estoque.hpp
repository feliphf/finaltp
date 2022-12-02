/**
 * @file estoque.hpp
 * @author Felipe Henrique Ferraz e Yan Figueiras
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

        //possiveis outras funçoes de pesquisa se der tempo

};

#endif