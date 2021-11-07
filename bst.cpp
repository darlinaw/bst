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
