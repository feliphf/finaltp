#include <iostream>
#include "estoque.hpp"

using namespace std;

int main(){
    Estoque estoque;
    estoque.lerArquivo();
    estoque.listarProdutos();
    cout << "----------------------------------------------------------------------------------------------------------"<< endl;
    estoque.pesquisarProduto("12571251");
    cout << "----------------------------------------------------------------------------------------------------------"<< endl;
    estoque.pesquisarProduto("9545124");
    cout << "----------------------------------------------------------------------------------------------------------"<< endl;
    estoque.alterarNomeProduto("9545124","panteao");
    estoque.alterarNomeProduto("1396547","ronaldo");
    cout << "----------------------------------------------------------------------------------------------------------"<< endl;
    estoque.listarProdutos();
    cout << "----------------------------------------------------------------------------------------------------------"<< endl;
    estoque.alterarFabricanteProduto("9545124","212");
    estoque.alterarCategoriaProduto("1396547","molhado");
    estoque.alterarPrecoProduto("1396547",300.00);
    cout << "----------------------------------------------------------------------------------------------------------"<< endl;
    estoque.listarProdutos();
    estoque.salvarArquivo();
    return 0;
}