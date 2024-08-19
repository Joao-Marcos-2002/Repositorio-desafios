#include "google_password.h"

#include <iostream>
#include <string>

using namespace std;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  if(passwords_.count(url) == 0 && validPassword(password)) {
    Usuario u{login, password};
    passwords_.insert(make_pair(url, u));
  }
}

void GooglePassword::remove(const std::string& url) {
  passwords_.erase(url);
}

void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  auto it = passwords_.find(url);
  if (it != passwords_.end()) {
    if (old_password == it->second.password && 
        validPassword(new_password)) {
      it->second = Usuario{login, new_password};
    }
  }
}

void GooglePassword::printPasswords() {
  cout << passwords_.size() << endl;
  for (auto par : passwords_) { 
    cout << par.first << ": " << par.second.login
         << " and " << par.second.password << endl; 
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
  // OBS: O gerenciador deverá aceitar apenas senhas que
  return password.find("123456") == string::npos &&  // (i) não contenham a sequência "123456",
         password.find(" ") == string::npos &&  // (ii) não contenham caracteres em branco,
         password.size() >= 6 &&  // (iii) possuam 6 ou mais caracteres e
         password.size() <= 50;  // (iv) possuam 50 ou menos caracteres.
}

