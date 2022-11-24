#include "sistema.hpp"

void Sistema::menuInicial(){
        std::cout << R"(
  _   _                            _          _____ _     _                       
 | \ | |                          | |        / ____(_)   | |                      
 |  \| | ___  _ __ ___   ___    __| | ___   | (___  _ ___| |_ ___ _ __ ___   __ _ 
 | . ` |/ _ \| '_ ` _ \ / _ \  / _` |/ _ \   \___ \| / __| __/ _ \ '_ ` _ \ / _` |
 | |\  | (_) | | | | | |  __/ | (_| | (_) |  ____) | \__ \ ||  __/ | | | | | (_| |
 |_| \_|\___/|_| |_| |_|\___|  \__,_|\___/  |_____/|_|___/\__\___|_| |_| |_|\__,_|
                                                                                  
                                                                                  
)" << std::endl;
    std::cout << "Escolha uma opcao: " << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
	std::cout << "| " << "1 - Fazer Login       |" << std::endl;
	std::cout << "| " << "2 - Sair              |" << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
}

void Sistema::menuFuncionario(){
    std::cout << "Escolha uma opcao: " << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
	std::cout << "| " << "1 - Consultar Produto |" << std::endl;
	std::cout << "| " << "2 - Listar Produtos   |" << std::endl;
	std::cout << "| " << "3 - Registrar Venda   |" << std::endl;
	std::cout << "| " << "4 - Sair              |" << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
}

void Sistema::menuGerente(){
    std::cout << "Escolha uma opcao: " << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
	std::cout << "| " << "1 - Consultar Produto |" << std::endl;
	std::cout << "| " << "2 - Listar Produtos   |" << std::endl;
	std::cout << "| " << "3 - Registrar Venda   |" << std::endl;
	std::cout << "| " << "3 - Registrar Compra  |" << std::endl;
	std::cout << "| " << "3 - Alterar Produto   |" << std::endl;
	std::cout << "| " << "4 - Sair              |" << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
}

void Sistema::menuAlterarProduto(){
    std::cout << "Escolha o que deseja alterar: " << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
	std::cout << "| " << "1 - Nome              |" << std::endl;
	std::cout << "| " << "2 - Categoria         |" << std::endl;
	std::cout << "| " << "3 - Fabricante        |" << std::endl;
	std::cout << "| " << "3 - Preço             |" << std::endl;
	std::cout << "| " << "4 - Sair              |" << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
}

