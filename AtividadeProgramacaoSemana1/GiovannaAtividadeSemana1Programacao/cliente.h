#include <iostream>
using namespace std;

// Difinição de uma classe com duas variáveis membro privada e dois construtores
class Cliente{

  // Definindo as variáveis privadas
  private :
    int imei;
    std::string login;  

  public:    
  // Definindo o construtor com parâmetros que inicializa as variáveis membro
    Cliente();
    Cliente(int imei, std::string login);
  // Definindo os métodos get que retornam os valolres das respectivas variáveis membro
    string getLogin() const;
    int getImei() const;
};






