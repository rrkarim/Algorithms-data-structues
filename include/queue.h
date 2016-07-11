/**
	LinkedList implementation
	Rasul Kerimov (CoderINusE) 
*/
#ifndef __QUEUE_S__
#define __QUEUE_S__

#include <stdlib.h>
#include <exception>
#include <iostream>

namespace alg {
	template <typename T>
	class Queue {
		class node {
			public:
				node(const T &val_) : next(NULL), value(val_) {}
				T& getVal() {return value;}
				node* next;
			private:
				T value;
		};

		private:	
			node *head, *tail;
			int size;
		public:
			Queue() : head(NULL), tail(NULL), size(0) {};
			~Queue() {
				__destruct(head);
			} 
			Queue& operator=(Queue queuet) {
				__destruct(head);
				head = tail = NULL;
				swap(head, queuet.head); //Copy-Swap idiom
				swap(head, queuet.tail);
				swap(size, queuet.size); // 
				return *this; 
			}
			void pushBack(const T &value) {
				if(head == NULL) {
					head = new node(value);
					tail = head;
				}
				else {
					node *p = new node(value);
					tail->next = p;
					tail = p;
				}
			}
			T popFront() {
				if(head == NULL) {
					throw std::out_of_range("Queue is empty");
				}
				else {
					T value = head->getVal();
					head = head->next;
					return value;
				}
			}

		private:
			void __destruct(node *n) {
				if(n == NULL) return;
				__destruct(n->next);
				delete n;
			}
	};
} 


#endif