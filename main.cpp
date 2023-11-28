#include <iostream>
#include "BinaryTree.h"

int main() {
    auto tree = BinaryTree();
    tree.insertNode(5);
    tree.insertNode(10);
    tree.insertNode(1);
    tree.printTree();

    tree.insertNode(0);
    tree.insertNode(3);
    tree.printTree();

    tree.insertNode(9);
    tree.insertNode(11);
    tree.printTree();

    tree.remove(0);
    tree.printTree();

    tree.remove(1);
    tree.printTree();


    return 0;
}
