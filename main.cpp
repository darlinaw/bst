#include <iostream>
#include <sstream>
#include <string>
#include "bst.h"


using namespace std;


int main(){
  bst tree;
  string line;
  while(getline(cin, line)){
    if(line.substr(0, 1) != "#"){
      stringstream ss (line);
      string first;
      int key;
      ss >> first;
      ss >> key;
    
      if(first == "min")
        tree.min();

      else if(first == "max")
        tree.max();

      else if(first == "inorder")
        tree.inorder();
      
      else if(first == "preorder")
        tree.preorder();

      else if (first == "postorder")
        tree.postorder();

      else if(first == "search")
        tree.search(key);

      else if(first == "insert")
        tree.insert(key);

      else if(first == "delete")
        tree.deleteKey(key);

      else if(first == "predecessor")
        tree.predecessor(key);

      else if(first == "successor")
        tree.successor(key);
    }
  }
  return 0;
}
