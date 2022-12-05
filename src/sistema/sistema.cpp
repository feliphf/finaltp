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
            int count=1;
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
            int count=1;
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
            string n,co,f,ca;
            float p;
            cout << "Digite o Nome: ";
            cin.ignore(1,'\n');
            getline(cin, n);
            cout << "Digite em sequência o Código, Fabricante, Categoria e Preço (separados por espaço)" << endl;
            cin >> co >> f >> ca >> p;
            if (cin.fail()){
            cin.clear();
            cin.ignore();
            throw PrecoNaoENumero();
          //  }else if (p < 0) {
          //  throw ExcecaoPrecoNegativoAlt();
          //  }if (f.size() > 20) {
          //  throw ExcecaoTamanhoFabricAlt();
         //   }if (ca.size() > 20) {
          //  throw ExcecaoTamanhoCategAlt();
           // }
           // if (n.size() > 20){
           // throw ExcecaoTamanhoNomeAlt();
            //}
            try
            {
                _estoque.cadastroDeProdutos(co,n,f,ca,p);
            }
            catch(ExcecaoTamanhoNomeAlt& erro){
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
        }
        break;
        }
        case '3':{
            string codigo;
            cout<<"Digite o código do produto que será removido: ";
            cin>>codigo;
            _estoque.excluirProduto(codigo);
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
    switch(escolha){
        case '1':{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            int count=1;
            while(loop){ 
                try{
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "saida", loop, count,_usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
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
            break;
        }
        case '2':{
            string s;
            cout << "Digite o código do produto: ";
            cin >> s;
            try{
                _estoque.pesquisarProduto(s);
            }catch(ProdutoNaoCadastrado& erro){
                cout<<erro.what()<<endl;
                limparTela("perguntar");
            }
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
            }
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
