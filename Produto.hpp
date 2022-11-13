#ifndef PRODUTO.HPP
#define PRODUTO.HPP
#include <iostream>

/**
 * @brief Classe base responsavel pelo armazenamento e manipulacao das
 * informacoes basicas de um produto.
 */

class Produto{
  
  /**
   * @brief Atributos do produto
   */
  private:
  
  int codigo;
  float preco;
  std::string nome;
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
  
