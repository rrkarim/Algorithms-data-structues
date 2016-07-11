/**
	Stack implementation
	Iterator pattern
	Rasul Kerimov (CoderINusE) 
*/
#ifndef __STACK_S__
#define __STACK_S__

#include <stdlib.h>
#include <exception>
#include <iostream>

namespace alg {
	template <typename T>
	class Stack {
		class node {
			public:
				node(const T& val_) : next(NULL), value(val_) {}
				T& getVal() {return value;}
				node* next;
			private:
				T value;
		};

		private:	
			node *head;
			int size_;
		public:
			Stack() : head(NULL), size_(0) {};
			~Stack() {
				__destruct(head);
			} 
			Stack& operator=(Stack Stackt) {
				__destruct(head);
				head = NULL;
				swap(head, Stackt.head); //Copy-Swap idiom
				//swap(head, Stackt.tail);
				swap(size_, Stackt.size_); // 
				return *this; 
			}
			void push(const T& value) {
				if(head == NULL) {
					head = new node(value);
				}
				else {
					node *p = head;
					head = new node(value);
					head->next = p;
				}
				size_ += 1;
			}
			T pop() {
				if(head == NULL) {
					throw std::out_of_range("Stack is empty");
				}
				else {
					node* p = head;
					head = head->next;
					T value = p->getVal();
					delete p;
					size_ -= 1;
					return value;
				}
			}
			int size() { return size_; }

			void empty() {
				__destruct(head);
				size_ = 0;
			}
			T& top() {
				return head->getVal();
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
						return (&*(Stack<T>::Iterator)*this);
					}
					

				private:
					node* node_;
			};

			Iterator begin() {
				return Iterator(head);
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
	};
} 


#endif