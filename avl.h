#ifndef AVL_H
#define AVL_H
#include <string>

struct AVLNode
{
  std::string key; // set key to str type
  int height;
  int size; // subtree size
  AVLNode *left;
  AVLNode *right;

  AVLNode(const std::string &key);
};

class AVLTree
{

public:
  AVLTree();
  void insert(const std::string &key);
  int range_query(const std::string &low, const std::string &high);

private:
  AVLNode *root;

  int height(AVLNode *node);
  int size(AVLNode *node);
  void update(AVLNode *node);

  AVLNode *rotate_left(AVLNode *node);
  AVLNode *rotate_right(AVLNode *node);
  AVLNode *balance(AVLNode *node);
  AVLNode *insert(AVLNode *node, const std::string &key);

  int count_lessOrEqual(AVLNode *node, const std::string &key);
  int count_lessThan(AVLNode *node, const std::string &key);
};

#endif