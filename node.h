#ifndef NODE_H
#define NODE_H


class node{

  friend class bst;
  
  public:
  
  node() { left = 0; right = 0; parent = 0; }
  // ~node() { delete left; left = 0; delete right; right = 0; delete parent; par
  int getData() { return data; }
  
  private:
  
  node *left, *right, *parent;
  int data;
};

#endif
