#include "avl.h"
#include <algorithm>

// AVL node constructor
AVLNode::AVLNode(const std::string &key)
    : key(key), height(1), size(1), left(nullptr), right(nullptr) {}

// tree construct
AVLTree::AVLTree() : root(nullptr) {}

// height size etc..

int AVLTree::height(AVLNode *node)
{
  return node ? node->height : 0;
}

int AVLTree::size(AVLNode *node)
{
  return node ? node->size : 0;
}

void AVLTree::update(AVLNode *node)
{
  if (node)
  {
    node->height = 1 + std::max(height(node->left), height(node->right));
    node->size = 1 + size(node->left) + size(node->right);
  }
}

// rotations

AVLNode *AVLTree::rotate_left(AVLNode *y)
{ // rotate left
  AVLNode *x = y->right;
  AVLNode *T2 = x->left;

  x->left = y;
  y->right = T2;

  update(y);
  update(x);

  return x;
}

AVLNode *AVLTree::rotate_right(AVLNode *x)
{ // rotate right
  AVLNode *y = x->left;
  AVLNode *T2 = y->right;

  y->right = x;
  x->left = T2;

  update(x);
  update(y);

  return y;
}

AVLNode *AVLTree::balance(AVLNode *node)
{ // balance
  update(node);

  int bf = height(node->left) - height(node->right);

  if (bf > 1)
  {
    if (height(node->left->right) > height(node->left->left))
      node->left = rotate_left(node->left);
    return rotate_right(node);
  }
  else if (bf < -1)
  {
    if (height(node->right->left) > height(node->right->right))
      node->right = rotate_right(node->right);
    return rotate_left(node);
  }
  return node;
}

AVLNode *AVLTree::insert(AVLNode *node, const std::string &key)
{ // insert
  if (!node)
    return new AVLNode(key);

  if (key < node->key)
  {
    node->left = insert(node->left, key);
  }
  else if (key > node->key)
  {
    node->right = insert(node->right, key);
  }
  else
  {
    return node;
  }

  return balance(node);
}

void AVLTree::insert(const std::string &key)
{
  root = insert(root, key);
}

int AVLTree::count_lessOrEqual(AVLNode *node, const std::string &key)
{ // count_lessOrEqual
  if (!node)
    return 0;

  if (node->key <= key)
  {
    return size(node->left) + 1 + count_lessOrEqual(node->right, key);
  }
  else
  {
    return count_lessOrEqual(node->left, key);
  }
}

int AVLTree::count_lessThan(AVLNode *node, const std::string &key)
{
  if (!node)
    return 0;

  if (node->key < key)
  {
    return size(node->left) + 1 + count_lessThan(node->right, key);
  }
  else
  {
    return count_lessThan(node->left, key);
  }
}

int AVLTree::range_query(const std::string &low, const std::string &high)
{ // range_query
  return count_lessOrEqual(root, high) - count_lessThan(root, low);
}
