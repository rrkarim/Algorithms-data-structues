/**
    LRU Cache
    Rasul Kerimov (CoderINusE) 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class node {
  int value;
  int key;
  node *next;
  node *pre;
public:
  node() {}
  node(int value, int key) : value(value), key(key), next(NULL), pre(NULL) {}
};

class LRUCache {

  int capacity;
  unordered_map <int, node*> map_elems;
  node *head;
  node *tail;
public:
  LRUCache(int capacity) : capacity(capacity) {}
  int get(int key) {
    if(map_elems[key]) {
      node * curr = make_pair[key];
      int ret = curr->value;
      add_to_tail(curr);
      remove(curr);
      return ret;
    }
    return -1;
  }

  void add_to_tail(node * n) {
    
  }

  int set() {

  }

};

int main() {


}