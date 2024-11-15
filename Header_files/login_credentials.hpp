#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>

using namespace std;

class MapEntry {
private:
  MapEntry* next;
  string key;
  string value;

public:
  MapEntry(string key, string value) {
    this->key = key;
    this->value = value;
    next = nullptr;
  }

  string getKey() {
    return key;
  }

  string getValue() {
    return value;
  }

  MapEntry* getNext() {
    return next;
  }

  void setNext(MapEntry* nextMap) {
    next = nextMap;
  }
};

class Operate {
private:
  MapEntry* head;
  int length;

public:
  Operate() : head(nullptr), length(0) {}

  void Add(const string& key, const string& value) {
    MapEntry* newItem = new MapEntry(key, value);
    if (head == nullptr) {
      head = newItem;
    } else {
      newItem->setNext(head);
      head = newItem;
    }
    length++;
  }

  bool Find(const string& key, const string& value) {
    MapEntry* temp = head;
    while (temp) {
      if (temp->getKey() == key && temp->getValue() == value) {
        return true;
      }
      temp = temp->getNext();
    }
    return false;
  }

  MapEntry* getHead() {
    return head;
  }

  int getLength() {
    return length;
  }
};

class Authentication {
public:
  bool authenticate(Operate& operate, const string& key, const string& value) {
    MapEntry* temp = operate.getHead();
    while (temp) {
      if (key == temp->getKey() && value == temp->getValue()) {
        return true;
      }
      temp = temp->getNext();
    }
    return false;
  }
};

#endif
