/**
 * @file Entradas.hpp
 * @author Ana Carolina e Guilherme Paschoal
 * @brief Classe para armazenamento de entradas dos produtos.
 * @version 1.0
 * @date 2022-11-13
 * @details A classe entradas está responsável por armazenar produtos, 
 * que serão administados pela classe estoque.
 * @copyright GNU General Public License v2.0
 */

#ifndef ENTRADAS.HPP
#define ENTRADAS.HPP

#include "Produto.hpp"

#include <iostream>
#include <list>

/**
 * @brief Armazena produto em uma lista de entradas.
 *
 * details A classe entradas está responsável por armazenar as compras feitas pelo gerente, 
 * incluindo-as, pela classe de cátologo produto, desta forma, irá armazenar cada produto,  
 * ela também retorna a consulta de determinado produto, 
 * para ser conferido se realmente foi adicionado.
 */
class Entradas{
  private:
  
///@brief lista de entradas, para armazenar cada produto, em uma posição da lista.
  std::list <Produto*> entradas;
  
  public:
  
/**
* @brief Função responsável por adiocionar um produto a lista de entradas
*
* @details A partir da compra de um produto para o estoque da empresa,
* o gerente irá adiocionar cada produto usando este método, a lista criá-da irá armazenar um produto,
* com todas as especificações do catálogo dos produtos.
*
* @param Produto p, produto com os atributos da classe produto.
*/  
  void adicionaProduto(Produto* p);
  
/**
* @brief Possibilita a consulta do gerente, para conferir se adiocionou corretamente
* o produto que gostaria de adiocionar, conferindo-o, pelo código do produto.
*
* @details Além de possibilitar a consulta, e a conferência, ele também trata os erros,
* que podem ser cometidos.

* @param código int, o código do produto, ao qual foi armazenado nas entradas.
*/
  std::list consultarAdicionado (int codigo);
    
};
#endif;
