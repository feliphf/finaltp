#include "estoque.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

void Estoque::salvarArquivo(){
    fstream arquivo;
    string nomeFormatado;
    map<string, Produto>::iterator it;
    arquivo.open("database/Estoque.txt", ios::out);
    for(it=_estoque.begin(); it!=_estoque.end(); it++){
        nomeFormatado = (it->second).getNome();
        for (unsigned i = 0; i < nomeFormatado.size(); i++)
             if (nomeFormatado[i] == ' ')
                nomeFormatado[i] = '_';   
         arquivo<< nomeFormatado<<' '<< (it->second).getFabricante()<<' ' <<
        (it->second).getCategoria()<<' ' << (it->second).getCodigo()<<' ' << (it->second).getPreco()<<' ' << 
        (it->second).getQuantidade() << endl;
    }
    arquivo.close();
}

void Estoque::lerArquivo(){
    fstream arquivo;
    string nome, fabricante, categoria, codigo;
    float preco;
    int quantidade;
    arquivo.open("database/Estoque.txt",ios::in);
    if (arquivo.is_open())
    {
        while (arquivo >> nome >> fabricante >> categoria >> codigo >> preco >> quantidade){
            Produto p(nome, fabricante, categoria, codigo, preco, quantidade); 
           _estoque.insert(pair<string,Produto>(codigo,p));
        }
    }else{
        arquivo.open("database/Estoque.txt",ios::out);
        cout<<"Arquivo não havia sido encontrado, agora foi criado com sucesso"<<endl; // throw ExcecaoArquivoNaoEncontrado
    }    
    arquivo.close(); 
}

void Estoque::listarProdutos(){
    cout << R"(
    ____                 __      __                    __         ______     __                       
   / __ \_________  ____/ /_  __/ /_____  _____   ____/ /___     / ____/____/ /_____  ____ ___  _____ 
  / /_/ / ___/ __ \/ __  / / / / __/ __ \/ ___/  / __  / __ \   / __/ / ___/ __/ __ \/ __ `/ / / / _ \
 / ____/ /  / /_/ / /_/ / /_/ / /_/ /_/ (__  )  / /_/ / /_/ /  / /___(__  ) /_/ /_/ / /_/ / /_/ /  __/
/_/   /_/   \____/\__,_/\__,_/\__/\____/____/   \__,_/\____/  /_____/____/\__/\____/\__, /\__,_/\___/ 
                                                                                      /_/ )" << endl;
    map<string, Produto>::iterator it;
    //              14                   26                      23                       23                 12         9
    cout << "+--------------+--------------------------+-----------------------+-----------------------+------------+---------+"<< endl;
    cout << "|    CÓDIGO    |           NOME           |       CATEGORIA       |       FABRICANTE      | QUANTIDADE |  PREÇO  |"<< endl;
	cout << "+--------------+--------------------------+-----------------------+-----------------------+------------+---------+"<< endl;
    for(it=_estoque.begin(); it!=_estoque.end(); it++){
        cout << setprecision(2) << fixed << left << '|' << setw(14) << (it->second).getCodigo() <<  '|' << setw(26) << (it->second).getNome() <<  '|' << setw(23) <<
        (it->second).getCategoria() <<  '|' << setw(23) << (it->second).getFabricante() <<  '|' << setw(12) << (it->second).getQuantidade()
         <<  '|' << setw(9) << (it->second).getPreco() << '|' << endl;
        cout << "+--------------+--------------------------+-----------------------+-----------------------+------------+---------+"<< endl;
    }
}

void Estoque::pesquisarProduto(string pesquisa){
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        //              14                   26                      23                       23                 12         9
        cout << "+--------------+--------------------------+-----------------------+-----------------------+------------+---------+"<< endl;
        cout << "|    CÓDIGO    |           NOME           |       CATEGORIA       |       FABRICANTE      | QUANTIDADE |  PREÇO  |"<< endl;
        cout << "+--------------+--------------------------+-----------------------+-----------------------+------------+---------+"<< endl;
        cout << setprecision(2) << left << fixed << '|' << setw(14) << (it->second).getCodigo() <<  '|' << setw(26) << (it->second).getNome() <<  '|' << setw(23) <<
        (it->second).getCategoria() <<  '|' << setw(23) << (it->second).getFabricante() <<  '|' << setw(12) << (it->second).getQuantidade()
        <<  '|' << setw(9) << (it->second).getPreco() << '|' << endl;
        cout << "+--------------+--------------------------+-----------------------+-----------------------+------------+---------+"<< endl;
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::alterarNomeProduto(string pesquisa, string nome){ 
      if (_estoque.count(pesquisa) == 1)
      {
        if (nome.size() > 20)
	{
            throw ExcecaoTamanhoNomeAlt();
        }else
        {
	   map<string, Produto>::iterator it = _estoque.find(pesquisa);
           cout<<"O nome do produto foi alterado de "<<(it->second).getNome()<<" para "<<nome<<endl;
	   (it->second).setNome(nome);
	}
      }else
        throw ProdutoNaoCadastrado();
}


void Estoque::alterarFabricanteProduto(string pesquisa, string fabric){
      if (_estoque.count(pesquisa) == 1)
      {
        if (fabric.size() > 20)
	{
            throw ExcecaoTamanhoFabricAlt();
        }else
	{
            map<string, Produto>::iterator it = _estoque.find(pesquisa);
            cout<<"O fabricante do produto foi alterado de "<<(it->second).getFabricante()<<" para "<<fabric<<endl;
           (it->second).setFabricante(fabric);
	}
      }else
        throw ProdutoNaoCadastrado();
}


void Estoque::alterarCategoriaProduto(string pesquisa, string categ){
      if (_estoque.count(pesquisa) == 1)
      {
       	if (categ.size() > 20)
        {
           throw ExcecaoTamanhoCategAlt();
        }else
	{
           map<string, Produto>::iterator it = _estoque.find(pesquisa);
           cout<<"A categoria do produto foi alterada de "<<(it->second).getCategoria()<<" para "<<categ<<endl;
           (it->second).setCategoria(categ);
      	}
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::alterarPrecoProduto(string pesquisa, float preco){
      if (_estoque.count(pesquisa) == 1)
      {
         if (preco < 0){
		throw ExcecaoPrecoNegativoAlt();
	    }else
        {
	    map<string, Produto>::iterator it = _estoque.find(pesquisa);
            cout<< fixed <<setprecision(2)<<"O preço do produto foi alterado de "<<(it->second).getPreco()<<" para "<<preco<<endl;
            (it->second).setPreco(preco);
     	} 
      }else
          throw ProdutoNaoCadastrado();
}

void Estoque::alterarProduto(){
    cout << R"(
    ___    ____                                               __      __      
   /   |  / / /____  _________ ______   ____  _________  ____/ /_  __/ /_____ 
  / /| | / / __/ _ \/ ___/ __ `/ ___/  / __ \/ ___/ __ \/ __  / / / / __/ __ \
 / ___ |/ / /_/  __/ /  / /_/ / /     / /_/ / /  / /_/ / /_/ / /_/ / /_/ /_/ /
/_/  |_/_/\__/\___/_/   \__,_/_/     / .___/_/   \____/\__,_/\__,_/\__/\____/ 
                                    /_/)" << endl;
    std::string codigoProdutoAlterado;
    std::string novaString;
    float novoFloat;
    map<string, Produto>::iterator it;
	std::cout << "+-----------------------------+"<<std::endl;
	std::cout << "| " << "1 - Nome                    |" << std::endl;
	std::cout << "| " << "2 - Categoria               |" << std::endl;
	std::cout << "| " << "3 - Fabricante              |" << std::endl;
	std::cout << "| " << "4 - Preço                   |" << std::endl;
	std::cout << "| " << "5 - Sair                    |" << std::endl;
	std::cout << "+-----------------------------+"<<std::endl;
    string aux;
    std::cout << "Escolha o que deseja alterar: ";
    cin >> aux;
    if (aux.size()>1)
        throw EntradaInvalida();
    char escolha = aux[0];
    switch (escolha)
    {
    case '1':
        std::cout<<"Digite o código do produto que será alterado: ";
        std::cin>>codigoProdutoAlterado;
        if (_estoque.count(codigoProdutoAlterado)==1)    
            it = _estoque.find(codigoProdutoAlterado); 
        else{
            throw ProdutoNaoCadastrado();
            break;
        }
        std::cout<<"Digite um novo nome para "<<(it->second).getNome() <<" : ";
        cin.ignore(1,'\n');
        getline(cin, novaString);
		alterarNomeProduto(codigoProdutoAlterado,novaString);
        break;
	
    case '2':
        std::cout<<"Digite o código do produto que será alterado: ";
        std::cin>>codigoProdutoAlterado;
        if (_estoque.count(codigoProdutoAlterado)==1)    
            it = _estoque.find(codigoProdutoAlterado); 
        else{
            throw ProdutoNaoCadastrado();
            break;
        }
        std::cout<<"Digite uma nova categoria para "<<(it->second).getNome()<<" : ";
        std::cin>>novaString;
		alterarCategoriaProduto(codigoProdutoAlterado,novaString);
        break;
	
    case '3':
        std::cout<<"Digite o código do produto que será alterado: ";
        std::cin>>codigoProdutoAlterado;
        if (_estoque.count(codigoProdutoAlterado)==1)    
            it = _estoque.find(codigoProdutoAlterado); 
        else{
            throw ProdutoNaoCadastrado();
            break;
        }
        std::cout<<"Digite um novo fabricante para "<<(it->second).getNome()<<" : ";
        std::cin>>novaString;
		alterarFabricanteProduto(codigoProdutoAlterado,novaString);
        break;
	
    case '4':
        std::cout<<"Digite o código do produto que será alterado: ";
        std::cin>>codigoProdutoAlterado;
        if (_estoque.count(codigoProdutoAlterado)==1)    
            it = _estoque.find(codigoProdutoAlterado); 
        else{
            throw ProdutoNaoCadastrado();
            break;
        }
        std::cout<<"Digite um novo preço para "<<(it->second).getNome()<<" : ";
        std::cin>>novoFloat;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw PrecoNaoENumero();
            break;
        }else
        
        	alterarPrecoProduto(codigoProdutoAlterado,novoFloat);

        break;     

    case '5':
        break;
        
    default:
        throw EntradaInvalida();
        alterarProduto();
        break;
    }
}

void Estoque::cadastroDeProdutos(){
    cout << R"(
   ______          __           __                    __                             __      __      
  / ____/___ _____/ /___ ______/ /__________     ____/ /__     ____  _________  ____/ /_  __/ /_____ 
 / /   / __ `/ __  / __ `/ ___/ __/ ___/ __ \   / __  / _ \   / __ \/ ___/ __ \/ __  / / / / __/ __ \
/ /___/ /_/ / /_/ / /_/ (__  ) /_/ /  / /_/ /  / /_/ /  __/  / /_/ / /  / /_/ / /_/ / /_/ / /_/ /_/ /
\____/\__,_/\__,_/\__,_/____/\__/_/   \____/   \__,_/\___/  / .___/_/   \____/\__,_/\__,_/\__/\____/ 
                                                           /_/)" << endl;
    string n,co,f,ca;
    float p;
    cout << "Digite o Nome: ";
    cin.ignore(1,'\n');
    getline(cin, n);
    if (n.size() > 20){
        throw ExcecaoTamanhoNomeAlt();
    }
    cout << "Digite em sequência o Código, Fabricante, Categoria e Preço (separados por espaço)" << endl;
    cin >> co >> f >> ca >> p;
    if (_estoque.count(co) == 0){
        if (f.size() > 20) {
            std::cin.clear();
            std::cin.ignore();
            throw ExcecaoTamanhoFabricAlt();
        }else if (ca.size() > 20) {
            std::cin.clear();
            std::cin.ignore();
            throw ExcecaoTamanhoCategAlt();
        }else if (p < 0) {
            std::cin.clear();
            std::cin.ignore();
            throw ExcecaoPrecoNegativoAlt();
        }else if(!cin){
            std::cin.clear();
            std::cin.ignore();
            throw PrecoNaoENumero();
        }else{
            Produto produto(n, f, ca, co, p,0);
            _estoque.insert(pair<string,Produto>(co, produto));
            std::cout<<"O produto "<<produto.getNome()<<" foi cadastrado com sucesso"<<std::endl;
            limparTela("perguntar");
        } 
    }else{
        std::cin.clear();
        std::cin.ignore();
        throw ProdutoJaCadastrado();
    }
}


void Estoque::entradasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual){
    if (_estoque.count(codig) == 1){
        map<string, Produto>::iterator it = _estoque.find(codig);
        int quantidade;
        quantidade=(it->second).getQuantidade();
        quantidade+=quant;
        (it->second).setQuantidade(quantidade);
        string cout_string;
        cout_string = "Foram adicionadas " + std::to_string(quant) + " unidades do produto "+(it->second).getNome();
        cout << "Foram adicionadas " << quant << " unidades do produto "<<(it->second).getNome()<<" com sucesso."<< endl;
        gerarLog(cout_string, nomeUsuario, dataAtual);
    }else{
        cout << "Produto não cadastrado, cadastre o produto antes de adicionar ao estoque" << endl;
        limparTela("perguntar");
    }
}
    
void Estoque::saidasDeProdutos(string codig, int quant, string nomeUsuario, string dataAtual){
    if (_estoque.count(codig) == 1){
        map<string, Produto>::iterator it = _estoque.find(codig);
        int quantidade;
        quantidade = (it->second).getQuantidade();
        quantidade -= quant;
        (it->second).setQuantidade(quantidade);
        string cout_string;
        cout_string = "Foram retiradas " + std::to_string(quant) + " unidades do produto "+(it->second).getNome();
        cout << "Foram retiradas " << quant << " unidades do produto "<<(it->second).getNome()<<" com sucesso."<< endl;
        gerarLog(cout_string, nomeUsuario, dataAtual);
    }else{
        cout << "Produto não cadastrado, não poderá ser retirado" << endl;
        limparTela("perguntar");
    }
}

void Estoque::gerarLog(string mensagem, string nomeUsuario, string dataAtual){
   fstream arquivo;
    arquivo.open("database/Movimentacoes.txt", ios::out | ios::app);
    arquivo<< mensagem<<" por "<<nomeUsuario<<" no dia " <<dataAtual<< endl;
    arquivo.close();
}

void Estoque::imprimirLog(){
  fstream arquivo;  
  arquivo.open("database/Movimentacoes.txt",ios::in);
    if (arquivo.is_open())
    {
    cout << R"(
  _   _ _     _    __       _                 _                             _                      _                            
 | | | (_)___| |_ /_/  _ __(_) ___ ___     __| | ___   _ __ ___   _____   _(_)_ __ ___   ___ _ __ | |_ __ _  ___ ___   ___  ___ 
 | |_| | / __| __/ _ \| '__| |/ __/ _ \   / _` |/ _ \ | '_ ` _ \ / _ \ \ / / | '_ ` _ \ / _ \ '_ \| __/ _` |/ __/ _ \ / _ \/ __|
 |  _  | \__ \ || (_) | |  | | (_| (_) | | (_| |  __/ | | | | | | (_) \ V /| | | | | | |  __/ | | | || (_| | (_| (_) |  __/\__ \
 |_| |_|_|___/\__\___/|_|  |_|\___\___/   \__,_|\___| |_| |_| |_|\___/ \_/ |_|_| |_| |_|\___|_| |_|\__\__,_|\___\___/ \___||___/
                                                                                                             )_))" << endl;
      cout<<arquivo.rdbuf()<<endl;
    }else{
        arquivo.open("database/Movimentacoes.txt",ios::out);
        cout<<"Arquivo não havia sido encontrado, agora foi criado com sucesso"<<endl; // throw ExcecaoArquivoNaoEncontrado
    }    
    arquivo.close();
}

void Estoque::menuEntradaESaidaDeProdutos(std::list<pair<unsigned int,pair<Produto,int>>>& listaQuantidades,
 std::string modo, bool& loop,unsigned int& count, string nomeUsuario, string dataAtual){
    int qtd;
    unsigned int posicao;
    std::string codigoProduto;
    std::list<pair<unsigned int,pair<Produto,int>>>::iterator itItem;
    map<string, Produto>::iterator it;
    if (modo=="entrada")
    {
        cout << R"(
  ___          _    _                _               _               _         
 | _ \___ __ _(_)__| |_ _ _ ___   __| |___   ___ _ _| |_ _ _ __ _ __| |__ _ ___
 |   / -_) _` | (_-<  _| '_/ _ \ / _` / -_) / -_) ' \  _| '_/ _` / _` / _` (_-<
 |_|_\___\__, |_/__/\__|_| \___/ \__,_\___| \___|_||_\__|_| \__,_\__,_\__,_/__/
         |___/ )" << endl;
    }else if (modo=="saida")
    {
         cout << R"(
  ___          _    _                _                __   _         
 | _ \___ __ _(_)__| |_ _ _ ___   __| |___   ___ __ _/_/__| |__ _ ___
 |   / -_) _` | (_-<  _| '_/ _ \ / _` / -_) (_-</ _` | / _` / _` (_-<
 |_|_\___\__, |_/__/\__|_| \___/ \__,_\___| /__/\__,_|_\__,_\__,_/__/
         |___/)" << endl;
    }
    
    std::cout << "+-----------------------------------+"<<std::endl;
    std::cout << "| " << "1 - Adicionar produto à lista     |" << std::endl;
    std::cout << "| " << "2 - Remover produto da lista      |" << std::endl;
    std::cout << "| " << "3 - Exibir lista                  |" << std::endl;
    std::cout << "| " << "4 - Finalizar lista               |" << std::endl;
    std::cout << "| " << "5 - Cancelar lista                |" << std::endl;
    std::cout << "+-----------------------------------+"<<std::endl;
    std::cout << "Escolha uma opção: ";
    string aux;
    cin >> aux;
    if (aux.size()>1)
        throw EntradaInvalida();
    char escolha = aux[0];
    switch (escolha){
    case '1':
        std::cout<<"Digite o código do produto que será adicionado: ";
        std::cin>>codigoProduto;
        if(_estoque.count(codigoProduto)==0){
            throw ProdutoNaoCadastrado();
        }
        std::cout<<"Digite a quantidade do produto que será adicionada: ";
        std::cin>>qtd;
        it = _estoque.find(codigoProduto);
        if(qtd<0){
            throw quantidadeInvalida();
        }else if (qtd == 0){
            throw ProdutoNaoRetirado();
        }else if((it->second).getQuantidade()<qtd && modo == "saida"){
            throw TentativaDeRetirada();
        }        
        listaQuantidades.push_back(make_pair(count,make_pair(it->second,qtd)));
        count++;
        limparTela("continuar");
        std::cout<<"O produto "<<(it->second).getNome()<<" foi adicionado à lista com quantidade "<<qtd<<std::endl;
        break;
    
    case '2':
        if(listaQuantidades.empty()){
            std::cout << "Nenhum item adicionado!!" << std::endl;
            limparTela("perguntar");
        }else{
            std::cout<<"Digite qual item será removido: ";
            std::cin>>posicao;
            if (posicao < 1 || posicao >= count){
                std::cout << "Posição inválida! Digite um número de 1 até "<< (count - 1) << std::endl;
                limparTela("perguntar");
            }
            else{
                int auxiliar = 0;
                for (itItem = listaQuantidades.begin(); itItem != listaQuantidades.end() ; itItem++)
                {
                    if((itItem->first)==posicao){
                        auxiliar++;
                        listaQuantidades.erase(itItem);
                        std::cout<<"O item "<<posicao<<" foi retirado da lista"<<std::endl;
                        limparTela("continuar");
                        break;
                }
                if (auxiliar == 0){
                    std::cout << "Item já removido da lista!!" << std::endl;
                    limparTela("perguntar");
                }
            }
          }
        }
        break;
    
    case '3':
        if(listaQuantidades.empty()){
            std::cout << "Nenhum item adicionado!!" << std::endl;
            limparTela("perguntar");
        }else{
            limparTela("continuar");
            cout << R"(
    ___      __               __                             __      __            
   / (_)____/ /_____ _   ____/ /__     ____  _________  ____/ /_  __/ /_____  _____
  / / / ___/ __/ __ `/  / __  / _ \   / __ \/ ___/ __ \/ __  / / / / __/ __ \/ ___/
 / / (__  ) /_/ /_/ /  / /_/ /  __/  / /_/ / /  / /_/ / /_/ / /_/ / /_/ /_/ (__  ) 
/_/_/____/\__/\__,_/   \__,_/\___/  / .___/_/   \____/\__,_/\__,_/\__/\____/____/  
                                   /_/ )" << endl;
            cout << "+----+---------------------+---------------------+------------+"<< endl;
            cout << "| ID |       CÓDIGO        |       PRODUTO       | QUANTIDADE |"<< endl;
            cout << "+----+---------------------+---------------------+------------+"<< endl;
            for(itItem=listaQuantidades.begin(); itItem!=listaQuantidades.end(); itItem++){
                cout << left << '|' << setw(4) << itItem->first <<  '|' << setw(21) << itItem->second.first.getCodigo() <<  '|' << setw(21) <<
                itItem->second.first.getNome() <<  '|' << setw(12) << itItem->second.second;
                cout << '|' << endl;
                cout << "+----+---------------------+---------------------+------------+"<< endl;
                }
        }
        limparTela("perguntar");
        break;

    case '4':
        limparTela("continuar");
        if(listaQuantidades.empty()){
            std::cout << "Nenhum item adicionado!!" << std::endl;
            limparTela("perguntar");
        }else{
            for(itItem=listaQuantidades.begin(); itItem!=listaQuantidades.end(); itItem++){
                if (modo=="entrada"){
                    entradasDeProdutos(((itItem->second).first.getCodigo()),((itItem->second).second),nomeUsuario,dataAtual);
                }else if(modo=="saida"){
                    saidasDeProdutos(((itItem->second).first.getCodigo()),((itItem->second).second),nomeUsuario,dataAtual);
                }
            }
            std::cout<<"O estoque foi atualizado com sucesso"<<std::endl;
            loop = false;
            listaQuantidades.clear();
            limparTela("perguntar");
        }
        break;    

    case '5':
        listaQuantidades.clear();
        std::cout<<"Lista excluída com sucesso"<<std::endl;
        loop = false;
        limparTela("perguntar");
        break;
        
    default:
        std::cout<<"Entrada inválida, digite um número de 1 a 5"<<std::endl;
        limparTela("perguntar");
        break;
    }
}

void Estoque::excluirProduto(string codigo){
    if (_estoque.count(codigo) == 1)
      { 
        cout<<"O produto "<< ((_estoque.find(codigo))->second).getNome()<<" foi removido com sucesso!"<<endl;
         _estoque.erase(codigo);
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::limparTela(string modo){
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
