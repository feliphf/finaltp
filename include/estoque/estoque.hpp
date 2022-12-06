/**
 * @file estoque.hpp
 * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
 * @brief Classe responsavel por adicionar, alterar ou retirar um produto ou uma lista de produtos 
 * @version 1.0
 * @date 2022-12-05
 * @details A classe estoque armazena um mapa de objetos do tipo produtos, ao qual
 * manipula-os, exibe-os, e salva tudo no arquivo "Estoque.txt", podendo a mesma alterar cada atributo
 * de um determinado produto, além de poder retirar ou adicionar uma lista de vários produtos. 
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
   * @brief Armazena um map de vários produtos
   *
   * @details A classe estoque é responsável por armazenar varios produtos,
   * usando um map, separamos cada produto de acordo com sua chave, sendo seu
   * código, e o valor sendo todos os atributos de um produto, esta classe possui
   * um menu, onde o gerente pode fazer modificações em um determinado produto, além
   * do mesmo poder adicionar ou retirar quantos produtos desejar, diferente do funcionário
   * ao qual só terá permissão de retirar os produtos de acordo com as vendas dos mesmos.
   */

class Estoque{
    private:

        ///@brief Mapa com as informações do produto de acordo com seu código
        map<string,Produto> _estoque;

    public:
        
        ///@brief Esta é uma função que destroi um mapa para não ocupar lugar na memória
        Estoque()=default;
        
        ///@brief Esta função salva o arquivo que contém todos os produtos e seus atributos
        void salvarArquivo();
        
        ///@brief Esta função lê o arquivo que contém todas as informações salvas, da última vez que foi acessado   
        void lerArquivo();
        
        ///@brief Esta função dá a possibilidade de pesquisar um produto específico de acordo com o código ou nome
        ///@param Pesquisa, podendo ser um código ou um nome de um produto
        void pesquisarProduto(string pesquisa);
        
        ///@brief Esta função lista todos os produtos que há no estoque no presente momento 
        void listarProdutos();
 
        ///@brief Esta função altera o nome de um determinado produto
        ///@param Pesquisa sendo o código de um produto e nome sendo o nome do produto ao qual o gerente deseja alterar
        void alterarNomeProduto(string pesquisa,string nome);
 
        ///@brief Esta função altera o fabricante de um determinado produto
        ///@param Pesquisa sendo o código de um produto e fabric sendo o nome do fabricante do produto ao qual o gerente deseja alterar
        void alterarFabricanteProduto(string pesquisa,string fabric);
 
        ///@brief Esta função altera a categoria de um determinado produto
        ///@param Pesquisa sendo o código de um produto e categ sendo o nome da categoria do produto ao qual o gerente deseja alterar
        void alterarCategoriaProduto(string pesquisa,string categ);
 
        ///@brief Esta função altera o preço de um determinado produto
        ///@param Pesquisa sendo o código de um produto e preco sendo o preço do produto ao qual o gerente deseja alterar
        void alterarPrecoProduto(string pesquisa, float preco);
 
        ///@brief Esta função abre um menu de opções, ao qual chama todas as funções de alterar acima
        void alterarProduto();
 
        ///@brief Esta função adiciona produtos com seus atributos específicos
        ///@param Codig sendo o código de um produto, quant sendo a quantidade que deseja adicionar, nomeUsuario sendo o nome do usuário e dataAtual sendo a data atual no momento da execução do programa
        void entradasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual);

        ///@brief Esta função retira produtos com seus atributos específicos
        ///@param Codig sendo o código de um produto, quant sendo a quantidade que deseja retirar, nomeUsuario sendo o nome do usuário e dataAtual sendo a data atual no momento da execução do programa
        void saidasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual);
 
        ///@brief Esta função cadastra produto com seus atributos específicos
        void cadastroDeProdutos();
 
        ///@brief Esta função abre um menu com todas as opções de movimentação
        /**@param (ListaQuantidades sendo um par entre um numero inteiro não negativo e um par entre um produto e um inteiro,
        * modo sendo as possibilidades entrada ou saídas, loop sendo uma variável que serve para encerrar o loop na hora correta,
        * count sendo a contagem de produtos, nomeUsuario sendo o nome do usuário e dataAtual sendo a data atual do momento da excução do programa
        */
        void menuEntradaESaidaDeProdutos(std::list<pair<unsigned int,pair<Produto,int>>>& listaQuantidades, std::string modo,
        bool& loop,unsigned int& count, string nomeUsuario, string dataAtual);
 
        ///@brief Esta função gera um histórico de movimentações feitas pelo funcionário ou gerente
        /**@param (ListaQuantidades sendo um par entre um numero inteiro não negativo e um par entre um produto e um inteiro,
        * modo sendo as possibilidades entrada ou saídas, loop sendo uma variável que serve para encerrar o loop na hora correta,
        * count sendo a contagem de produtos, nomeUsuario sendo o nome do usuário e dataAtual sendo a data atual do momento da excução do programa
        */
        void gerarLog(string mensagem, string nomeUsuario, string dataAtual);
 
        ///@brief Esta função imprimi o histórico acima
        void imprimirLog();
 
        ///@brief Esta função exclui um cadastro de um produto com todos os seus atributos
        ///@param Código sendo um código de um produto ao qual o gerente deseja excluir
        void excluirProduto(string codigo);
 
        ///@brief Esta função limpa a tela, para poder ter uma melhor visualização na compilação
        ///@param Modo sendo uma conferência se deve ou não perguntar se pode limpar a tela
        void limparTela(string modo);
};

#endif
