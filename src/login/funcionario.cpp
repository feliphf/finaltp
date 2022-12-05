#include "funcionario.hpp"

Funcionario::Funcionario(string id, string t, string n, string c, string e, string u, string s){
    _id = id;
    _tipo = t;
    _nome = n;
    _cpf = c;
    _email = e;
    _ultimoAcesso = u;
    _senha = s;
}

void Funcionario::menuAdministrativo(){}

void Funcionario::menuInicial(){
    	    cout << R"(
    __  ___                    ____       _            _             __
   /  |/  /__  ____  __  __   / __ \_____(_)___  _____(_)___  ____ _/ /
  / /|_/ / _ \/ __ \/ / / /  / /_/ / ___/ / __ \/ ___/ / __ \/ __ `/ / 
 / /  / /  __/ / / / /_/ /  / ____/ /  / / / / / /__/ / /_/ / /_/ / /  
/_/  /_/\___/_/ /_/\__,_/  /_/   /_/  /_/_/ /_/\___/_/ .___/\__,_/_/   
                                                    /_/)";
    cout << "+------------------------------------------------+" << endl;
	cout << "| Olá " << left << setw(27) << getNome() << " | " << setw(12) << getTipo() << " |" << endl;
	cout << "+------------------------------------------------+" << endl;
    cout << "+----------------------------------------------+" << endl;
	cout << "| " << "1 - Registrar venda                            |" << endl;
	cout << "| " << "2 - Consultar produto                          |" << endl;
	cout << "| " << "3 - Listar todos os produtos                   |" << endl;
	cout << "| " << "4 - Alterar meu dados                          |" << endl;
	cout << "| " << "5 - Fazer logout                               |" << endl;
	cout << "+------------------------------------------------+" << endl;
    cout << "Escolha uma opcao: ";
}

bool Funcionario::temPermissao(){
    return false;
}

void Funcionario::alterarUsuarioLogado(){
    	    cout << R"(
    ___    ____                              __          __          
   /   |  / / /____  _________ ______   ____/ /___ _____/ /___  _____
  / /| | / / __/ _ \/ ___/ __ `/ ___/  / __  / __ `/ __  / __ \/ ___/
 / ___ |/ / /_/  __/ /  / /_/ / /     / /_/ / /_/ / /_/ / /_/ (__  ) 
/_/  |_/_/\__/\___/_/   \__,_/_/      \__,_/\__,_/\__,_/\____/____/                                                                                                                                                                                                                                                                                                                                                                                                                                                    
)" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| " << "1 - Senha                        |" << endl;
    cout << "| " << "2 - Voltar                       |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "Escolha o que deseja alterar: ";
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaInvalida();
    char escolha = aux[0];
    switch (escolha){
        case '1':{
            string s;
            cout << "Digite a nova senha: ";
            cin >> s;
            cout << endl << "A senha foi alterada de " << getSenha() << " para " << s << " com sucesso!" << endl;
            setSenha(s);
            break;
        }
        case '2':{
            break;
       }
	default:
        throw EscolhaInvalida();
        break;
    }
}
