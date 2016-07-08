#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

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

			void insert(const T & value) {
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

			void traverse_print() {
				traverse_print(pHead);
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
	};
} 


#endif