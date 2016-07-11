/**
	LinkedList implementation
	Rasul Kerimov (CoderINusE) 
*/
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdlib.h>
#include <exception>
#include <iostream>
#include <iterator>

using namespace std;

namespace alg {
	template <typename T>
	class LinkedList {
		struct node {
			T value;
			node* next;
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

			iterator end() {
				return iterator(pTail);
			}

			void insert_to_tail(const T & value) {
				node * temp = new node;
				temp->value = value;
				temp->next = NULL;

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
				node * temp = new node;
				temp->value = value;
				temp->next = NULL;

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
					
					node * temp = new node; //Create new temporary node
					temp->value = value;
					temp->next = NULL; 	   	//

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
				node *head_s = new node;

				head_s->value = pHead->value;
				head_s->next = NULL;
				 
				while(it != NULL) {
					node *temp = new node;
					temp->value = it->value;
					temp->next = head_s;
					head_s = temp;
					it = it->next;
				}
				__destruct(pHead);
				this->pHead = head_s;
			}


			void traverse_print() {
				traverse_print(pHead);
			}

			void traverse_print_backward() {
				traverse_print_backward(pHead);
			}

		private:
			void __destruct(node *n) {
				if(n == NULL) return;
				__destruct(n->next);
				delete n;
			}
			void traverse_print(node *n) {
				if(n == NULL) return;
				std::cout << n->value << std::endl;
				traverse_print(n->next);
			}
			void traverse_print_backward(node *n) {
				if(n == NULL) return;
				traverse_print_backward(n->next);
				std::cout << n->value << std::endl;
			}
	};
} 


#endif