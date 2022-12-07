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
        
        ///@brief Esta é uma função de construtor, ao qual inicaliza com nenhuma informação
        ///@details inicializa um estoque default, sem nenhum parametro.
        Estoque()=default;
        
        ///@brief Esta função salva o arquivo que contém todos os produtos e seus atributos
        ///@details carrega todas as informações do mapa dentro do arquivo Estoque.txt
        void salvarArquivo();
        
        ///@brief Esta função lê o arquivo que contém todas as informações salvas, da última vez que foi acessado   
        ///@details lê o arquivo Estoque.txt , constroi um objeto do tipo estoque e carrega no mapa todas as informações do arquivo
        void lerArquivo();
        
        ///@brief Esta função dá a possibilidade de pesquisar um produto específico de acordo com o código ou nome
        ///@param Pesquisa, podendo ser um código ou um nome de um produto
        ///@details pesquisa se um produto existe no estoque, se existir, exibe um menu com todas as informações do produto
        void pesquisarProduto(string pesquisa);
        
        ///@brief Esta função lista todos os produtos que há no estoque no presente momento 
        ///@details exibe uma interface visual com todos os produtos no estoque e suas informações 
        void listarProdutos();
 
        ///@brief Esta função altera o nome de um determinado produto
        ///@param Pesquisa sendo o código de um produto e nome sendo o nome do produto ao qual o gerente deseja alterar
        ///@details procura um produto no estoque e altera o seu nome para o novo nome desejado, com limite de 26 caracteres
        void alterarNomeProduto(string pesquisa,string nome);
 
        ///@brief Esta função altera o fabricante de um determinado produto
        ///@param Pesquisa sendo o código de um produto 
        ///@param fabric sendo o nome do fabricante do produto ao qual o gerente deseja alterar
        ///@details procura um produto no estoque e altera o seu fabricante para o novo fabricante desejado, com limite de 23 caracteres
        void alterarFabricanteProduto(string pesquisa,string fabric);
 
        ///@brief Esta função altera a categoria de um determinado produto
        ///@param Pesquisa sendo o código de um produto
        ///@param categ sendo o nome da categoria do produto ao qual o gerente deseja alterar
        ///@details procura um produto no estoque e altera o sua categoria para a nova categoria desejada, com limite de 23 caracteres
        void alterarCategoriaProduto(string pesquisa,string categ);
 
        ///@brief Esta função altera o preço de um determinado produto
        ///@param Pesquisa sendo o código de um produto 
        ///@param preco sendo o preço do produto ao qual o gerente deseja alterar
        ///@details procura um produto no estoque e altera o seu preço para o novo preço desejado, com limite de 9 algarismos
        void alterarPrecoProduto(string pesquisa, float preco);
 
        ///@brief Esta função abre um menu de opções, ao qual chama todas as funções de alterar acima
        ///@details exibe um menu com opçoes de escolha para alterar os atributos do produto desejado, com exceçao da quantidade e do código que não podem ser alterados
        void alterarProduto();
 
        ///@brief Esta função adiciona produtos no estoque
        ///@param Codig sendo o código de um produto
        ///@param quant sendo a quantidade que deseja adicionar
        ///@param nomeUsuario sendo o nome do usuário 
        ///@param dataAtual sendo a data atual no momento da execução do programa
        ///@details aumenta a quantidade de um produto no estoque somando com a quantidade atual com a quantidade passada como parâmetro
        void entradasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual);

        ///@brief Esta função retira produtos com seus atributos específicos
        ///@param Codig sendo o código de um produto
        ///@param quant sendo a quantidade que deseja retirar
        ///@param nomeUsuario sendo o nome do usuário 
        ///@param dataAtual sendo a data atual no momento da execução do programa
        ///@details diminui a quantidade de um produto no estoque subtraindo com a quantidade atual pela quantidade passada como parâmetro
        void saidasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual);
 
        ///@brief Esta função cadastra produto com seus atributos específicos
        ///@details exibe um menu que pede os dados do produto que será cadastrado, cria um objeto da classe produto com esses dados e quantidade inicial 0, depois insere no mapa de estoque
        void cadastroDeProdutos();
 
        ///@brief Esta função abre um menu com todas as opções de movimentação
        ///@param ListaQuantidades sendo um par entre um numero inteiro não negativo e um par entre um produto e um inteiro,
        ///@param modo sendo as possibilidades entrada ou saídas
        ///@param loop sendo uma variável que serve para encerrar o loop na hora correta,
        ///@param count sendo a contagem de produtos
        ///@param nomeUsuario sendo o nome do usuário 
        ///@param dataAtual sendo a data atual do momento da excução do programa
        ///@details exibe um menu para manipular uma lista de entradas/saídas (depende do modo escolhido) que altera a quantidade de possiveis diversos produtos do estoque
        void menuEntradaESaidaDeProdutos(std::list<pair<unsigned int,pair<Produto,int>>>& listaQuantidades, std::string modo,
        bool& loop,unsigned int& count, string nomeUsuario, string dataAtual);
 
        ///@brief Esta função gera um histórico de movimentações feitas pelo funcionário ou gerente
        ///@param count sendo a contagem de produtos
        ///@param nomeUsuario sendo o nome do usuário 
        ///@param dataAtual sendo a data atual do momento da excução do programa
        ///@details salva as novas movimentações no arquivo Movimentacoes.txt
        void gerarLog(string mensagem, string nomeUsuario, string dataAtual);
 
        ///@brief Esta função imprimi o histórico acima
        ///@details imprime o histórico de movimentaçoes lido do arquivo Movimentacoes.txt
        void imprimirLog();
 
        ///@brief Esta função exclui um cadastro de um produto com todos os seus atributos
        ///@param Código sendo um código de um produto ao qual o gerente deseja excluir
        ///@details verifica se um produto existe no estoque pelo código e apaga seu cadastro
        void excluirProduto(string codigo);
 
        ///@brief Esta função limpa a tela, para poder ter uma melhor visualização na compilação
        ///@param Modo sendo uma conferência se deve ou não perguntar se pode limpar a tela
        ///@details recurso visual para melhor vizualização e interação do usuário, possui modo "perguntar" em que pergunta se pode limpar a tela antes de limpar, e modo "continuar" em que limpa direto sem perguntar
        void limparTela(string modo);
};

#endif
