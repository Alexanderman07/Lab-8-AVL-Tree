#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node {
  public: 
    string data;
    int count;
    Node* left;
    Node* right;
  public:
    Node(string);
};

#endif
