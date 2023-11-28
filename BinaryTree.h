//
// Created by David on 11/27/23.
//

#ifndef DISCUSSION_9_BINARYTREE_H
#define DISCUSSION_9_BINARYTREE_H

#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node (int aVal, Node* aLeft = nullptr, Node* aRight = nullptr);
    };

    Node* root;
    static void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

    void displayInOrder(Node* aNodePtr);

    void printTree();
};

#endif //DISCUSSION_9_BINARYTREE_H

