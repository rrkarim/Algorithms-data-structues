/**
	LinkedList implementation
	Iterator pattern
	Rasul Kerimov (CoderINusE) 
*/
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdlib.h>
#include <exception>
#include <iostream>

using namespace std;

namespace alg {
	template <typename T>
	class LinkedList {
		class node {
			public:
				node(const T& val_) : next(NULL), value(val_) {}
				node(const T& val_, node* next_) : next(next_), value(val_) {}
				T& getVal() {return value;}
				node* next;
			private:
				T value;
		};
		class LLException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "out of range";
				}
		} excp_key;
		private:	
			node *pHead;
			node *pTail;
			int size;
		public:
			LinkedList() : pHead(NULL), pTail(NULL), size(0) {};
			~LinkedList() {
				__destruct(pHead);
			} 
			LinkedList& operator=(LinkedList linkn) {
				__destruct(pHead);
				pHead = pTail = NULL;
				swap(pHead, linkn.pHead); //Copy-Swap idiom
				swap(pTail, linkn.pTail);
				swap(size, linkn.size); //
				return *this;
			}
			void insert_to_tail(const T & value) {
				node * temp = new node(value);
				if(pHead == NULL) {
					pHead = pTail = temp;
					size = 1;
				}
				else {
					pTail->next = temp;
					pTail = pTail->next; 
					size += 1;
				}
			}
			void insert_to_head(const T & value) {
				node * temp = new node(value);
				if(pHead == NULL) {
					pHead = pTail = temp;
					this->size = 1;
				} 
				else {
					temp->next = pHead;
					pHead = temp;
					this->size += 1;
				}
			}
			void insert_by_position(const T &value, const int &position) {
				if(position >= this->size) { 
					insert_to_tail(value);
				}
				else if(position == 0) {
					insert_to_head(value);
				}
				else {
					node * temp = new node(value); //Create new temporary node
					node *it = pHead;
					for(int i = 0; i < position - 1; ++i) it = it->next;
					node *next_temp = it->next;
					it->next = temp;
					it = it->next;
					it->next = next_temp;
					this->size += 1;
				}
			}
			bool remove_by_position(const int &position) {
				if(position >= this->size)
					return 1;
				if(position == 0) {
					node *delete_node = pHead;
					pHead = pHead->next;
					delete delete_node;
					return 0;
				}
				node *it = pHead;
				for(int i = 0; i < position - 1; ++i) it = it->next;			
				node *delete_node = it->next;
				it->next = delete_node->next;
				delete delete_node;
				this->size -= 1;
				return 0;
			}
			void swap_list() {
				node *it = pHead->next;
				node *head_s = new node(pHead->getVal());
	
				while(it != NULL) {
					node *temp = new node(it->getVal(), head_s);
					head_s = temp;
					it = it->next;
				}
				__destruct(pHead);
				this->pHead = head_s;
			}
			void sort_helper(node *n, node *curr) { //Insertion sort O(n^2)
				if(n == curr) { return n; }
				node *temp = f(n->next, curr);
				if(n->val > temp->val) {
					swap(n->val, temp->val);
				} 
			}
			void sort() {
				node *curr = pHead;
				while(curr != NULL) {
					sort_helper(pHead, curr);
					curr = curr->next;
				}
			}
			void traverse_print() {
				traverse_print(pHead);
			}
			void traverse_print_backward() {
				traverse_print_backward(pHead);
			}
			// bug fix: iterator tag
			class Iterator {
				public:
					Iterator(node *p) : node_(p) {}
					~Iterator() { delete node_; }
					Iterator& operator=(const Iterator& other) {
						delete node_;
						swap(node_, other.node_);
						return (*this);
					}
					bool operator==(const Iterator& other) {
						return (node_ == other.node_);
					}
					bool operator!=(const Iterator& other) {
         				return(node_ != other.node_);
      				}
					Iterator& operator++() { //prefix
						if(node_ != NULL) {
							node_ = node_->next;
						}
						return (*this);
					}
					Iterator& operator++(int) { //postfix
						Iterator tmp(*this);
						++(*this);
						return tmp;
					}
					T& operator*() {
						return node_->getVal();
					}
					T* operator->() {
						return (&*(LinkedList<T>::Iterator)*this);
					}
				private:
					node* node_;
			};
			Iterator begin() {
				return Iterator(pHead);
			}
			Iterator end() {
				return Iterator(NULL);
			}
		private:
			void __destruct(node *n) {
				if(n == NULL) return;
				__destruct(n->next);
				delete n;
			}
			void traverse_print(node *n) {
				if(n == NULL) return;
				std::cout << n->getVal() << std::endl;
				traverse_print(n->next);
			}
			void traverse_print_backward(node *n) {
				if(n == NULL) return;
				traverse_print_backward(n->next);
				std::cout << n->getVal() << std::endl;
			}
	};
} 

#endif