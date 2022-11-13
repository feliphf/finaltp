/**
 * @file Entradas.hpp
 * @author Ana Carolina e Guilherme Paschoal
 * @brief Classe para armazenamento de entradas dos produtos
 * @version 1.0
 * @date 2022-11-13
 * @details A classe entradas está responsável por armazenar as compras feitas pelo gerente, 
 * incluindo-as, pela classe de cátologo produtos, desta forma, irá armazenar cada produto, 
 * ela também retorna a consulta de determinado produto, para poder ser conferido qse realmente adicionou 
 * @copyright GNU General Public License v2.0
 */

#ifndef ENTRADAS.HPP
#define ENTRADAS.HPP
#include "Produto.hpp"
#include <iostream>
#include <list>

/**
 * @brief Armazena produtos em uma lista de entradas.
 */
class Produto{
  private:
///@brief 
  std::list <Produto*> entradas;
  
  public:
  
  void adicionaProduto(Produto* p);
  std::list consultarAdicionado (int codigo);
    
};
#endif;
