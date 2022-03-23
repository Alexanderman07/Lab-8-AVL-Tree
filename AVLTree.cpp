#include "AVLTree.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

AVLTree::AVLTree()
{
  root = 0;
}



void AVLTree::insert(const string &val) //FIX
{
if(!root) //insert first node case
{
root = new Node(val); //create new node and pass in string val
return;
}
Node *curr = root;
  Node *parent = 0;
  while(curr)
  {
    parent = curr;
    if(val < curr->data)
    {
        curr = curr -> left;
    }
    else if(val > curr -> data)
    {
        curr = curr -> right;
    }
    else 
    {
      curr -> count++;
      return;
    }
  }

  if(val < parent -> data)
  {
    parent -> left = new Node(val);
  }
  else
  {
    parent -> right = new Node(val);
  }

  Node* imbalance = findUnbalancedNode(root, val);
  if(imbalance)
  {
    rotate(imbalance, val);
  }
}

Node* AVLTree::findUnbalancedNode(Node *n, string val)
{
  Node *curr = root;
  Node *imbal = 0;
//int leftHeight = -1;
//int rightHeight = 1;
while(curr)
  {
    int bal = balanceFactor(curr);
    if(bal < -1 || bal > 1)
    {
      imbal = curr;
    }
    if(curr -> data > val)
    {
      curr = curr -> left;
    }
    else 
    {
      curr = curr -> right;
    }
  }
  return imbal;
}

Node* AVLTree::search(Node* n, const string &val) 
{
  Node* curr = n;
  while(curr)
  {
    if(val == curr -> data)
    {
      return curr;
    }
    else if(val < curr -> data)
    {
      curr = curr -> left;
    }
    else
    {
      curr = curr -> right;
    }
  }
  return 0;
}

int AVLTree::Height(const string &val) 
{
  Node *found;
  if((found = search(root, val)))
  {
    return Height(found);
  }
  else
  {
    return -1;
  }
}

int AVLTree::Height(Node *node) 
{
  if(node)
  {
    return max(Height(node -> left), Height(node -> right)) +1;
  }
  else
  {
    return -1;
  }
}

Node* AVLTree::getParent(Node *n)
{
  Node *curr = root;
  Node *parent = 0;
  while(curr != nullptr)
  {
    if(n -> data == curr -> data)
    {
      break;
    }
    parent = curr;
      if(n -> data < curr -> data)
      {
        curr = curr -> left;
      }
      else
      {
        curr = curr -> right;
      }
  }
  return parent;
}

Node* AVLTree::rotateLeft(Node *n)
{
  Node *Right = n -> right;
  Node *RightLeft = n -> right -> left;

  Right -> left = n;
  n -> right = RightLeft;
  return Right;
}

Node* AVLTree::rotateRight(Node *n)
{
  Node *Left = n -> left;
  Node *LeftRight = n -> left -> right;

  Left -> right = n;
  n -> left = LeftRight;
  return Left;
}

void AVLTree::rotate(Node *n, const string &val)
{
  int bal = balanceFactor(n);
  Node *rotated = nullptr;
  Node *imbalanced = getParent(n);

  if(bal > 1 && val < n -> left -> data)
  {
    rotated = rotateRight(n);
  }
  else if(bal >1 && val > n -> left -> data)
  {
    n -> left = rotateLeft(n -> left);
    rotated = rotateRight(n);
  }
  else if(bal < -1 && val < n -> right -> data)
  {
    n -> right = rotateRight(n -> right);
    rotated = rotateLeft(n);
  }
  else if(bal < -1 && val > n -> right -> data)
  {
    rotated = rotateLeft(n);
  }

  if(imbalanced == nullptr)
  {
    root = rotated;
  }
  else if(imbalanced -> left == n)
  {
    imbalanced -> left = rotated;
  }
  else 
  {
    imbalanced -> right = rotated;
  }
}


void AVLTree::print(Node *n)
{
   if(n)
  {
    print(n -> left);
    cout << n -> data << "(" << balanceFactor(n) << "), ";
    print(n -> right);
  }
}

int AVLTree::balanceFactor(Node *node)
{
  return Height(node -> left) - Height(node -> right);
}

void AVLTree::print()
{
  print(root);
  cout << endl;
}



