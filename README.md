# Trabalho Final PDS2 - Sistema de Estoque (Perfumaria)

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
### Controle de catálogo de produtos
* Eu como gerente quero poder realizar o cadastro de um produto, caso ele não exista, para poder adicioná-lo no estoque, remover um produto ou alterar seus dados, caso ele já exista, com intuito de manter o estoque atualizado de acordo com a demanda dos consumidores em relação aos produtos com que a empresa deve trabalhar. Também desejo poder pesquisar um produto pelo seu código e listar todos os cadastrados.
- Critérios:
    1. Adicionar um produto de acordo com as informações necessários do catálogo
    2. Pesquisar por código e mostrar todas as suas informações.
    3. Não duplicar produtos, se o produto já existir, não poderá ser adicionado.
    4. Listar todos produtos presentes no estoque.
    5. Alterar os atributos de um produto já cadastrado.
    6. Remover um produto pelo seu código, caso já exista.

### Controle de movimentação
* Eu como gerente quero poder verificar o estoque, para saber quanto tem de cada item, para
saber se preciso comprar mais produtos ou não.
- Critérios:
    1. Poder retornar quantos produtos tem de cada produto, pesquisado por nome ou
    código.
    2. Pesquisar por código e nome e mostrar quantos foram retirados.
    3. Pesquisar por código e nome e mostrar quantos foram adicionados.
    4. Poder retornar o valor total de cada produto em estoque.

### Registros de movimentação
* Eu como usuário pretendo poder realizar movimentações de produtos no estoque que variam entre entradas e saídas de produtos, de acordo com a minha permissão no momento. Gostaria também de realizar essa movimentação de uma forma intuitiva, prática e segura, na qual seria fácil manter o controle do que será modificado no estoque enquanto o pedido estiver sendo feito e também na sua finalização. Para que, o estoque se mantenha atualizado de acordo com as devidas entradas e saídas. 
- Critérios:
    1. Implementar entradas e saídas de produtos através de uma lista que é modificada enquanto o pedido está sendo feito.
    2. Não permitir a adição de um produto na lista com uma quantidade que não tenha em estoque.
    3. Possibilitar a remoção de qualquer produto adicionado a lista através de seu ID na lista.
    4. Antes de realizar a entrada de um produto, sempre checar pelo código se o mesmo já consta como cadastrado.
    5. Possibilitar o cancelamento de todos os produtos da lista.
    6. Implementar a finalização dos produtos da lista de uma forma que fique claro, para o usuário, o que foi modificado no sistema.

### Controle de ..
* Eu como funcionário preciso registrar quantos e quais produtos foram vendidos, para
manter o estoque atualizado.
- Critérios:
    1. Adicionar uma nota de saída com um produto já cadastrado, poder remover um
    produto, para ser removido do estoque
    2. Poder excluir uma nota de saída.
    3. Conferir se o produto está em estoque para poder ser retirado.

### Controle de acesso
* Eu como dono da empresa quero separar as funções as funções do sistema entre funcionários e gerentes, para que
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
