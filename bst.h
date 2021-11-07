#ifndef BST_H
#define BST_H
#include "node.h"


class bst{
  public:
 
  bst(); // constructor
  ~bst(); // destructor
  void search(int); // will output key found or key not found
  void insert(int); // will output inserted key, ex inserted 5
  void deleteKey(int); // will remove object with key value and output deleted key
  void min(); // output min is key
  void max(); // output max is key
  void predecessor(int); // output key predecessor is key, no predecessor for key,
  void successor(int); // similar to above
  void inorder(); // output inorder traversal, postorder traversal, or preorder tr
  void preorder(); // followed by : and space separated list of elements starting
  void postorder();

  
  
  private:
 
  void deleteTree(node*); // helper to destructor
  node *root;
  node* search(node*, int);
  void deleteNode(node*); // helper to deleteKey
  node* min(node*);
  node* max(node*);
  node* predecessor(node*);
  node* successor(node*);
  void inorder(node*);
  void preorder(node*);
  void postorder(node*);
};


#endif
