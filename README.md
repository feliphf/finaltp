# Trabalho Final PDS2
# Sistema de Estoque (Perfumaria)

## Grupo:
* Yan Figueiras Alves
* Felipe Henrique Ferraz
* Ana Carolina Lima de Souza
* Guilherme Antônio Pascoal
* Pedro de Araújo Cruz

## Descrição do sistema:
* O sistema desenvolvido tem como objetivo gerir um estoque (nesse exemplo aplicado a uma perfumaria), e para isso conta com gerentes e funcionários, cada um com diferentes níveis de acesso as funções. Quando iniciado, é preciso fazer login com uma conta pré-cadastrada que
ao depender de qual permissão lhe for dada, de acordo acordo com sua função na empresa aparecerá um menu diferente. Resumidamente, os funcionários podem apenas alterar sua própria senha, registrar vendas, consultar produtos e listar todos os produtos do estoque, já os gerentes, além de possuirem essas funções, podem controlar o sistema como um todo realizando entradas no estoque, cadastrando, listando, alterando, removendo produtos e usuários. Também há para o gerente a possibilidade de imprimir o histórico de movimentações do estoque, em que são mostradas todas as entradas e saídas já feitas. Nesse histórico constam o produto adicionado ou removido, a quantidade alterada, o usuário responsável pela alteração e a data da movimentação.

## Diagrama de classes:
![alt text](https://github.com/feliphf/finaltp/blob/main/database/imgReadme/diagramaClasses.png)

## User Stories:
### 1º User Storie (classe entrada)
* Eu como gerente quero poder catalogar um cadastro de um produto, para poder adicionar
um produto no estoque e mantê-los atualizados, caso ele não exista;
- Critérios:
    1. Adicionar um produto de acordo com as informações necessários do catálogo
    2. Pesquisar por código e nome e mostrar todas as duas informações.
    3. Não duplicar produtos, se o produto já existir, não poderá ser adicionado.

### 2º User Storie (classe estoque)
* Eu como gerente quero poder verificar o estoque, para saber quanto tem de cada item, para
saber se preciso comprar mais produtos ou não.
- Critérios:
    1. Poder retornar quantos produtos tem de cada produto, pesquisado por nome ou
    código.
    2. Pesquisar por código e nome e mostrar quantos foram retirados.
    3. Pesquisar por código e nome e mostrar quantos foram adicionados.
    4. Poder retornar o valor total de cada produto em estoque.

### 3º User Storie (classe funcionario)
* Eu como funcionário quero poder fazer uma consulta no estoque para saber quais produtos
estão disponíveis a venda
- Critérios:
    1. Pesquisar por código e nome para mostrar quais produtos estão em estoque.
    2. Poder gerar um relatório do estoque com o nome e quantidade de produtos que
    estão disponíveis para venda..
    3. Poder gerar um relatório geral, para poder averiguar toda a situação do sistema,
    desde a quantidade de produtos às movimentações de entrada e saída.

### 4º User Storie (classe saídas)
* Eu como funcionário preciso registrar quantos e quais produtos foram vendidos, para
manter o estoque atualizado.
- Critérios:
    1. Adicionar uma nota de saída com um produto já cadastrado, poder remover um
    produto, para ser removido do estoque
    2. Poder excluir uma nota de saída.
    3. Conferir se o produto está em estoque para poder ser retirado.

### 5º User Storie (classe Usuário)
* Eu como dono da empresa quero separar as permissões do meu gerente com os
permissões dos subordinados do meu gerente, para garantia a segurança da minha
empresa
- Critérios:
    1. Somente o gerente deverá ter permissão em entradas para poder comprar os
    produtos, para não ter excesso de produtos parados.
    2. O funcionário deverá ter acesso às saídas, para poder retirar os produtos, que os
    vendedores venderam, para poder ser retirado do estoque.
    3. O funcionário e o gerente deverão ter acesso ao estoque, para poder emitir os
    relatórios gerais e individuais dos produtos

## Como executar e testar o sistema:
### Comandos:
- Clonar o repositório:
    - 1 - `git clone https://github.com/feliphf/finaltp.git`: clona o diretório para sua máquina local.
    - 2 - `cd finaltp`: entra na pasta do repositório.


- Executar o programa:    
    - 1 - `make`: compila todas as classes do sistema.
    - 2 - `./main`: executa o sistema (deve ser feito na raiz).


- Testar o programa:
    - 1 - `make tests`: compila todos os testes do sistema, além das classes.
    - 2 - `./tester`: executa os testes do sistema (deve ser feito na raiz).