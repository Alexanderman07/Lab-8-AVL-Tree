#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "Node.h"
using namespace std;

class AVLTree {
  private:
    Node* root;

  public:
    AVLTree();
    void insert(const string &val);
    int balanceFactor(Node* n);
    void print();
    int Height(const string &val);
  private:
    void rotate(Node* n, const string &val);
    Node* rotateLeft(Node *n);
    Node* rotateRight(Node* n);
    Node* getParent(Node *n);
    Node* findUnbalancedNode(Node* n, string val);
    void print(Node *n);
    Node* search(Node* n, const string &val);
    int Height(Node* n);
};

#endif

