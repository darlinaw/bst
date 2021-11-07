p7: main.o bst.o
  g++ −o p7 −std=c++11 main.o bst.o
main.o: main.cpp bst.h
  g++ −c −std=c++11 main.cpp
bst.o: bst.cpp bst.h node.h
  g++ −c −std=c++11 bst.cpp
clean:
  rm −f p7 *.o *~
