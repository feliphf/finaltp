#include "usuario.hpp"

string Usuario::getId(){
    return _id;
}

string Usuario::getTipo(){
    return _tipo;
}

string Usuario::getNome(){
    for (unsigned i = 0; i < _nome.size(); i++)
        if (_nome[i] == '_')
            _nome[i] = ' ';    
    return _nome;
}

string Usuario::getCpf(){
    return _cpf;
}

string Usuario::getEmail(){
    return _email;
}

string Usuario::getUltimoAcesso(){
    return _ultimoAcesso;
}

string Usuario::getSenha(){
    return _senha;
}

bool Usuario::getEstaAutenticado(){
    return _estaAutenticado;
}

void Usuario::setId(string s){
    _id = s;
}

void Usuario::setTipo(string s){
    _tipo = s;
}

void Usuario::setNome(string s){
    for (unsigned i = 0; i < _nome.size(); i++)
        if (_nome[i] == ' ')
            _nome[i] = '_';   
    _nome = s;
}

void Usuario::setCpf(string s){
    _cpf = s;
}

void Usuario::setEmail(string s){
    _email = s;
}

void Usuario::setUltimoAcesso(string s){
    _ultimoAcesso = s;
}

void Usuario::setSenha(string s){
    _senha = s;
}

void Usuario::setEstaAutenticado(bool b){
    _estaAutenticado = b;
}

void Usuario::alterarUsuario(){
    cout << "+----------------------------------+" << endl;
    cout << "| " << "1 - Nome                         |" << endl;
    cout << "| " << "2 - Tipo                         |" << endl;
    cout << "| " << "3 - CPF                          |" << endl;
    cout << "| " << "4 - Email                        |" << endl;
    cout << "| " << "5 - Senha                        |" << endl;
    cout << "| " << "6 - Voltar                       |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "Escolha o que deseja alterar: ";
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaInvalida();
    char escolha = aux[0];
    switch (escolha){
        case '1':{
            string n;
            cout << "Digite o novo nome: ";
            cin.ignore(1,'\n');
            getline(cin, n);
            if (n.size() > 26){
                throw ExcecaoTamanhoNomeAlt();
                break;
            }else{
                cout << endl << "O nome foi alterado de " << getNome() << " para " << n << " com sucesso!" << endl;
                setNome(n);
                break;
            }
        }
        case '2':{
            cout << "+----------------------------------+" << endl;
	        cout << "| " << "1 - Gerente                      |" << endl;
	        cout << "| " << "2 - Funcionário                  |" << endl;
	        cout << "+----------------------------------+" << endl;
            cout << "Escolha qual tipo de usuário: ";
            string aux;
            cin >> aux;
            if (aux.size()>1)
                throw EscolhaInvalida();
            char escolha = aux[0];
            switch (escolha){
               case '1':{
                    cout << "O tipo foi alterado de " << getTipo() << " para Gerente com sucesso!" << endl;
                    setTipo("Gerente");
                    break;
                }
                 case '2':{
                    cout << "O tipo foi alterado de " << getTipo() << " para Funcionário com sucesso!" << endl;
                    setTipo("Funcionario");
                    break;
                }
		    default:
        	    throw EscolhaInvalida();
                    break;
            }
            break;
        }
        case '3':{
            string c;
            cout << "Digite o novo CPF no modelo XXX.XXX.XXX-XX : ";
            cin >> c;
            if (c.size() > 14){
                throw ExcecaoTamanhoCPF();
                break;
            }else{
            cout << endl << "O CPF foi alterado de " << getCpf() << " para " << c << " com sucesso!" << endl;
            setCpf(c);
            break;
            }
        }
        case '4':{
            string e;
            cout << "Digite o novo Email: ";
            cin >> e;
            if (e.size() > 28){
                throw ExcecaoTamanhoEmail();
                break;
            }else{
            cout << endl << "O Email foi alterado de " << getEmail() << " para " << e << " com sucesso!" << endl;
            setEmail(e);
            break;
            }
        }
        case '5':{
            string s;
            cout << "Digite a nova senha: ";
            cin >> s;
            if (s.size() > 6){
                throw ExcecaoTamanhoSenha();
                break;
            }else{
            cout << endl << "A senha foi alterada de " << getSenha() << " para " << s << " com sucesso!" << endl;
            setSenha(s);
            break;
            }
        }
        case '6':{
            break;
        }
	default:
       	    throw EscolhaInvalida();
            break;
    }
}

void Usuario::limparTela(string modo){
    if (modo == "perguntar"){
        std::cout << "Pressione enter para continuar!";
        char temp;
        std::cin.ignore();
        std::cin.get(temp);
        int aux = system("cls||clear");
        if (aux == -1){
            std::cout << "O sistema não conseguiu limpar a tela!" << std::endl;
        }
    } else {
        int aux = system("cls||clear");
        if (aux == -1){
            std::cout << "O sistema não conseguiu limpar a tela!" << std::endl;
        }
    }
}
