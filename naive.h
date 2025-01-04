#ifndef NAIVE_BST_H
#define NAIVE_BST_H
#include <string>

struct BSTNode
{
    std::string key;
    BSTNode *left;
    BSTNode *right;

    BSTNode(const std::string &key);
};

class BST
{
public:
    BST();
    void insert(const std::string &key);
    int range_query(const std::string &low, const std::string &high);

private:
    BSTNode *root;

    BSTNode *insert(BSTNode *node, const std::string &key);
    int count_lessOrEqual(BSTNode *node, const std::string &key);
    int count_lessThan(BSTNode *node, const std::string &key);
};

#endif
