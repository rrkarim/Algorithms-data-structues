#ifndef _BINARY_SEARCH_TREE__
#define _BINARY_SEARCH_TREE__

#include <stdlib.h>
#include <exception>
#include <iostream>

namespace alg {
	template <typename KeyT, typename ValueT>
	class BST {

		struct treeNode {
			KeyT key;
			ValueT value;
			treeNode *parent;
			treeNode *left;
			treeNode *right;
		};
		class BSTException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "key does not exist";
				}
		} excp_key;

		private:
			treeNode * m_root;
			BST(const BST&);
			BST& operator=(const BST&);
		public:
			BST() : m_root(NULL) {};

			~BST() {
				__destruct(m_root);
			}

			treeNode *find(const KeyT & key) {
				treeNode  *n = m_root;
				while(n != NULL && key != n->key) {
					if(key < n->key) {
						n = n->left;
					} else {
						n = n->right;
					}
				}

				return n;
			}
			void insert(const KeyT & key, const ValueT & value) {
					treeNode *z= new treeNode;
					z->key = key;
					z->value = value;
					z->left = z->right = z->parent = NULL;

					treeNode * n = m_root;
					treeNode * y = NULL;
					while(n!=NULL) {
						y = n;	
						if(key < n->key) {
							n = n->left;			
						} else {
							n = n->right;
						}
					}

					z->parent = y;
					if (y==NULL) {
						m_root = z;
					} else if (key < y->key) {
						y->left = z;
					} else {
						y->right = z;
					}
				}

				/**
				 * delete a key from the binary search tree.
				 */
				bool deleteKey(const KeyT & key) {
					
					throw BSTException();

					treeNode *z = find(key);
					if (z == NULL) {	
						return false;
					}

					if (z->left == NULL) {
						transplant(z, z->right);
					} else if (z->right == NULL) {
						transplant(z, z->left);
					} else {
						// find the minimum element of the right subtree
						treeNode *y = minimum(z->right);	
						if (y->parent != z) {
							// replace y with right-child
							transplant(y, y->right);
							// replace right-child of y with the right-child of z
							y->right = z->right;
							// make y the parent of the right-child
							y->right->parent = y;
						}

						// replace z with y
						transplant(z,y);
						y->left = z->left;
						y->left->parent = y;
					}

					delete z;
					return true;
				}

				void print_tree(treeNode * n, int indent) {
					if (n == NULL) {
						return;
					}
					print_tree(n->right, indent+1);
					int i;
					for (i=0;i<indent;i++){
						printf(" ");
					}
					std::cout << "[" << n->key << "," << n->value << "]" << std::endl;
					print_tree(n->left, indent+1);
				}

				void print_helper() {
					print_tree(m_root, 0);
				}
			private:
				void __destruct(treeNode *n) {
					if (n==NULL) return;
					__destruct(n->left);
					__destruct(n->right);
					delete n;
				}

				/**
				 * replace node u with v.
				 */
				void transplant(treeNode *u, treeNode *v) {
					if (u->parent == NULL) {
						m_root = v;
					} else if (u == u->parent->left) {
						u->parent->left = v;
					} else {
						u->parent->right = v;
					}

					if (v!=NULL) {
						v->parent = u->parent;
					}
				}

				/**
				 * find the minimum element of the subtree
				 */
				treeNode * minimum(treeNode *x) {
					while (x->left != NULL) {
						x = x->left;
					}

					return x;
				}
	};
} 


#endif