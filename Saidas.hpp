/**
 * @file Entradas.hpp
 * @author Ana Carolina e Guilherme Pascoal
 * @brief Classe para retirar produtos armazenados na classe produto.
 * @version 1.0
 * @date 2022-11-13
 * @details A classe saídas está responsável por retirar produtos da 
 * classe produto, ao qual serão administados pela classe estoque.
 * @copyright GNU General Public License v2.0
 */

#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <iostream>
#include <list>

#include "Produto.hpp"

/**
 * @brief Retirada de um produto em uma lista de saídas.
 *
 * @details A classe saídas está responsável por retirar produtos de acordo com as  
 * vendas feitas na empresa, retirando-as, pela classe de cátologo produto, desta  
 * forma, irá retirar cada produto. Ela também retornará o último produto adicionado, 
 * desta forma, o funcionário poderá conferir se realmente foi retirado, oque ele gostaria.
 */

class Saidas {
private:
    
///@brief lista de saídas, para retirar cada produto, em uma posição da lista.
  std::list<Produto*> saidas;
  
public:

/**
 * @brief Função responsável por retirar um produto da lista de saídas. 
 *
 * @details A partir da venda de um produto do estoque da empresa, o funcionário 
 * irá retirar cada produto usando este método, a lista cria-da irá retirar um 
 * produto, de acordo com o seus atributos, na classe estoque.
 *
 * @param Produto p, produto com os atributos da classe produto.
 */  
  void retiraProduto(Produto* p);
    
/**
 * @brief Possibilita a consulta do funcionário, para conferir se retirou 
 * corretamente o produto que gostaria de retirar.
 *
 * @details a função irá apresentar o último produto adicionado, para poder ser conferido.
 */
  void consultarRetirado();
  
};
#endif
