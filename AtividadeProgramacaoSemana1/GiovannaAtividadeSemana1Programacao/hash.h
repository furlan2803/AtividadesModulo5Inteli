#include "cliente.h"

class Hash {

 public:
  // Permite que o usuário especifique o número máximo de itens que a tabela hash pode armazenar
  Hash(int itensMaximo = 100);

  // Libera a memória alocada para a estrutura da tabela hash.
  ~Hash();

  // Verifica se a tabela hash está cheia.
  bool isFull() const;

  // Retorna o comprimento da tabela hash.
  int getComprimentoTabela() const;

  // Recupera um item da tabela hash, armazenando-o em uma referência para um objeto "Cliente"
  // Informando se o item foi encontrado ou não através da variável "encontrado".
  void retrieveItem(Cliente& cliente, bool& encontrado);   

  // A função "insertItem" insere um item na tabela e a "deleteItem" remove um item da tabela hash.
  void insertItem(Cliente cliente); 
  void deleteItem(Cliente cliente);  
  void print();

 private:
  // Calcula o índice da tabela hash para um dado objeto "Cliente".
  int getHash(Cliente cliente);

  // Armazena o número máximo de itens que a tabela hash pode armazenar.
  int itensMaximo;

  // Armazena o comprimento da tabela hash.
  int comprimentoTabela;

  // Um ponteiro para um array de objetos "Cliente", que representa a estrutura da tabela hash.
  Cliente* estrutura;

};





