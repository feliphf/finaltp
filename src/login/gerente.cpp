#include "gerente.hpp"

Gerente::Gerente(string id, string t, string n, string c, string e, string u, string s){
    _id = id;
    _tipo = t;
    _nome = n;
    _cpf = c;
    _email = e;
    _ultimoAcesso = u;
    _senha = s;
}

void Gerente::menuInicial(){
	    cout << R"(
    __  ___                    ____       _            _             __
   /  |/  /__  ____  __  __   / __ \_____(_)___  _____(_)___  ____ _/ /
  / /|_/ / _ \/ __ \/ / / /  / /_/ / ___/ / __ \/ ___/ / __ \/ __ `/ / 
 / /  / /  __/ / / / /_/ /  / ____/ /  / / / / / /__/ / /_/ / /_/ / /  
/_/  /_/\___/_/ /_/\__,_/  /_/   /_/  /_/_/ /_/\___/_/ .___/\__,_/_/   
                                                    /_/                                                                                                                                                                                                                                                                                                                                                                                  
)" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "| Olá " << left << setw(27) << getNome() << " | " << setw(12) << getTipo() << " |" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "| " << "1 - Registrar venda                            |" << endl;
	cout << "| " << "2 - Registrar compra                           |" << endl;
	cout << "| " << "3 - Consultar produto                          |" << endl;
	cout << "| " << "4 - Listar todos os produtos                   |" << endl;
	cout << "| " << "5 - Exibir movimentações                       |" << endl;
	cout << "| " << "6 - Menu Administrativo                        |" << endl;
	cout << "| " << "7 - Fazer logout                               |" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "Escolha uma opcao: ";

}

void Gerente::menuAdministrativo(){
    cout << R"(
    __  ___                    ___       __          _       _      __             __  _           
   /  |/  /__  ____  __  __   /   | ____/ /___ ___  (_)___  (_)____/ /__________ _/ /_(_)   ______ 
  / /|_/ / _ \/ __ \/ / / /  / /| |/ __  / __ `__ \/ / __ \/ / ___/ __/ ___/ __ `/ __/ / | / / __ \
 / /  / /  __/ / / / /_/ /  / ___ / /_/ / / / / / / / / / / (__  ) /_/ /  / /_/ / /_/ /| |/ / /_/ /
/_/  /_/\___/_/ /_/\__,_/  /_/  |_\__,_/_/ /_/ /_/_/_/ /_/_/____/\__/_/   \__,_/\__/_/ |___/\____/ 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
)" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "| " << "1 - Alterar produto                            |" << endl;
	cout << "| " << "2 - Cadastrar produto                          |" << endl;
	cout << "| " << "3 - Remover produto                            |" << endl;
	cout << "| " << "4 - Alterar usuário                            |" << endl;
	cout << "| " << "5 - Listar usuários                            |" << endl;
	cout << "| " << "6 - Cadastrar usuário                          |" << endl;
	cout << "| " << "7 - Remover usuário                            |" << endl;
	cout << "| " << "8 - Voltar                                     |" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "Escolha uma opcao: ";
}

bool Gerente::temPermissao(){
    return true;
}

void Gerente::alterarUsuarioLogado(){
    alterarUsuario();
}
