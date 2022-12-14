#include "sistemaLogin.hpp"

void sistemaLogin::lerArquivo(){
    fstream arquivo;
    string id,tipo,nome,cpf,email,ultimoAcesso,senha;
    arquivo.open("database/Usuarios.txt",ios::in);
    if (arquivo.is_open())
    {   
        while (arquivo >> id >> nome >> tipo >> cpf >> email >> ultimoAcesso >> senha){
            if (tipo == "Gerente"){
                Usuario *g = new Gerente(id, tipo, nome, cpf, email, ultimoAcesso, senha);
                _usuarios.insert({id,g}); 
            }else {
                Usuario *f = new Funcionario(id, tipo, nome, cpf, email, ultimoAcesso, senha);
                _usuarios.insert(pair<string,Usuario*>(id,f)); 
            }
        }
    }else{
        arquivo.open("database/Usuarios.txt",ios::out);
        arquivo << "0000 adm Gerente 111.111.111-11 adm@gmail.com 00/00/0000 1"<<endl;
        cout<<"Arquivo não havia sido encontrado, agora foi criado com sucesso, execute o programa novamente"<<endl; // throw ExcecaoArquivoNaoEncontrado
    }
    arquivo.close(); 
}

void sistemaLogin::salvarArquivo(){
    fstream arquivo;
    string nomeFormatado;
    map<string, Usuario*>::iterator it;
    arquivo.open("database/Usuarios.txt", ios::out);
    for(it=_usuarios.begin(); it!=_usuarios.end(); it++){
        nomeFormatado = (it->second)->getNome();
        for (unsigned i = 0; i < nomeFormatado.size(); i++)
             if (nomeFormatado[i] == ' ')
                nomeFormatado[i] = '_';    
         arquivo<< (it->second)->getId()<<' '<< nomeFormatado <<' ' <<
        (it->second)->getTipo()<<' ' << (it->second)->getCpf()<<' ' << (it->second)->getEmail()<<' ' << 
        (it->second)->getUltimoAcesso() << ' ' << (it->second)->getSenha() << endl;
    }
    arquivo.close();
}

void sistemaLogin::listarUsuarios(){
    if(_usuarios.empty()){
        cout << "Nenhum usuário cadastrado!!" << endl;
        limparTela("perguntar");
    }else{
    cout << R"(
    __    _      __               __        __  __             __       _           
   / /   (_)____/ /_____ _   ____/ /__     / / / /______  ____/_/______(_)___  _____
  / /   / / ___/ __/ __ `/  / __  / _ \   / / / / ___/ / / / __ `/ ___/ / __ \/ ___/
 / /___/ (__  ) /_/ /_/ /  / /_/ /  __/  / /_/ (__  ) /_/ / /_/ / /  / / /_/ (__  ) 
/_____/_/____/\__/\__,_/   \__,_/\___/   \____/____/\__,_/\__,_/_/  /_/\____/____/ )" << endl;
    map<string, Usuario*>::iterator it;
    cout << "+-----+---------------------------+------------+---------------+----------------------------+---------------+-------+"<< endl;
    cout << "| ID  |           NOME            |    TIPO    |      CPF      |            EMAIL           | ÚLTIMO ACESSO | SENHA |"<< endl;
	cout << "+-----+---------------------------+------------+---------------+----------------------------+---------------+-------+"<< endl;
    for(it=_usuarios.begin(); it!=_usuarios.end(); it++){
        cout << left << '|' << setw(5) << (it->second)->getId() <<  '|' << setw(27) << (it->second)->getNome() <<  '|' << setw(12) <<
        (it->second)->getTipo() <<  '|' << setw(15) << (it->second)->getCpf() <<  '|' << setw(28) << (it->second)->getEmail()
         <<  '|' << setw(15) << (it->second)->getUltimoAcesso() <<  '|' << setw(7) << (it->second)->getSenha();
         cout << '|' << endl;
        cout << "+-----+---------------------------+------------+---------------+----------------------------+---------------+-------+"<< endl;
        }
        limparTela("perguntar");
    }
}

void sistemaLogin::limparMemoria(){
    _usuarios.clear();
    // excluir ponteiros
}

string sistemaLogin::gerarID(){
    static const int tamanhoDigitos = 4; 
    string IDgerado;
    int numeroMaximoTentativas = 10; 
    do {
        for (int i = 0; i < tamanhoDigitos; ++i) {
            IDgerado += ('0' + (rand() % 10));
        }
        if (_usuarios.count(IDgerado) == 0)
            return IDgerado;
        IDgerado = "";
    } while (--numeroMaximoTentativas > 0);
    throw std::runtime_error("Não foi possível gerar um ID único");
}

string sistemaLogin::gerarDataAtual(){
    time_t t = time(0);
	struct tm * now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "%d/%m/%Y", now);
	return std::string(buffer);
}

Usuario* sistemaLogin::pesquisarUsuario(string pesquisa){
    if (_usuarios.count(pesquisa) == 1)   
        return _usuarios[pesquisa];
    int contador = 0;
    map<string, Usuario*>::iterator it;
    for(it=_usuarios.begin(); it!=_usuarios.end(); it++)
        if (it->second->getNome() == pesquisa){
            contador++;
            break;
        }
    if (contador != 0)
        return it->second;
    return nullptr;
}

void sistemaLogin::excluirUsuario(){
        cout << R"(
    ______          __      _         __  __             __       _     
   / ____/  _______/ /_  __(_)____   / / / /______  ____/_/______(_)___ 
  / __/ | |/_/ ___/ / / / / / ___/  / / / / ___/ / / / __ `/ ___/ / __ \
 / /____>  </ /__/ / /_/ / / /     / /_/ (__  ) /_/ / /_/ / /  / / /_/ /
/_____/_/|_|\___/_/\__,_/_/_/      \____/____/\__,_/\__,_/_/  /_/\____/)" << endl;
    string pesquisa;
    cout << "Digite o ID ou nome completo do usuário: " << endl;
    cin.ignore(1,'\n');
    getline(cin, pesquisa);
    Usuario *u = pesquisarUsuario(pesquisa);
    if (u != nullptr){ 
        cout << "O usuário " << u->getNome() << " foi excluído com sucesso!" << endl;
        _usuarios.erase(u->getId());
    } else
        throw UsuarioNaoCadastrado();
}

void sistemaLogin::cadastrarUsuario(){
        cout << R"(
   ______          __           __                     __  __             __       _     
  / ____/___ _____/ /___ ______/ /__________ ______   / / / /______  ____/_/______(_)___ 
 / /   / __ `/ __  / __ `/ ___/ __/ ___/ __ `/ ___/  / / / / ___/ / / / __ `/ ___/ / __ \
/ /___/ /_/ / /_/ / /_/ (__  ) /_/ /  / /_/ / /     / /_/ (__  ) /_/ / /_/ / /  / / /_/ /
\____/\__,_/\__,_/\__,_/____/\__/_/   \__,_/_/      \____/____/\__,_/\__,_/_/  /_/\____/)" << endl<<endl;
	cout << "+----------------------------------+" << endl;
	cout << "| " << "1 - Gerente                      |" << endl;
	cout << "| " << "2 - Funcionário                  |" << endl;
	cout << "| " << "3 - Voltar                       |" << endl;
	cout << "+----------------------------------+" << endl;
    cout << "Escolha qual tipo de usuário: ";
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaInvalida();
    char escolha = aux[0];
    switch (escolha){
        case '1':{
            string i = gerarID(), t = "Gerente", d = gerarDataAtual();
            string n, c, e, s;
            cout << "Digite o Nome completo: ";
            cin.ignore(1,'\n');
            getline(cin, n);
            if (n.size() > 26){
            throw ExcecaoTamanhoNomeAlt();
            }
            for (unsigned i = 0; i < n.size(); i++)
                if (n[i] == ' ')
                    n[i] = '_';
            cout << "Digite em sequência o CPF, Email, e Senha (separados por espaço)" << endl;
            cin >> c >> e >> s;
            if (c.size() > 23){
            throw ExcecaoTamanhoCPF();
            }else if (e.size() > 23) {
                throw ExcecaoTamanhoEmail();
            }if (s.size() > 23) {
                throw ExcecaoTamanhoSenha();
            }else{
                Usuario *u = new Gerente(i,t,n,c,e,d,s);
                _usuarios.insert(pair<string,Usuario*>(i,u));
                break;
            }
        }
        case '2':{
            string i = gerarID(), t = "Funcionario", d = gerarDataAtual();
            string n, c, e, s;
            cout << "Digite o Nome completo: ";
            cin.ignore(1,'\n');
            getline(cin, n);
            if (n.size() > 26){
            throw ExcecaoTamanhoNomeAlt();
            }
            for (unsigned i = 0; i < n.size(); i++)
                if (n[i] == ' ')
                    n[i] = '_';
            cout << "Digite em sequência o CPF, Email, e Senha (separados por espaço)" << endl;
            cin >> c >> e >> s;
               if (c.size() > 23){
            throw ExcecaoTamanhoCPF();
            }else if (e.size() > 23) {
                throw ExcecaoTamanhoEmail();
            }if (s.size() > 23) {
                throw ExcecaoTamanhoSenha();
            }else{
            Usuario *u = new Funcionario(i,t,n,c,e,d,s);
            _usuarios.insert(pair<string,Usuario*>(i,u));
            break;
            }
        }
        case '3':
            break;
	    default:
            throw EscolhaInvalida();
            break;
    }
}

Usuario* sistemaLogin::menuLogin(){
    limparTela("continuar");
    cout << R"(
    ____                    _    ___           __    
   / __ )___  ____ ___     | |  / (_)___  ____/ /___ 
  / __  / _ \/ __ `__ \    | | / / / __ \/ __  / __ \
 / /_/ /  __/ / / / / /    | |/ / / / / / /_/ / /_/ /
/_____/\___/_/ /_/ /_/     |___/_/_/ /_/\__,_/\____/)" << endl<< endl;
	cout << "+----------------------------------+" << endl;
	cout << "| " << "1 - Fazer Login                  |" << endl;
	cout << "| " << "2 - Encerrar Programa            |" << endl;
	cout << "+----------------------------------+" << endl;
    cout << "Escolha uma opcao: ";
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaInvalida();
    char escolha = aux[0];
    switch (escolha){
        case '1':{
            string usuario, senha;
            cout << "Digite o nome ou ID: ";
            cin.ignore(1,'\n');
            getline(cin, usuario);
            Usuario *u = pesquisarUsuario(usuario);
            if (u != nullptr){
                cout << "Digite a senha: ";
                cin >> senha;
                if (senha == u->getSenha()){
                    u->setUltimoAcesso(gerarDataAtual());
                    u->setEstaAutenticado(true);
                    limparTela("continuar");
                    cout << "Logado com sucesso :)" << endl;
                    return u;
                }else
                    throw SenhaIncorreta();
            }else{
                throw UsuarioNaoCadastrado();      
            	return nullptr;
            }
        }
        case '2':{
            exit(0);
       }
	default:
            throw EscolhaInvalida();
            return nullptr;
            break;
    }
}

void sistemaLogin::alterarUsuario(){ 
        cout << R"(
    ___    ____                          __  __             __       _     
   /   |  / / /____  _________ ______   / / / /______  ____/_/______(_)___ 
  / /| | / / __/ _ \/ ___/ __ `/ ___/  / / / / ___/ / / / __ `/ ___/ / __ \
 / ___ |/ / /_/  __/ /  / /_/ / /     / /_/ (__  ) /_/ / /_/ / /  / / /_/ /
/_/  |_/_/\__/\___/_/   \__,_/_/      \____/____/\__,_/\__,_/_/  /_/\____/ )" << endl; 
    string pesquisa;
    cout << "Digite o ID ou nome completo do usuário: ";
    cin.ignore(1,'\n');
    getline(cin, pesquisa);
    Usuario *u = pesquisarUsuario(pesquisa);
    if (u != nullptr){     
        u->alterarUsuario();
    } else
        throw UsuarioNaoCadastrado();     
}

void sistemaLogin::fazerLogout(Usuario *u){
    _usuarios[u->getId()] = u;
    u->setEstaAutenticado(false);
}

void sistemaLogin::limparTela(string modo){
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
