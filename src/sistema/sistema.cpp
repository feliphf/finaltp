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
        }catch(UsuarioNaoCadastrado& erro){
            cout<<erro.what()<<endl;     
        }catch(EscolhaInvalida& erro){
            cout<<erro.what()<<endl;     
        }
    } while(_usuarioLogado == nullptr);
}

void Sistema::opcoesMenuGerente(){
    _usuarioLogado->menuInicial();
    int escolha;
    cin >> escolha;
    switch(escolha){
        case 1:{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            int count=1;
            while(loop){   
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "saida", loop, count, _usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
            }
            break;
        }
        case 2:{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            int count=1;
            while(loop){   
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "entrada", loop, count,_usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
            }
            break;
        }
        case 3:{
            string s;
            cout << "Digite o código do produto: ";
            cin >> s;
            try{
                 _estoque.pesquisarProduto(s);   
            }catch(ProdutoNaoCadastrado& erro){
                    cout<<erro.what()<<endl;     
            }
            break;
        }
        case 4:{
            _estoque.listarProdutos();
            limparTela("perguntar");
            break;
        }
        case 5:{
            _estoque.imprimirLog();
            limparTela("perguntar");
            break;
        }
        case 6:{
            try{
                opcoesMenuAdministrativo();
            }catch(EscolhaSistemaInvalida& erro){
                    cout<<erro.what()<<endl;     
            }
            break;
        }
        case 7:
            _sistemaLogin.fazerLogout(_usuarioLogado);
            break;
        }
        default:
            throw EscolhaSistemaInvalida();
            break;
}

void Sistema::opcoesMenuAdministrativo(){
    _usuarioLogado->menuAdministrativo();
    int escolha;
    cin >> escolha;
    switch(escolha){
        case 1:
            try{
                _estoque.alterarProduto();
            }catch(EntradaInvalida& erro){
                  cout<<erro.what()<<endl;
            }
            break;
        case 2:
            try{
                _sistemaLogin.alterarUsuario();
            }catch(UsuarioNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
            }
            break;
        case 5:
            _sistemaLogin.listarUsuarios();
            break;
        case 4:
            _sistemaLogin.cadastrarUsuario();
            break;
        case 5:
            _sistemaLogin.excluirUsuario();
            break;
        case 8:
            salvarParametrosSistema();
            break;
        default:
            throw EscolhaInvalida();
            break;
    }    
}

void Sistema::opcoesMenuFuncionario(){
    _usuarioLogado->menuInicial();
    int escolha;
    cin >> escolha;
    switch(escolha){
        case 1:{
            bool loop=true;
            std::list<pair<unsigned int,pair<Produto,int>>> listaQuantidades;
            int count=1;
            while(loop){   
                _estoque.menuEntradaESaidaDeProdutos(listaQuantidades, "saida", loop, count,_usuarioLogado->getNome(), _usuarioLogado->getUltimoAcesso());
            }
            break;
        }
        case 2:{
            string s;
            cout << "Digite o código do produto: ";
            cin >> s;
            try{
                _estoque.pesquisarProduto(s);
            }catch(ProdutoNaoCadastrado& erro){
                cout<<erro.what()<<endl;
            }
            break;
        }
        case 3:{
            _estoque.listarProdutos();
            limparTela("perguntar");
            break;
        }
        case 4:{
            try{
                _usuarioLogado->alterarUsuarioLogado();
            }catch(EscolhaInvalida & erro){
                  cout<<erro.what()<<endl;
            }
            break;
        }
        case 5:{
            _sistemaLogin.fazerLogout(_usuarioLogado);
            break;
        }
        default:
            throw EscolhaInvalida();
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
                }
            } else {
                try{
                    opcoesMenuFuncionario(); 
                }catch(EscolhaSistemaInvalida& erro){
                    cout<<erro.what()<<endl;     
                }
            }
            salvarParametrosSistema();
            if (!_usuarioLogado->getEstaAutenticado())
                _usuarioLogado = nullptr;
        }
    }
}