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
* Eu como gerente quero poder verificar o histórico de movimentações do estoque, que deve conter informações importantes como o tipo da movimentação (entrada ou saída), o produto em questão, a quantidade movimentada, o usuário que a realizou e a data da movimentação. Para que, seja possível fiscalizar e monitorar o estoque, e, em caso de erros humanos, ter as informações necessárias para corrigí-los, garantindo a segurança do estoque da empresa. 
- Critérios:
    1. Registrar o histórico em um arquivo inalterável pelos usuários, garantindo a perpetuação da memória. 
    2. Poder registrar o histórico automaticamente e em tempo real sempre que movimentações forem realizadas no estoque.
    3. Poder exibir o histórico de movimentações lido do arquivo.
    4. Pegar automaticamente a data atual do momento da movimentação e o usuário logado para realizar o registro no histórico.

### Registros de movimentação
* Eu como usuário pretendo poder realizar movimentações de produtos no estoque que variam entre entradas e saídas de produtos, de acordo com a minha permissão no momento. Gostaria também de realizar essa movimentação de uma forma intuitiva, prática e segura, na qual seria fácil manter o controle do que será modificado no estoque enquanto o pedido estiver sendo feito e também na sua finalização. Para que, o estoque se mantenha atualizado de acordo com as devidas entradas e saídas. 
- Critérios:
    1. Implementar entradas e saídas de produtos através de uma lista que é modificada enquanto o pedido está sendo feito.
    2. Não permitir a adição de um produto na lista com uma quantidade que não tenha em estoque.
    3. Possibilitar a remoção de qualquer produto adicionado a lista através de seu ID na lista.
    4. Antes de realizar a entrada de um produto, sempre checar pelo código se o mesmo já consta como cadastrado.
    5. Possibilitar o cancelamento de todos os produtos da lista.
    6. Implementar a finalização dos produtos da lista de uma forma que fique claro, para o usuário, o que foi modificado no sistema.

### Perpetuação de memória 
* Eu como dono da empresa preciso garantir que os dados do estoque, do histórico de movimentações e do subsistema de login sejam registrados de forma segura, de maneira que não haja perda da memória quando o sistema for encerrado. Sendo assim, são necessários arquivos que armazenarão as informações de maneira correta e que serão lidos ao inicializar o sistema de forma à garantir seu correto funcionamento. Para que, dessa forma, haja a perpetuação da memória do sistema.
- Critérios:
    1. Implementar uma base de dados com um arquivo para cada sistema citado.
    2. Implementar funções que, ao inicializar o sistema, lerão as informações contidas nos arquivos e as utilizarão adequadamente na construção dos devidos objetos,          que permitirão o funcionamento de todos os métodos.
    3. Implementar funções que escreverão nos arquivos as informações atualizadas, de maneira que na próxima execução do sistema, ele possa lê-las corretamente.

### Controle de acesso
* Eu como dono da empresa quero poder delegar diferentes funções do sistema entre usuários de diferentes permissões, sendo eles divididos entre funcionários e gerentes. De forma que os funcionários tenham acesso apenas à funções mais básicas como: registrar saídas, consultar ou listar produtos e alterar os próprios dados. Enquanto isso, os gerentes possuem acesso à todas as funções presentes no sistema. Para que, dessa forma, tanto o estoque quanto o sistema de usuários estejam protegidos de usuários de menores níveis de confiança da empresa e experiência na profissão. 
- Critérios:
    1. Implementar um atributo em usuário para registrar seu tipo, que reflete no nível de permissão.
    2. Disponibilizar menus diferentes para os diferentes tipos de usuários, com limitações para o tipo "funcionário".
    3. Registro de novos usuários possível somente por uma função do Gerente, sendo necessário inicializar o arquivo que armazena os usuários registrados com um usuário        padrão do tipo "gerente".
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
