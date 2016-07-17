#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <stdlib.h>
#include <exception>
#include <iostream>
#include <vector>

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
			BST(std::vector<ValueT>& nums) {
				if(nums.empty()) {
					m_root = NULL;
					return;
				}
				int l = 0, r = nums.size() - 1;
				m_root = vector_to_bst(nums, l, r, 1);
			}
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
						treeNode *y = minimum(z->right);	
						if (y->parent != z) {
							transplant(y, y->right);
							y->right = z->right;
							y->right->parent = y;
						}

						transplant(z,y);
						y->left = z->left;
						y->left->parent = y;
					}

					delete z;
					return true;
				}

				void print_tree() {
					print_helper(m_root, 0);
				}
			private:

				void print_helper(treeNode * n, int indent) {
					if (n == NULL) {
						return;
					}
					print_helper(n->right, indent+1);
					int i;
					for (i = 0;i<indent;i++){
						printf(" ");
					}
					std::cout << "[" << n->key << "," << n->value << "]" << std::endl;
					print_helper(n->left, indent+1);
				}

				void __destruct(treeNode *n) {
					if (n==NULL) return;
					__destruct(n->left);
					__destruct(n->right);
					delete n;
				}

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
				treeNode * minimum(treeNode *x) {
					while (x->left != NULL) {
						x = x->left;
					}

					return x;
				}

				treeNode * vector_to_bst(std::vector<ValueT>& nums, int l, int r, KeyT c) {
					if(l > r) return NULL;
					
					treeNode * ret = new treeNode;
					if(l == r) {	
						ret->value = nums[l];
						ret->key = c;
						return ret;
					}
					int m = (l + r) / 2;
					ret->value = nums[m];
					ret->key = c;
					ret->left = vector_to_bst(nums, l, m - 1, c * 2);
					ret->right = vector_to_bst(nums, m + 1, r, c * 2 + 1);
					return ret;
				}
	};
} 


#endif