#include <iostream>
#include "tree.h"

int main(){


    BNode<int> t = BNode<int>(nullptr, 10);

    t.setLeft(1);
    t.setRight(2);
    t.getLeft()->setLeft(3);

    std::cout << t;

}