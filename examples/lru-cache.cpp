/**
    LRU Cache
    Rasul Kerimov (CoderINusE) 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class node {
public:
  int value;
  int key;
  node *next;
  node *pre;
  node() {}
  node(int key, int value) : value(value), key(key), next(NULL), pre(NULL) {}
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
      node * curr = map_elems[key];
      node * newnode = new node(key, curr->value);
      int ret = curr->value;
      add_to_tail(newnode);
      remove(curr);
      return ret;
    }
    return -1;
  }

  void add_to_tail(node * n) {
    if(tail == NULL) {
      head = tail = n;
    }
    else {
      tail->next = n;
      tail = tail->next;  
    }
  }

  void remove(node *n) {
    if(n->pre != NULL) {
      n->pre->next = n->next;
    }
    else head = n->next;

    if(n->next != NULL) {
      n->next->pre = n->pre;
    }
    else tail = n->pre;
    delete n;

  }

  int set(int key, int value) {
    if(map_elems[key]) {
      node * curr = map_elems[key];
      node * newnode = new node(key, value); 
      add_to_tail(newnode);
      remove(curr);
    }
    else {
      node * newnode = new node(key, value); 
      if(map_elems.size() > capacity) {
        map_elems.erase(head->key);
        remove(head);
        add_to_tail(newnode);
      }
      else {
        add_to_tail(newnode);
      }
      map_elems[key] = newnode;
    }
  }

};

int main() {
  LRUCache * cache = new LRUCache(3);
  cache->set(1, 34);
  cache->set(2, 35);
  cache->set(3, 32);
  cache->set(4, 31);

  cout << cache->get(1) << endl;
}