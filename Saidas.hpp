/**
 * @file Entradas.hpp
 * @author Ana Carolina e Guilherme Pascoal
 * @brief Classe para retirar produtos armazenados na classe produto.
 * @version 1.0
 * @date 2022-11-13
 * @details A classe saídas está responsável por retirar produtos da classe produto, 
 * ao qual serão administados pela classe estoque.
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
 * @details A classe saídas está responsável por retirar produtos de acordo com as vendas feitas na empresa, 
 * retirando-as, pela classe de cátologo produto, desta forma, irá retirar cada produto,  
 * ela também retorna a consulta de determinado produto, 
 * para ser conferido se realmente foi retirado.
 */
class Saidas {
private:
    
///@brief lista de saídas, para retirar cada produto, em uma posição da lista.
  std::list<Produto*> saidas;
  
public:

/**
 * @brief Função responsável por retirar um produto da lista de saídas. 
 *
 * @details A partir da venda de um produto do estoque da empresa,
 * o funcionário irá retirar cada produto usando este método, a lista criá-da irá retirar um produto,
 * de acordo com o seu código, só poderá retirar, se já tiver sido adicionado ao estoque, além de tratar os erros,
 * que podem ser cometidos.
 *
 * @param código int do produto, de um produto existente no estoque da empresa.
 */  
  void retiraProduto(int código);
    
/**
 * @brief Possibilita a consulta do funcionário, para conferir se retirou corretamente
 * o produto que gostaria de retirar, conferindo-o, pelo código do produto.
 *
 * @details Além de possibilitar a consulta, e a conferência, ele também trata os erros,
 * que podem ser cometidos.
 *
 * @param código int, o código do produto, ao qual foi retirado nas saídas.
 */
  std::string consultarRetirados (int codigo);
  
};
#endif
