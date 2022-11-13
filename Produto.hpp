  /**
   * @file Produto.hpp
   * @author Ana Carolina e Guilherme Pascoal
   * @brief Classe para armazenamento dos produtos
   * @version 1.0
   * @date 2022-11-13
   * @details A classe produto funcionará como um catálogo onde o gerente e os funcionarios poderão
   * fazer consultas e alterações.
   * @copyright GNU General Public License v2.0
   */

#ifndef PRODUTO.HPP
#define PRODUTO.HPP
#include <iostream>

  /**
   * @brief Armazena produto em uma lista de entradas.
   * @details A classe produto está responsável por armazenar os atributos necessários para os produtos, 
   * servindo como uma espécie de catálogo onde o funcionário ou gerente poderá consultar a disponibilidade
   * de um produto e adcionar/retirar um item do catálogo. 
   * para ser conferido se realmente foi adicionado.
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
  /**
   * @brief Fabricante do produto.
   */
  std::string fabricante;
  
  public:
  
  /**
   * @brief Adiciona o nome de um produto
   */
  void set_nome ();
  
  /**
   * @brief Adiciona o código único de um produto
   */
  void set_codigo ();
  
  /**
   * @brief Adiciona o fabricante de um produto
   */
  void set_fabricante ();
  
  /**
   * @brief Adiciona o preço de um produto
   */
  void set_preco ();
  
  /**
   * @brief Adiciona a categoria de um produto
   */
  void set_categoria ();
  
  /**
  * @brief Retorna o código do produto
  *
  * @return Retorna o código do produto
  */
  int get_codigo ();
  
  /**
  * @brief Retorna o preço do produto
  *
  * @return Retorna o preço do produto
  */
  float get_preco ();
  
  /**
  * @brief Retorna o nome do produto
  *
  * @return Retorna o nome do produto
  */
  std::string get_nome ();
  
  /**
  * @brief Retorna a categoria do produto
  *
  * @return Retorna a categoria do produto
  */
  std::string get_categoria ();
  
  /**
  * @brief Retorna o fabricante do produto.
  *
  * @return Retorna o fabricante do produto.
  */
  std::string get_fabricante ();
  
};
#endif;
  
