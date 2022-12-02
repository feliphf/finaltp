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
	cout << "+------------------------------------------------+" << endl;
	cout << "| Olá " << left << setw(27) << getNome() << " | " << setw(12) << getTipo() << " |" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "| " << "1 - Registrar venda                            |" << endl;
	cout << "| " << "2 - Registrar compra                           |" << endl;
	cout << "| " << "3 - Consultar produto                          |" << endl;
	cout << "| " << "4 - Listar todos os produtos                   |" << endl;
	cout << "| " << "5 - Gerar relatório                            |" << endl;
	cout << "| " << "6 - Funções admnistrativas                     |" << endl;
	cout << "| " << "7 - Fazer logout                               |" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "Escolha uma opcao: ";

}

void Gerente::menuAdministrativo(){
	cout << "+------------------------------------------------+" << endl;
	cout << "| " << "1 - Alterar produto                            |" << endl;
	cout << "| " << "2 - Alterar usuário                            |" << endl;
	cout << "| " << "3 - Listar usuários                            |" << endl;
	cout << "| " << "4 - Cadastrar usuário                          |" << endl;
	cout << "| " << "5 - Remover usuário                            |" << endl;
	cout << "| " << "6 - Voltar                                     |" << endl;
	cout << "+------------------------------------------------+" << endl;
	cout << "Escolha uma opcao: ";
}

bool Gerente::temPermissao(){
    return true;
}

void Gerente::alterarUsuarioLogado(){
    alterarUsuario();
}
