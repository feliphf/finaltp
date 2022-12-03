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
        _usuarioLogado = _sistemaLogin.menuLogin();
    } while(_usuarioLogado == nullptr);
}

void Sistema::opcoesMenuGerente(){
    _usuarioLogado->menuInicial();
    int escolha;
    cin >> escolha;
    switch(escolha){
        case 1:{
            //registrar venda
            break;
        }
        case 2:{
            //registrar compra
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
            break;
        }
        case 5:{
            //relatório
            break;
        }
        case 6:{
            opcoesMenuAdministrativo();
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
            _estoque.alterarProduto();
            break;
        case 2:
            _sistemaLogin.alterarUsuario();
            break;
        case 3:
            _sistemaLogin.listarUsuarios();
            break;
        case 4:
            _sistemaLogin.cadastrarUsuario();
            break;
        case 5:
            _sistemaLogin.excluirUsuario();
            break;
        case 6:
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
            //registrar venda
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
            break;
        }
        case 4:{
            _usuarioLogado->alterarUsuarioLogado();
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
                opcoesMenuGerente();
            } else {
                opcoesMenuFuncionario(); 
            }
            salvarParametrosSistema();
            if (!_usuarioLogado->getEstaAutenticado())
                _usuarioLogado = nullptr;
        }
    }
}
