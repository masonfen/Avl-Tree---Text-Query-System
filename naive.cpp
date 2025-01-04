#include "naive.h"

// BSTNode constructor
BSTNode::BSTNode(const std::string &key)
    : key(key), left(nullptr), right(nullptr) {}

// BST constructor
BST::BST() : root(nullptr) {}

BSTNode *BST::insert(BSTNode *node, const std::string &key)
{
    if (!node)
        return new BSTNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void BST::insert(const std::string &key)
{
    root = insert(root, key);
}

int BST::count_lessOrEqual(BSTNode *node, const std::string &key)
{
    if (!node)
        return 0;

    if (node->key <= key)
        return 1 + count_lessOrEqual(node->left, key) + count_lessOrEqual(node->right, key);
    else
        return count_lessOrEqual(node->left, key);
}

int BST::count_lessThan(BSTNode *node, const std::string &key)
{
    if (!node)
        return 0;

    if (node->key < key)
        return 1 + count_lessThan(node->left, key) + count_lessThan(node->right, key);
    else
        return count_lessThan(node->left, key);
}

int BST::range_query(const std::string &low, const std::string &high)
{
    return count_lessOrEqual(root, high) - count_lessThan(root, low);
}
