//
// Created by David on 11/27/23.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

void BinaryTree::insert(Node* &aNodePtr, Node* &aNewNodePtr) {
    if (aNodePtr == nullptr) {
        aNodePtr = aNewNodePtr;
    } else if (aNewNodePtr->val < aNodePtr->val) {
        insert(aNodePtr->left, aNewNodePtr);
    } else {
        insert(aNodePtr->right, aNewNodePtr);
    }
}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);
}

BinaryTree::Node::Node(int aVal, BinaryTree::Node *aLeft, BinaryTree::Node *aRight) {
    val = aVal;
    left = aLeft;
    right = aRight;
}


void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) { // check to see if the variable declarations are right
    if (aVal < aNodePtr->val) {
        deleteNode(aVal, aNodePtr->left);
    }
    else if (aVal > aNodePtr->val) {
        deleteNode(aVal, aNodePtr->right);
    }
    else { // if the value is found
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {

    Node* tempNodePtr = nullptr;

    if (aNodePtr == nullptr) {
        cout << "Cannot remove empty Node" << endl;
    }

    else if (aNodePtr->right == nullptr) {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }

    else if (aNodePtr->left == nullptr) {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }

    else {
        tempNodePtr = aNodePtr->right;

        while (tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left= aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right; // not sure about this line

        delete tempNodePtr;
    }
}
void BinaryTree::insertNode(int aVal) {
    Node* newNode  = new Node(aVal);
    insert (root, newNode);
}

    bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;
    while (currentNode) {
        if (currentNode->val == aVal) {
            return true;
        } else if (aVal < currentNode->val) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
        return false;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::displayInOrder(BinaryTree::Node *aNodePtr) {
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}

void BinaryTree::printTree() {
    displayInOrder(root);
    cout << endl;
}
