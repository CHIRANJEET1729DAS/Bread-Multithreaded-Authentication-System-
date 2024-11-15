#ifndef CMD_HPP
#define CMD_HPP

#include <iostream>
#include <cstdlib>
#include "/home/chiranjeet/multithreading/header_files/server_code.hpp"

using namespace std;

class Execution {
public:
  void clientAuthenticate(ProcessFunctionality& process, const string& key, const string& value) {
    cout << "Client requesting authentication for key: " << key << " and value: " << value << endl;

    bool result = process.process_map(key, value);

    if (result) {
      cout << "Authentication successful for key: " << key << endl;
      system("/home/chiranjeet/custom_shell/chachashell");
    } else {
      cout << "Authentication failed for key: " << key << endl;
    }
  }
};

#endif
