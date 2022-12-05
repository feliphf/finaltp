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
    map<string, Produto>::iterator it;
    cout << left << setw(21) << "Nome" << setw(21) << "Fabricante"<< setw(21) <<
        "Categoria"<< setw(21) << "Código" << setw(21) << "Preço" << setw(10) <<
        "Quantidade" << endl << fixed << showpoint;
    cout << endl;
    for(it=_estoque.begin(); it!=_estoque.end(); it++){
        cout << setprecision(2) << left << setw(21) << (it->second).getNome() << setw(21) << (it->second).getFabricante() << setw(21) <<
        (it->second).getCategoria() << setw(21) << (it->second).getCodigo() << setw(21) << (it->second).getPreco() << setw(10) << right <<
        (it->second).getQuantidade() << endl;
    }
}

void Estoque::pesquisarProduto(string pesquisa){
      if (_estoque.count(pesquisa) == 1)
      {
        map<string, Produto>::iterator it = _estoque.find(pesquisa);
        cout << left << setw(21) << "Nome" << setw(21) << "Fabricante"<< setw(21) <<
        "Categoria"<< setw(21) << "Código" << setw(21) << "Preço" << setw(10) <<
        "Quantidade" << endl << fixed << showpoint;
        cout << endl;
        cout << setprecision(2) << left << setw(21) << (it->second).getNome() << setw(21) << (it->second).getFabricante() << setw(21) <<
        (it->second).getCategoria() << setw(21) << (it->second).getCodigo() << setw(21) << (it->second).getPreco() << setw(10) << right <<
        (it->second).getQuantidade() << endl;
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::alterarNomeProduto(string pesquisa, string nome){ 
      if (_estoque.count(pesquisa) == 1)
      {
	if (nome.size() > 20)
            throw ExcecaoTamanhoNomeAlt();
        else
        {
	   map<string, Produto>::iterator it = _estoque.find(pesquisa);
           cout<<"O nome do prduto foi alterado de "<<(it->second).getNome()<<" para "<<nome<<endl;
	   (it->second).setNome(nome);
	}
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::alterarFabricanteProduto(string pesquisa, string fabric){
      if (_estoque.count(pesquisa) == 1)
      {
	if (fabric.size() > 20)
            throw ExcecaoTamanhoFabricAlt();
        else
	{
            map<string, Produto>::iterator it = _estoque.find(pesquisa);
            cout<<"O fabricante do prduto foi alterado de "<<(it->second).getFabricante()<<" para "<<fabric<<endl;
           (it->second).setFabricante(fabric);
	}
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::alterarCategoriaProduto(string pesquisa, string categ){
      if (_estoque.count(pesquisa) == 1)
      {
	if (categ.size() > 20)
           throw ExcecaoTamanhoCategAlt();
        else
	{
           map<string, Produto>::iterator it = _estoque.find(pesquisa);
           cout<<"A categoria do prduto foi alterada de "<<(it->second).getCategoria()<<" para "<<categ<<endl;
           (it->second).setCategoria(categ);
      	}
      }else
        throw ProdutoNaoCadastrado();
}

void Estoque::alterarPrecoProduto(string pesquisa, float preco){
      if (_estoque.count(pesquisa) == 1)
      { //NAO PODE SER LETRA SE NAO BUGA BIZARRAMENTE	
	if (preco != (int)preco)
	    throw PrecoNaoENumero();
        else if (preco < 0)
            throw ExcecaoPrecoNegativo();
	else
        {
	    map<string, Produto>::iterator it = _estoque.find(pesquisa);
            cout<<setprecision(2)<<"O preço do prduto foi alterado de "<<(it->second).getPreco()<<" para "<<preco<<endl;
            (it->second).setPreco(preco);
     	} 
      }else
          throw ProdutoNaoCadastrado();
}

void Estoque::alterarProduto(){
    char escolha;
    std::string codigoProdutoAlterado;
    std::string novaString;
    float novoFloat;
    map<string, Produto>::iterator it;
    std::cout << "Escolha o que deseja alterar: " << std::endl;
	  std::cout << "+-----------------------------+"<<std::endl;
	  std::cout << "| " << "1 - Nome                    |" << std::endl;
	  std::cout << "| " << "2 - Categoria               |" << std::endl;
	  std::cout << "| " << "3 - Fabricante              |" << std::endl;
	  std::cout << "| " << "4 - Preço                   |" << std::endl;
	  std::cout << "| " << "5 - Sair                    |" << std::endl;
	  std::cout << "+-----------------------------+"<<std::endl;
    std::cin>>escolha;
    switch (escolha)
    {
    case '1'://tratamento nome
        std::cout<<"Digite o código do produto que será alterado"<<endl;
        std::cin>>codigoProdutoAlterado;
        it = _estoque.find(codigoProdutoAlterado); // SE O CÓDIGO NAO EXISTIR OU FOR ENTRADA INVALIDA ELE DA BAD ALLOC E ABORT
        std::cout<<"Digite um novo nome para "<<(it->second).getNome()<<std::endl;
        std::cin>>novaString;
        try{
		alterarNomeProduto(codigoProdutoAlterado,novaString);
	}catch(ProdutoNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
        }catch(ExcecaoTamanhoNomeAlt& erro){
                  cout<<erro.what()<<endl;
        }   
        break;
    
    case '2':
        std::cout<<"Digite o código do produto que será alterado"<<endl;
        std::cin>>codigoProdutoAlterado;
        it = _estoque.find(codigoProdutoAlterado);
        std::cout<<"Digite uma nova categoria para "<<(it->second).getNome()<<std::endl;
        std::cin>>novaString;
        try{
		alterarCategoriaProduto(codigoProdutoAlterado,novaString);
	}catch(ProdutoNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
        }catch(ExcecaoTamanhoCategAlt& erro){
                  cout<<erro.what()<<endl;
        }  
        break;
    
    case '3':
        std::cout<<"Digite o código do produto que será alterado"<<endl;
        std::cin>>codigoProdutoAlterado;
        it = _estoque.find(codigoProdutoAlterado);
        std::cout<<"Digite um novo fabricante para "<<(it->second).getNome()<<std::endl;
        std::cin>>novaString;
        try{
		alterarFabricanteProduto(codigoProdutoAlterado,novaString);
	}catch(ProdutoNaoCadastrado& erro){
                  cout<<erro.what()<<endl;
        }catch(ExcecaoTamanhoFabricAlt& erro){
                  cout<<erro.what()<<endl;
	}
        break;

    case '4':
        std::cout<<"Digite o código do produto que será alterado"<<endl;
        std::cin>>codigoProdutoAlterado;
        it = _estoque.find(codigoProdutoAlterado);
        std::cout<<"Digite um novo preço para "<<(it->second).getNome()<<std::endl;
        std::cin>>novoFloat;
	try{
        	alterarPrecoProduto(codigoProdutoAlterado,novoFloat);
        }catch(ProdutoNaoCadastrado& erro){
                cout<<erro.what()<<endl;
        }catch(PrecoNaoENumero& erro){
		cout<<erro.what()<<endl;
	}catch(ExcecaoPrecoNegativoAlt& erro){
		cout<<erro.what()<<endl;
	}
	break;    

    case '5':
        break;
        
    default:
        throw EntradaInvalida();
        alterarProduto();
        break;
    }
}
