#include "hash.h" 
#include <iostream>
using namespace std;

// Construtor que inicializa os membros da classe
// Aceita um parÂmetro inteiro maximo (tamanho máximo da tabela hash)
Hash::Hash(int maximo) {  
  
  comprimentoTabela = 0;
  itensMaximo = maximo;
  estrutura = new Cliente[itensMaximo];
}

// Implementação do destrutor da classe "Hash"
Hash::~Hash(){
  // Libera a memória alocada para o array "estrutura".
  delete [] estrutura;
}

// Verifica se a tabela hash está cheia
bool Hash::isFull() const {
  // Se o comprimento da tabela é igual ao número máximo de itens na tabela retorna true
  return (comprimentoTabela == itensMaximo);
}

// Retorna o comprimento atual da tabela hash
int Hash::getComprimentoTabela() const {
  return comprimentoTabela;
}

void Hash::retrieveItem(Cliente& cliente, bool& encontrado) {

  // Calcula o valor hash para o objeto de cliente passado como referência
  int localInicial = getHash(cliente);

  // indica se deve continuar a pesquisar na tabela hash
  bool pesquisar = true; 
  
  // Armazena a localização atual na tabela hash
  int local = localInicial;
  
  // Enquanto a posição atual não for igual à posição inicial e a indicação de pesquisa for verdadeira
  do {
    
    // Se o IMEI na posição atual for igual ao IMEI do objeto de cliente ou for -1 (posição vazia)
    if (estrutura[local].getImei() == cliente.getImei() || estrutura[local].getImei() == -1)
      
      // Define a indicação de pesquisa como falsa para interromper o loop
      pesquisar = false;
      
    else
      // Se não for igual, vai para a próxima posição na tabela hash
      local = (local + 1) % itensMaximo;
    
  } while (local != localInicial && pesquisar);
  
  // Define se o objeto de cliente foi encontrado na tabela hash baseado no valor do IMEI na posição atual
  encontrado = (estrutura[local].getImei() == cliente.getImei());  

  // Se o objeto de cliente foi encontrado
  //Atualiza o objeto passado como referência com o objeto na posição encontrada na tabela hash
  if (encontrado) { 
    cliente = estrutura[local];
  }
  
}

void Hash::insertItem(Cliente cliente) {
   // Calcula a posição na tabela hash para o objeto de cliente
  int local;
  local = getHash(cliente);
  
  // Enquanto a posição na tabela hash não estiver vazia (IMIE não for -1)
  while (estrutura[local].getImei() > 0)
    // Vai para a próxima posição na tabela hash
    local = (local + 1) % itensMaximo;
  
  // Insere o objeto de cliente na posição encontrada na tabela hash
  estrutura[local] = cliente;
  comprimentoTabela++;
  
}

void Hash::deleteItem(Cliente cliente) {


  // Verificação para encontrar o item com o IMEI correspondente ao cliente
  // A variável "local" armazena a posição inicial na tabela
  int localInicial = getHash(cliente);
  bool pesquisar = true; 
  int local = localInicial;

  
  do {
    
     // Verifica se há algum item na posição, com o IMEI igual ao do cliente ou se a posição está vazia (-1)
    if (estrutura[local].getImei() == cliente.getImei() || estrutura[local].getImei() == -1)
      // Caso vazia ou com um IMEI igual, a pesquisa é interrompida e "pesquisar" é definido como false
      pesquisar = false;

    // A pesquisa continua até encontrar o item ou chegar na posição inicial novamente.
    else
      local = (local + 1) % itensMaximo;
    
  } while (local != localInicial && pesquisar);

   // Verifica se a posição encontrada tem um item com IMEI igual ao do cliente
  if (estrutura[local].getImei() == cliente.getImei()) {  
    
    // Exclui o item da tabela, define a posição como (-2) e decrementa o comprimento da tabela.
    estrutura[local] = Cliente(-2,"");
    comprimentoTabela--; 
  }
}

// Impressão de todos os itens da tabela, mostrando sua posição, IMEI e login.
void Hash::print() {
  
  for (int i = 0; i < itensMaximo; i++) {
    cout << i <<":"<< estrutura[i].getImei()<<", "<<estrutura[i].getLogin()<<endl;
  }
}

// Calcula a posição na tabela de um determinado item, baseado no IMEI do cliente, utilizando o operador módulo.
int Hash::getHash(Cliente cliente){
  return cliente.getImei() % itensMaximo;
}



