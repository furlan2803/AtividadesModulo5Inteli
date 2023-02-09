#include "cliente.h"

// Implementação de uma classe chamada "Cliente" com dois construtores
Cliente::Cliente(){
  // Inicializando os construtores
  this-> imei   = -1;
  this-> login = "";
}; 

// Definição de construtor com parâmetros
Cliente::Cliente(int imei, std::string login){
  // Inicializa as variáveis passadas como parâmetros com o valor variável membro
  this-> imei    = imei;
  this-> login  = login;
}

// Inicializando método get para o login, como const para não modificar o estado do objeto
string Cliente::getLogin() const {
  return login;
}

// Inicializando método get para o imei, como const para não modificar o estado do objeto
int Cliente::getImei() const{
  return imei;
}






