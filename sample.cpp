/**
	LinkedList implementation
	Rasul Kerimov (CoderINusE) 
*/
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdlib.h>
#include <exception>
#include <iostream>


namespace alg {


	template <typename T>
	class node {
		T value;
		node* next;
	};

	template <typename T>
	class LinkedList {
		
		private:	
			node<T> *pHead;
			node<T> *pTail;
			int size;
		public:
			LinkedList() : pHead(NULL), pTail(NULL), size(0) {};
			~LinkedList() {
				__destruct(pHead);
			} 

			void insert_to_tail(const T & value) {
				node<T> * temp = new node<T>;
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

		private:
			void __destruct(node<T> *n) {
				if(n == NULL) return;
				__destruct(n->next);
				delete n;
			}
	};
} 


#endif