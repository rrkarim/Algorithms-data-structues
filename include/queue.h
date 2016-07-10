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
		struct node
		{
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
			node *head;
			int size;
		public:
			Queue() : head(NULL), size(0) {};
			~Queue() {
				__destruct(head);
			} 

			Queue& operator=(Queue queuet) {
				__destruct(head);
				head = NULL;

				//Copy-Swap idiom
				swap(head, queuet.head);
				swap(size, queuet.size);
				return *this;
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