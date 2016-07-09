#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdlib.h>
#include <exception>
#include <iostream>

namespace alg {
	template <typename T>
	class LinkedList {
		struct node
		{
			T value;
			node* next;
		};
		class LLException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "";
				}
		} excp_key;

		private:
			node *pHead;
			node *pTail;
		public:
			LinkedList() : pHead(NULL), pTail(NULL) {};
			~LinkedList() {
				__destruct(pHead);
			} 

			LinkedList& operator=(LinkedList *linkn) {
				std::cout << "dsdss" << std::endl;
				__destruct(pHead);
				std::cout << linkn->pHead->value << std::endl;
			}

			void insert_to_tail(const T & value) {
				node * temp = new node;
				temp->value = value;
				temp->next = NULL;

				if(pHead == NULL) {
					pHead = pTail = temp;
				}
				else {
					pTail->next = temp;
					pTail = pTail->next; 
				}
			}

			void insert_to_head(const T & value) {
				node * temp = new node;
				temp->value = value;
				temp->next = NULL;

				if(pHead == NULL) {
					pHead = pTail = temp;
				} 
				else {
					temp->next = pHead;
					pHead = temp;
				}
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