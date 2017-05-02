#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
: root(nullptr) {
}

BinaryTree::BinaryTree(const BinaryTree& orig) {
}

BinaryTree::~BinaryTree() {
    remove(root);
}

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

void BinaryTree::insert(int value) {
    node* newNode = new node(value);
    root = sortedInsert(root, newNode);
}

BinaryTree::node* BinaryTree::sortedInsert(node* root, node* newNode) {
    if (root == nullptr) {
        return newNode;
    }
    if (root -> data > newNode -> data) {
        root -> left = sortedInsert(root -> left, newNode);
    } else {
        root -> right = sortedInsert(root -> right, newNode);
    }
    return root;
}

void BinaryTree::travers(node* start) {
    if (start == nullptr)
        return;
    std::cout << start -> data << std::endl;
    travers(start -> left);
    travers(start -> right);
}

void BinaryTree::remove(node* start) {
    if (start == nullptr)
        return;
    remove(start -> left);
    remove(start -> right);
    delete start;
}

void BinaryTree::travers() {
    travers(root);
}

bool BinaryTree::find(int value) {
    node* temp = root;
    while (temp != nullptr) {
        if (temp -> data == value) {
            return true;
        }
        if (value >= temp -> data) {
            temp = temp -> right;
        } else if (value < temp -> data) {
            temp = temp -> left;
        }
    }
    delete temp;
    return false;
}

int BinaryTree::height(node* node) const{
    static int heightLeft = 0;
    static int heightRight = 0;
    if (node -> left != nullptr) {
        ++heightLeft;
        height(node -> left);
    }
    if (node -> right != nullptr) {
        ++heightRight;
        height(node -> right);
    }
    if (heightLeft > heightRight) {
        return heightLeft + 1;
    }
    return heightRight + 1;
}

int BinaryTree::height() const{
    return height(root);
}

//works incorrect
int BinaryTree::size(node* node, int length) const {
    if(node != nullptr) {
        size(node -> left, length + 1);
        size(node -> right, length + 1);
    } else {
        return length;
    }
}

int BinaryTree::size() const{
    return size(root);
}
