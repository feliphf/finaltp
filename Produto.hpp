#ifndef PRODUTO.HPP
#define PRODUTO.HPP
#include <iostream>

/**
 * @file Produto.hpp
 * @author Ana Carolina e Guilherme Pascoal
 * @brief Classe para armazenamento dos produtos
 * @version 1.0
 * @date 2022-11-13
 * @details A classe produto está responsável por armazenar os atributos necessários para os produtos, 
 * servindo como uma espécie de catálogo onde o funcionário ou gerente poderá consultar a disponibilidade
 * de um produto e adcionar/retirar um item do catálogo. 
 * @copyright GNU General Public License v2.0
 */

class Produto{
  
  private:
  
  /**
   * @brief Código único do produto.
   */
  int codigo;
  /**
   * @brief Preço unitário do produto.
   */
  float preco;
  /**
   * @brief Nome do produto.
   */
  std::string nome;
  /**
   * @brief Categoria do produto.
   */
  std::string categoria;
  std::string fabricante;
  
  public:
  
  void set_nome ();
  void set_codigo ();
  void set_fabricante ();
  void set_preco ();
  void set_categoria ();
  /**
  * @brief Retorna o código do produto
  *
  * @return int código do produto
  */
  int get_codigo ();
  /**
  * @brief Retorna o preço do produto
  *
  * @return float preço do produto
  */
  float get_preco ();
  /**
  * @brief Retorna o nome do produto
  *
  * @return string nome do produto
  */
  std::string get_nome ();
  /**
  * @brief Retorna a categoria do produto
  *
  * @return string categoria do produto
  */
  std::string get_categoria ();
  /**
  * @brief Retorna o fabricante do produto
  *
  * @return string fabricante do produto
  */
  std::string get_fabricante ();
  
};
#endif;
  
