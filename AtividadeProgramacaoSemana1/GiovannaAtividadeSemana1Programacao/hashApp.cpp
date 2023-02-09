#include "hash.h"
#include <iostream>
#include <algorithm>
using namespace std;

int casoTeste1() {

  /*
    Caso de Teste 1 : Deletar um usuário da tabela Hash.
    Pré requisito: O usuário deve estar listado/existir na tabela. 
    Entrada esperada: 12704 (imei do usuário - giovanna@gmail.com)
    Saída esperada: Após executar o caso de teste 1 na função main, visualizar se o usuário foi realmente deletado. 
  */

  // Cria uma tabela Hash com tamanho 11
  Hash clienteHash(11);

  // Vetor com 9 "imeis" e 9 "logins"
  int imeis[9] = {
  
    12704, 
    31300, 
    1234, 
    33345, 
    33345,
    49001, 
    31300,
    52202, 
    65606
  
  };

  string logins[9] = {

      "giovanna@gmail.com", 
      "pedro@gmail.com",  
      "beatriz@gmail.com",
      "marcelo@gmail.com",  
      "taissa@gmail.com", 
      "lucas@gmail.com",
      "sofia@gmail.com",    
      "sara@gmail.com", 
      "amanda@gmail.com"

  };

  for (int i = 0; i < 9; i++) {

    // Utiliza os vetores para criar 7 objetos da classe "Cliente"
    Cliente cliente = Cliente(imeis[i], logins[i]);

    // Esses objetos são então inseridos na tabela hash usando a função
    // "insertItem()"
    clienteHash.insertItem(cliente);
  }
  cout << "------------------------------" << endl;
  cout << "CASO DE TESTE 1" << endl;
  cout << "Deletar um item da lista" << endl;
  cout << "------------------------------" << endl;
  cout << "Lista antes de deletar" << endl;
  cout << "------------------------------" << endl;
  clienteHash.print();

  // Busca na tabela Hash um imei com esse valor
  Cliente cliente(12704, "");

  // retorna o resultado da busca na variável
  bool encontrado = false;

  // Exibe o login juntamente com o resultado da busca
  clienteHash.retrieveItem(cliente, encontrado);

  if (encontrado){
    // o item com o imei especificado é removido da tabela hash usando a função "deleteItem()"
    clienteHash.deleteItem(cliente);
    cout << "------------------------------" << endl;
    cout << "O item " << cliente.getLogin() << " foi deletado " << endl;
    cout << "------------------------------" << endl;
  }
  else {
    cout << "------------------------------" << endl;
    cout << "O item não foi encontrado" << endl;
    cout << "------------------------------" << endl;
  }

  cout << "Lista após deletar" << endl;
  cout << "------------------------------" << endl;
  clienteHash.print();
  cout << "------------------------------" << endl;

  return 0; 
}

int casoTeste2() {

   /*
    Caso de Teste 2 : Alterar o tamanho da tabela Hash para um número primo
    Pré requisito: O tamanho anterior da tabela tem que ser par. 
    Entrada esperada: "Hash clienteHash(13);"
    Saída esperada: 
        Após executar o caso de teste 2 na função main, visualizar se a tabela possui mais casas
        O intuito é evitar colisões colocando como tamanho um número primo 
  */
  
  // Cria uma tabela Hash com tamanho 13
  Hash clienteHash(13);

  // Vetor com 9 "imeis" e 9 "logins"
  int imeis[9] = {

    12704, 
    31300, 
    1234, 
    33345, 
    33345,
    49001, 
    31300,
    52202, 
    65606

  };

  string logins[9] = {

      "giovanna@gmail.com", "pedro@gmail.com",  "beatriz@gmail.com",
      "marcelo@gmail.com",  "taissa@gmail.com", "lucas@gmail.com",
      "sofia@gmail.com",    "sara@gmail.com", "amanda@gmail.com"

  };

  for (int i = 0; i < 9; i++) {

    // Utiliza os vetores para criar 7 objetos da classe "Cliente"
    Cliente cliente = Cliente(imeis[i], logins[i]);

    // Esses objetos são então inseridos na tabela hash usando a função
    // "insertItem()"
    clienteHash.insertItem(cliente);
  }

  cout << "--------------------------------------------" << endl;
  cout << "CASO DE TESTE 2" << endl;
  cout << "Lista com tamanho 13" << endl;
  cout << "Evitar colisões por ser um número primo" << endl;
  cout << "--------------------------------------------" << endl;
  clienteHash.print();
  cout << "------------------------------" << endl;

  return 0; 
}

int casoTeste3() {

   /*
    Caso de Teste 3 : Dois usuários com o mesmo login e imei.
    Pré requisito: Os usuários devem ser iguais e possuir duas casas vagas na tabela. 
    Entrada esperada: dois "33345" e dois "marcelo@gmail.com"
    Saída esperada: Após executar o caso de teste 3 na função main, visualizar os dois imeis e os dois emails
      Uma vez que, existe o tratamento para colisões aplicado
  */
  
  // Cria uma tabela Hash com tamanho 10
  Hash clienteHash(10);

  // Vetor com 9 "imeis" e 9 "logins"
  int imeis[9] = {

    12704, 
    31300, 
    1234, 
    33345, 
    33345,
    49001, 
    31300,
    52202, 
    65606

  };

  string logins[9] = {

      "giovanna@gmail.com", "pedro@gmail.com",  "beatriz@gmail.com",
      "marcelo@gmail.com",  "marcelo@gmail.com", "lucas@gmail.com",
      "sofia@gmail.com",    "sara@gmail.com", "amanda@gmail.com"

  };

  for (int i = 0; i < 9; i++) {

    // Utiliza os vetores para criar 7 objetos da classe "Cliente"
    Cliente cliente = Cliente(imeis[i], logins[i]);

    // Esses objetos são então inseridos na tabela hash usando a função
    // "insertItem()"
    clienteHash.insertItem(cliente);
  }


  cout << "--------------------------------------------" << endl;
  cout << "CASO DE TESTE 3 - REALIZA TRATAMENTO DE COLISÃO" << endl;
  cout << "Colocar dois itens iguais, mesmo email e mesmo login" << endl;
  cout << "--------------------------------------------" << endl;
  clienteHash.print();
  cout << "------------------------------" << endl;

  return 0; 
}

int casoTeste4() {

   /*
    Caso de Teste 4 : Colocar o tamanho da lista, igual a quantidade de entradas
    Pré requisito: Deve possuir 9 entradas para a tabela.
    Entrada esperada: tamanho da tabela "Hash clienteHash(9)", tamanho das entradas "int imeis[9]" e "string logins[9]"
    Saída esperada: Após executar o caso de teste 4 na função main, visualizar como a lista ficou definida
      obs: Com tratamento de colisões aplicados. 
  */
  
  // Cria uma tabela Hash com tamanho 9
  Hash clienteHash(9);

  // Vetor com 9 "imeis" e 9 "logins"
  int imeis[9] = {

    12704, 
    31300, 
    1234, 
    33345, 
    33345,
    49001, 
    31300,
    52202, 
    65606

  };

  string logins[9] = {

      "giovanna@gmail.com", "pedro@gmail.com",  "beatriz@gmail.com",
      "marcelo@gmail.com",  "taissa@gmail.com", "lucas@gmail.com",
      "sofia@gmail.com",    "sara@gmail.com", "amanda@gmail.com"

  };

  for (int i = 0; i < 9; i++) {

    // Utiliza os vetores para criar 7 objetos da classe "Cliente"
    Cliente cliente = Cliente(imeis[i], logins[i]);

    // Esses objetos são então inseridos na tabela hash usando a função
    // "insertItem()"
    clienteHash.insertItem(cliente);
  }

  cout << "--------------------------------------------" << endl;
  cout << "CASO DE TESTE 4 - JÁ COM TRATAMENTO DE COLISÃO" << endl;
  cout << "Tamanho da lista igual a quantidade de entradas (9)" << endl;
  cout << "--------------------------------------------" << endl;
  clienteHash.print();
  cout << "------------------------------" << endl;

  return 0;
}

int casoTeste5() {
  /*
    Caso de Teste 5 : Busca de login na tabela
    Pré requisito: Existir alguma entrada na tabela
    Entrada esperada: "pedro@gmail.com"
    Saída esperada: Após executar o caso de teste 5 na função main, visualizar se o intem existe ou não na tabela.
  */
  
  // Cria uma tabela Hash com tamanho 10
  Hash clienteHash(10);

  // Vetor com 9 "imeis" e 9 "logins"
  int imeis[9] = {

    12704, 
    31300, 
    1234, 
    33345, 
    33345,
    49001, 
    31300,
    52202, 
    65606

  };

  string logins[9] = {

      "giovanna@gmail.com", "pedro@gmail.com",  "beatriz@gmail.com",
      "marcelo@gmail.com",  "taissa@gmail.com", "lucas@gmail.com",
      "sofia@gmail.com",    "sara@gmail.com", "amanda@gmail.com"

  };

  for (int i = 0; i < 9; i++) {

    // Utiliza os vetores para criar 7 objetos da classe "Cliente"
    Cliente cliente = Cliente(imeis[i], logins[i]);

    // Esses objetos são então inseridos na tabela hash usando a função
    // "insertItem()"
    clienteHash.insertItem(cliente);
  }

  cout << "------------------------------------------------------------" << endl;
  cout << "CASO DE TESTE 5" << endl;
  cout << "Busca de uma chave de entrada" << endl;
  cout << "------------------------------------------------------------" << endl;


  string valorChave = "pedro@gmail.com";

  int listaPercorre = sizeof(logins) / sizeof(*logins);

  bool verificaExistencia = std::find(logins, logins + listaPercorre, valorChave) != logins + listaPercorre;
  
  if (verificaExistencia) {
      std::cout << "O e-mail " << valorChave << " requisitado foi encontrado na lista" << endl;
      cout << "------------------------------------------------------------" << endl;
    
  } else {
      std::cout << "O e-mail requisitado NÃO foi encontrado na lista" << endl;
      cout << "------------------------------------------------------------" << endl;
    
  }


  clienteHash.print();
  cout << "------------------------------------------------------------" << endl;
  


  return 0;
}

int main() {

  casoTeste1();
  casoTeste2();
  casoTeste3();
  casoTeste4();
  casoTeste5();

  return 0;
}
