  /**
   * @file produto.hpp
   * @author Ana Carolina, Felipe Ferraz, Guilherme Pascoal, Pedro Araújo, Yan Figueiras 
   * @brief Classe para armazenamento dos produtos
   * @version 1.1
   * @date 2022-12-05
   * @details A classe produto funcionará como um catálogo onde o  
   * gerente e os funcionarios poderão fazer consultas e alterações.
   * @copyright GNU General Public License v2.0
   */

#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
using namespace std;

  /**
   * @brief Armazena todos os atributos de um determiando produto
   *
   * @details A classe produto é responsável por armazenar os atributos 
   * necessários para os produtos, servindo como uma espécie de catálogo  
   * onde o funcionário poderá consultar a disponibilidade de um produto e 
   * efetuar a retirada do mesmo. Já o gerente também poderá consultar e
   * retirar, mas somente ele conseguirá adcionar um novo produto.
   */

class Produto{
    private:

        ///@brief Nome do produto.
        string _nome;

        ///@brief Fabricante do produto.
        string _fabricante;

        ///@brief Categoria do produto.
        string _categoria;

        ///@brief Código único do produto.
        string _codigo;

        ///@brief Preço unitário do produto.
        float _preco;

        ///@brief quantidade de um produto.
        int _quantidade;

    public:

        ///@brief Construtor da classe Produto, recebe todos os atributos como parâmetro.
        Produto(string n, string fabricante, string categoria, string codigo, float preco, int quantidade);

        ///@brief Retorna o nome do produto
        ///@return Retorna o nome do produto
        string getNome(void);

        ///@brief Retorna o fabricante do produto.
        ///@return Retorna o fabricante do produto.
        string getFabricante(void);

        ///@brief Retorna a categoria do produto
        ///@return Retorna a categoria do produto
        string getCategoria(void);


        ///@brief Retorna o código do produto
        ///@return Retorna o código do produto
        string getCodigo(void);

        ///@brief Retorna a quantidade do produto
        ///@return Retorna a quantidade do produto
        int getQuantidade(void);

        ///@brief Retorna o preço do produto
        ///@return Retorna o preço do produto
        float getPreco(void);

        ///@brief Altera o nome de um produto
        void setNome(string n);

        ///@brief Altera o fabricante de um produto
        void setFabricante(string f);

        ///@brief Altera a categoria de um produto
        void setCategoria(string c);

        ///@brief Altera o código único de um produto
        void setCodigo(string c);

        ///@brief Altera a quantidade de um produto
        void setQuantidade(int q);

        ///@brief Adiciona o preço de um produto
        void setPreco(float p);
};

#endif
