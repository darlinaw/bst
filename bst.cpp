#include <iostream>
#include "bst.h"


bst::bst(){
  root = 0;
}



bst::~bst(){
  deleteTree(root);
}




void bst::deleteTree(node *n){
  if(!n) return;
  deleteTree(n−>left);
  deleteTree(n−>right);
  delete n;
}




void bst::search(int key){
  node *n = search(root, key);
  if(!n){
    std::cout << key << " not found." << std::endl;
    return;
  }
  std::cout << key << " found." << std::endl;
}




void bst::insert(int key){
  std::cout << "inserted " << key << "." << std::endl;
  // case for when tree is empty
  node *parent = 0;
  node *temp = root;
  while(temp){
    parent = temp;
    if(key < temp−>data)
      temp = temp−>left;
    else
     temp = temp−>right;
  }
  node *n = new node();
  n−>data = key;
  n−>parent = parent;
  if(!parent){
    root = n;
    return;
  }
  if(n−>data < parent−>data)
    parent−>left = n;
  else
    parent−>right = n;
}




void bst::deleteKey(int key){
  node *n = search(root, key);
  // check to see if key is in tree
  if(n == 0){
    std::cout << "delete " << key << " − not found." << std::endl;
    return;
  }
  deleteNode(n);
  std::cout << "deleted " << key << "." << std::endl;
}




void bst::deleteNode(node *n){
  node *target = 0;
  node *temp = 0;
  if(n−>left == 0 || n−>right == 0)
    target = n;
  else
    target = successor(n);
  if(target−>left != 0)
    temp = target−>left;
  else
    temp = target−>right;
  if(temp != 0)
    temp−>parent = target−>parent;
  if(target−>parent == 0)
    root = temp;
  else{
    if(target == target−>parent−>left)
      target−>parent−>left = temp;
    else
      target−>parent−>right = temp;
  }
  if(target != n){
    n−>data = target−>data;
  }
  delete target; target = 0;
}




void bst::min(){
  node *n = min(root);
  std::cout << "min is " << n−>data << "." << std::endl;
}




void bst::max(){
  node *n = max(root);
  std::cout << "max is " << n−>data << "." << std::endl;
}



void bst::predecessor(int key){
  node *n = search(root, key);
  if(n == 0){
    std::cout << key << " not in tree." << std::endl;
    return;
  }
  
  node *p = predecessor(n);
  if(p == 0){
    std::cout << "no predecessor for " << key << "." << std::endl;
    return;
  }
  std::cout << key << " predecessor is " << p−>data << "." << std::endl;
}




void bst::successor(int key){
  node *n = search(root, key);
  if(!n){
    std::cout << key << " not in tree." << std::endl;
    return;
  }
  node *s = successor(n);
  if(!s){
    std::cout << "no successor for " << key << "." << std::endl;
    return;
  }
  std::cout << key << " successor is " << s−>data << "." << std::endl;
}




void bst::inorder(){
  std::cout << "inorder traversal:" << std::endl;
  inorder(root);
  std::cout << std::endl;
}



void bst::preorder(){
  std::cout << "preorder traversal:" << std::endl;
  preorder(root);
  std::cout << std::endl;
}



void bst::postorder(){
  std::cout << "postorder traversal:" << std::endl;
  postorder(root);
  std::cout << std::endl;
}



// helper and private functions


node* bst::search(node *n, int key){
  if(!n || n−>data == key)
    return n;
  if(key < n−>data)
    return search(n−>left, key);
  return search(n−>right, key);
}



node* bst::min(node *n){
  while(n−>left)
    n = n−>left;
  return n;
}



node* bst::max(node *n){
  while(n−>right)
    n = n−> right;
  return n;
}





node* bst::predecessor(node *n){
  if(n−>left)
    return max(n−>left);
  node *t = n−>parent;
  while(t && n == t−>left){
    n = t;
    t = t−>parent;
  }
  return t;
}



node* bst::successor(node *n){
  if(n−>right)
    return min(n−>right);
  node *t = n−>parent;
  while(t && n == t−>right){
    n = t;
    t = t−>parent;
  }
  return t;
}




void bst::inorder(node *n){
  if(!n) return;
  inorder(n−>left);
  std::cout << n−>data << " ";
  inorder(n−>right);
}




void bst::postorder(node *n){
  if(!n) return;
  postorder(n−>left);
  postorder(n−>right);
  std::cout << n−>data << " ";
}



void bst::preorder(node *n){
  if(!n) return;
  std::cout << n−>data << " ";
  preorder(n−>left);
  preorder(n−>right);
}
