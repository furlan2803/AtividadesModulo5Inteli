# 🔒 Acesso ao Replit

https://replit.com/join/rtgclqnmjw-giovannatorres


# ⚙️ Casos de Teste

## 🔧 Caso 1 

Caso de Teste 1 : Deletar um usuário da tabela Hash.
Pré requisito: O usuário deve estar listado/existir na tabela. 
Entrada esperada: 12704 (imei do usuário - giovanna@gmail.com)
Saída esperada: Após executar o caso de teste 1 na função main, visualizar se o usuário foi realmente deletado. 

## 🔧 Caso 2

Caso de Teste 2 : Alterar o tamanho da tabela Hash para um número primo
Pré requisito: O tamanho anterior da tabela tem que ser par. 
Entrada esperada: "Hash clienteHash(13);"
Saída esperada: Após executar o caso de teste 2 na função main, visualizar se a tabela possui mais casas. O intuito é evitar colisões colocando como tamanho um número primo 

## 🔧 Caso 3 

Caso de Teste 3 : Dois usuários com o mesmo login e imei.
Pré requisito: Os usuários devem ser iguais e possuir duas casas vagas na tabela. 
Entrada esperada: dois "33345" e dois "marcelo@gmail.com"
Saída esperada: Após executar o caso de teste 3 na função main, visualizar os dois imeis e os dois emails. Uma vez que, existe o tratamento para colisões aplicado

## 🔧 Caso 4 

Caso de Teste 4 : Colocar o tamanho da lista, igual a quantidade de entradas
Pré requisito: Deve possuir 9 entradas para a tabela.
Entrada esperada: tamanho da tabela "Hash clienteHash(9)", tamanho das entradas "int imeis[9]" e "string logins[9]"
Saída esperada: Após executar o caso de teste 4 na função main, visualizar como a lista ficou definida
  obs: Com tratamento de colisões aplicados. 

## 🔧 Caso 5 

Caso de Teste 5 : Busca de login na tabela
Pré requisito: Existir alguma entrada na tabela
Entrada esperada: "pedro@gmail.com"
Saída esperada: Após executar o caso de teste 5 na função main, visualizar se o intem existe ou não na tabela.
  

# 💻 Execução do programa

Os arquivos desta pasta podem ser compilados com:

$ g++ *.cpp

Feito isso, a execução será feita com:

$ ./a.out
