#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include "/home/chiranjeet/multithreading/header_files/login_credentials.hpp"

using namespace std;

class Bread {
private:
  MapEntry* top;
public:
  string key;
  string value;
  bool available;

  Bread(string key, string value) {
    this->key = key;
    this->value = value;
    top = nullptr;
    available = false;
  }

  string getKey() {
    return key;
  }

  string getValue() {
    return value;
  }

  void setTop(MapEntry* topMap) {
    top = topMap;
  }

  MapEntry* getTop() {
    return top;
  }

  void setAvailability(bool avail) {
    available = avail;
  }

  bool isAvailable() {
    return available;
  }
};

class Accessibility {
public:
  void process(bool success) {
    if (success) {
      cout << "Processing successful." << endl;
    } else {
      cout << "Error during processing." << endl;
    }
  }
};

class ProcessFunctionality {
private:
  Bread* new_bread;
  int active_breads = 0;
  MapEntry* temp;
  Operate operate;
  Authentication authentication;
  Accessibility accessibility;

public:
  ProcessFunctionality() : new_bread(nullptr), temp(nullptr) {}

  void manage_breads() {
    if (active_breads > 0) {
      cout << "Creating a new bread as there are active threads." << endl;
      new_bread = new Bread(temp->getKey(), temp->getValue());
      new_bread->setAvailability(true);
    }
  }

  bool authenticate(const string& key, const string& value) {
    bool result = authentication.authenticate(operate, key, value);
    accessibility.process(result);
    return result;
  }

  bool process_map(const string& key, const string& value) {
    active_breads += 1;
    temp = operate.getHead();

    while (temp) {
      if (key == temp->getKey() && value == temp->getValue()) {
        accessibility.process(true);
        if (new_bread) {
          new_bread->setTop(nullptr);
          delete new_bread;
          active_breads -= 1;
        }
        return true;
      }
      temp = temp->getNext();
    }

    accessibility.process(false);

    if (new_bread) {
      new_bread->setTop(nullptr);
      delete new_bread;
      active_breads -= 1;
    }

    return false;
  }

  Operate& getOperate() {
    return operate;
  }
};

#endif
