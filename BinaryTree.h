#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
    struct node;
public:
    BinaryTree();
    BinaryTree(const BinaryTree& orig);
    virtual ~BinaryTree();
    bool isEmpty();
    int size() const;
    int size(node*, int length = 0) const;
    int height(node*) const;
    int height() const;
    void remove(node*);
    void insert(int);
    void travers();
    bool find(int);
private:
    struct node
    {
      int data;
      node *left, *right;
      node(int value) : data (value), left(nullptr), right(nullptr) {};
    };
   node *root;   
   node* sortedInsert(node* root, node* newNode);
   void travers(node* start);
};

#endif

