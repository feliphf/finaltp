#include "sistema.hpp"

void Sistema::inicializarParametrosSistema(){
    _estoque.lerArquivo();
    _sistemaLogin.limparMemoria();
    _sistemaLogin.lerArquivo();
}

void Sistema::salvarParametrosSistema(){
    _estoque.salvarArquivo();
    _sistemaLogin.salvarArquivo();
}

void Sistema::efetuarLogin(){
    do{
       try{
            _usuarioLogado = _sistemaLogin.menuLogin();
       }catch(SenhaIncorreta& erro){
            cout<<erro.what()<<endl;
            limparTela("perguntar");     
       }catch(UsuarioNaoCadastrado& erro){
            cout<<erro.what()<<endl;
            limparTela("perguntar");     
       }catch(EscolhaInvalida& erro){
            cout<<erro.what()<<endl;
            limparTela("perguntar");     
       }
    } while(_usuarioLogado == nullptr);
}

void Sistema::opcoesMenuGerente(){
    _usuarioLogado->menuInicial();
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaSistemaInvalida();
    char escolha = aux[0];
    limparTela("continuar");
    switch(escolha){
        case '1':{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            unsigned int count=1;
            while(loop){
                try{   
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "saida", loop, count, _usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
                }catch(ProdutoNaoCadastrado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(EntradaInvalida& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(quantidadeInvalida& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(TentativaDeRetirada& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(ProdutoNaoRetirado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }
            }
            limparTela("continuar");
            break;
        }
        case '2':{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            unsigned int count=1;
            while(loop){   
                try{
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "entrada", loop, count,_usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
                }catch(ProdutoNaoCadastrado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(EntradaInvalida& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(quantidadeInvalida& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(TentativaDeRetirada& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(ProdutoNaoRetirado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }
            }
            limparTela("continuar");
            break;
        }
        case '3':{
            cout << R"(
   ______                       ____                ____                 __      __      
  / ____/___  ____  _______  __/ / /_____ ______   / __ \_________  ____/ /_  __/ /_____ 
 / /   / __ \/ __ \/ ___/ / / / / __/ __ `/ ___/  / /_/ / ___/ __ \/ __  / / / / __/ __ \
/ /___/ /_/ / / / (__  ) /_/ / / /_/ /_/ / /     / ____/ /  / /_/ / /_/ / /_/ / /_/ /_/ /
\____/\____/_/ /_/____/\__,_/_/\__/\__,_/_/     /_/   /_/   \____/\__,_/\__,_/\__/\____/ )" << endl << endl;
            string s;
            cout << "Digite o código do produto: ";
            cin >> s;
            try{
                 _estoque.pesquisarProduto(s);   
            }catch(ProdutoNaoCadastrado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                    break;     
            }
            limparTela("perguntar");
            break;
        }
        case '4':{
            _estoque.listarProdutos();
            limparTela("perguntar");
            break;
        }
        case '5':{
            _estoque.imprimirLog();
            limparTela("perguntar");
            break;
        }
        case '6':{
            try{
                opcoesMenuAdministrativo();
            }catch(EscolhaSistemaInvalida& erro){
                    cout<<erro.what()<<endl;     
                    limparTela("perguntar");
                    break;
            }
            //limparTela("perguntar");
            break;
        }
        case '7':
            _sistemaLogin.fazerLogout(_usuarioLogado);
            break;
        default:
            throw EscolhaSistemaInvalida();
            break;
    }
}

void Sistema::opcoesMenuAdministrativo(){
    _usuarioLogado->menuAdministrativo();
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaSistemaInvalida();
    char escolha = aux[0];
    limparTela("continuar");
    switch(escolha){
        case '1':
            try{
                _estoque.alterarProduto();
            }catch(ProdutoNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;   
            }catch(EntradaInvalida& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoNomeAlt& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoCategAlt& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoFabricAlt& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(PrecoNaoENumero& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoPrecoNegativoAlt& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }
            limparTela("perguntar");
            break;
        case '2':{
            try{
                _estoque.cadastroDeProdutos();
            }catch(ExcecaoTamanhoNomeAlt& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }catch(ExcecaoTamanhoCategAlt& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }catch(ExcecaoTamanhoFabricAlt& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }catch(ExcecaoPrecoNegativoAlt& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }catch(PrecoNaoENumero& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }catch(ProdutoJaCadastrado& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }
            limparTela("continuar");
            break;

        }
        case '3':{
            cout << R"(
    ______          __      _         ____                 __      __      
   / ____/  _______/ /_  __(_)____   / __ \_________  ____/ /_  __/ /_____ 
  / __/ | |/_/ ___/ / / / / / ___/  / /_/ / ___/ __ \/ __  / / / / __/ __ \
 / /____>  </ /__/ / /_/ / / /     / ____/ /  / /_/ / /_/ / /_/ / /_/ /_/ /
/_____/_/|_|\___/_/\__,_/_/_/     /_/   /_/   \____/\__,_/\__,_/\__/\____/ )" << endl << endl;
            string codigo;
            cout<<"Digite o código do produto que será removido: ";
            cin>>codigo;
            try{
            _estoque.excluirProduto(codigo);
            }catch(ProdutoNaoCadastrado& e){
                cout<<e.what()<<endl;
                limparTela("perguntar");
                break;
            }
            limparTela("perguntar");
            break;
        }
        case '4':
            try{
                _sistemaLogin.alterarUsuario();
            }catch(UsuarioNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(EscolhaInvalida& e){
                cout<<e.what()<<endl;
                limparTela("perguntar");
                break;
            }catch(ExcecaoTamanhoNomeAlt& e){
                cout<<e.what()<<endl;
                limparTela("perguntar");
                break;
            }catch(ExcecaoTamanhoCPF& e){
                cout<<e.what()<<endl;
                limparTela("perguntar");
                break;
            }catch(ExcecaoTamanhoEmail& e){
                cout<<e.what()<<endl;
                limparTela("perguntar");
                break;
            }catch(ExcecaoTamanhoSenha& e){
                cout<<e.what()<<endl;
                limparTela("perguntar");
                break;
            }
            limparTela("perguntar");
            break;
        case '5':
            _sistemaLogin.listarUsuarios();
            break;
        case '6':
            try{
                _sistemaLogin.cadastrarUsuario();
            }catch(EscolhaInvalida& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoNomeAlt& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoCPF& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoEmail& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoSenha& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }
            limparTela("perguntar");
            break;
        case '7':
            try{
                _sistemaLogin.excluirUsuario();
            }catch(UsuarioNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }
            limparTela("perguntar");
            break;
        case '8':
            salvarParametrosSistema();
            break;
        default:
            throw EscolhaSistemaInvalida();
            break;
    }       
}

void Sistema::opcoesMenuFuncionario(){
    _usuarioLogado->menuInicial();
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EscolhaSistemaInvalida();
    char escolha = aux[0];
    limparTela("continuar");
    switch(escolha){
        case '1':{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            unsigned int count=1;
            while(loop){
                try{   
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "saida", loop, count, _usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
                }catch(ProdutoNaoCadastrado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(EntradaInvalida& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(quantidadeInvalida& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(TentativaDeRetirada& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }catch(ProdutoNaoRetirado& erro){
                    cout<<erro.what()<<endl;
                    limparTela("perguntar");
                }
            }
            limparTela("continuar");
            break;
        }
        case '2':{
            cout << R"(
   ______                       ____                ____                 __      __      
  / ____/___  ____  _______  __/ / /_____ ______   / __ \_________  ____/ /_  __/ /_____ 
 / /   / __ \/ __ \/ ___/ / / / / __/ __ `/ ___/  / /_/ / ___/ __ \/ __  / / / / __/ __ \
/ /___/ /_/ / / / (__  ) /_/ / / /_/ /_/ / /     / ____/ /  / /_/ / /_/ / /_/ / /_/ /_/ /
\____/\____/_/ /_/____/\__,_/_/\__/\__,_/_/     /_/   /_/   \____/\__,_/\__,_/\__/\____/ )" << endl << endl;
            string s;
            cout << "Digite o código do produto: ";
            cin >> s;
            try{
                _estoque.pesquisarProduto(s);
            }catch(ProdutoNaoCadastrado& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
                break;
            }
            limparTela("perguntar");
            break;
        }
        case '3':{
            _estoque.listarProdutos();
            limparTela("perguntar");
            break;
        }
        case '4':{
            try{
                _usuarioLogado->alterarUsuarioLogado();
            }catch(EscolhaInvalida & erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }catch(ExcecaoTamanhoSenha & erro){
                  cout<<erro.what()<<endl;
                  limparTela("perguntar");
                  break;
            }
            limparTela("perguntar");
            break;
        }
        case '5':
            _sistemaLogin.fazerLogout(_usuarioLogado);
            break;
        default:
            throw EscolhaSistemaInvalida();
            break;
    }
}

void Sistema::inicializarSistema(){
    while(1){
        inicializarParametrosSistema();
        if(_usuarioLogado == nullptr){
            efetuarLogin();
        } else {
            if(_usuarioLogado->temPermissao()){
                try{
                    opcoesMenuGerente();
                }catch(EscolhaSistemaInvalida& erro){
                    cout<<erro.what()<<endl;  
                    limparTela("perguntar");   
                }catch(EntradaInvalida& erro){
                    cout<<erro.what()<<endl;  
                    limparTela("perguntar");   
                }
            } else {
                try{
                    opcoesMenuFuncionario(); 
                }catch(EscolhaSistemaInvalida& erro){
                    cout<<erro.what()<<endl; 
                    limparTela("perguntar");    
                }catch(EntradaInvalida& erro){
                    cout<<erro.what()<<endl;  
                    limparTela("perguntar");  
                }
            }
            salvarParametrosSistema();
            if (!_usuarioLogado->getEstaAutenticado())
                _usuarioLogado = nullptr;
        }
    }
}


void Sistema::limparTela(string modo){
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
